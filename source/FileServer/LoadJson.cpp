/*****************************************************************//**
 * @file   LoadJson.cpp
 * @brief  Jsonファイルの読み取り処理クラスの定義
 *
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "LoadJson.h"
#include <Windows.h>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <nlohmann/json.hpp>
#include "../Data/DivGraph.h"
#include "FileBase.h"
#include "FileServer.h"
#include "../SoundServer/SoundMem.h"

// jsonファイルの読み取りで使用する標準キー
namespace {
  constexpr auto Directory = "directory"; //!< ディレクトリ
  constexpr auto Param = "param";         //!< パラメータ
  constexpr auto Extension = "extension"; //!< ファイル拡張子
  constexpr auto Key = "key";             //!< 連想配列に登録するキー
  constexpr auto FileName = "filename";   //!< ファイル名


  constexpr auto MAP = "map";             // マップ
  constexpr auto DIRECTORY = "directory"; // ディレクトリパス
  constexpr auto FORMAT = "format";       // フォーマット
  constexpr auto NUMS = "nums";           // 要素数取得キー
  constexpr auto KEY = "key";             // 連想配列登録用キー
  constexpr auto PATH = "path";           // ファイル名
}

namespace AppFrame {
  namespace FileServer {

    std::unordered_map<std::string, FileBase> LoadJson::LoadJsonFile(std::filesystem::path jsonPath) {
      // ファイルの展開
      std::ifstream jsonFile(jsonPath);
      // 読み取り失敗
      if (!jsonFile) {
#ifdef _DEBUG
        throw std::logic_error(jsonPath.string() + " : ファイルの読み取りに失敗しました\n");
#endif
        return FileBaseMap(); // 空データを返す
      }
      // 
      namespace json = nlohmann;
      json::json j = json::json::parse(jsonFile);
      jsonFile.close();

      auto map = j[MAP]; // データ
      // キーとパスのサイズは等しいか
      if (map[KEY].size() != map[PATH].size()) {
#ifdef _DEBUG
        auto error = Differebce(static_cast<int>(map[KEY].size()), map[PATH]);
        throw std::logic_error("キーとパスのサイズが一致していません。jsonファイルを確認して下さい");
#endif
      }
      const std::string directry = map[DIRECTORY]; // ディレクトリパス
      const std::string format = map[FORMAT];      // フォーマット
      std::queue<std::string_view> keys;           // 登録用キー
      // キーのコピー
      for (auto key : map[KEY]) {
        keys.push(key);
      }
      FileBaseMap fileMap; // ファイルデータ
      // 連想配列への登録
      for (auto path : map[PATH]) {
        std::string fileName = path; // ファイル名
        // ファイルパス
        std::string filePath = directry + fileName + format;
        // パスは存在するか
        if (std::filesystem::exists(filePath)) {
#ifdef _DEBUG
          OutputDebugString(filePath.c_str());
          OutputDebugString(" : 対象ファイルは存在していません。\n");
#endif
          keys.pop(); // 先頭のキーを破棄
          continue;
        }

      }
      return fileMap;
    }

//    bool LoadJson::LoadDivGraphData(nlohmann::json json) {
//      // 画像ファイルが存在するディレクトリパス
//      auto directory = json["directory"].get<std::string>();
//      for (auto data : json["file"]["data"]) {
//#ifndef _DEBUG
//#else
//#endif
//        auto key = data["key"].get<std::string>();
//        auto divGraph =  AddDivGraph(data, directory);
//        // コンテナに登録する
//
//      }
//      return true;
//    }
//
//    Data::DivGraph LoadJson::AddDivGraph(nlohmann::json param, std::string_view directory) {
//      // 各種パラメータの取得
//      auto filePath = directory.data() + param["filename"].get<std::string>() + ".png";
//      auto xNum = param["xnum"].get<int>();
//      auto yNum = param["ynum"].get<int>();
//      auto allNum = param["allnum"].get<int>();
//      auto xSize = param["xsize"].get<int>();
//      auto ySize = param["ysize"].get<int>();
//      // 生成した画像情報を返す
//      return Data::DivGraph(filePath, xNum, yNum, allNum, xSize, ySize);
//    }
//
//    Sound::SoundMem LoadJson::AddSoundMem(nlohmann::json param, std::string_view directory, std::string_view extension) {
//      auto filePath = directory.data() + param["filename"].get<std::string>() + extension.data();
//      auto playType = param["playtype"].get<int>();
//      return Sound::SoundMem(filePath, playType);
//    }
//
//    bool LoadJson::TypeChack(nlohmann::json json) {
//      switch (json.get<int>()) {
//      default:
//        return false;
//      }
//      return true;
//    }


#ifdef _DEBUG
    std::string_view LoadJson::Differebce(const int key, const int path) noexcept {
      std::string message;
      // 差分の算出
      auto value = key - path;
      if (value < 0) {
        value *= -1;
        message = "パスのサイズがキーよりも" + std::to_string(value) + "多いです\n";
      }
      else {
        message = "キーのサイズがパスよりも" + std::to_string(value) + "多いです\n";
      }
      return std::string_view(message);
    }

    std::logic_error LoadJson::GetLogicError(std::string message) {
      return std::logic_error("LoadJson::" + message + "/n");
    }
#endif

    bool LoadJson::IsJson(const std::filesystem::path path) {
      auto format = path.stem().string(); // ファイル拡張子
      if (format != "json") {
#ifdef _DEBUG
        throw std::logic_error(format + ":対象はjsonファイルではありません\n");
#endif
        return false; // jsonファイルではない
      }
      return true; // jsonファイル
    }
  } // namespace FileServer
} // namespace AppFrame