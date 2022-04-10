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
#include "FileBase.h"
#include "FileServer.h"
#include "../Application/ApplicationBase.h"
#include "../Data/DivGraph.h"
#include "../SoundServer/SoundMem.h"
#include "../Resource/ResourceServer.h"
#include "../Model/ModelServer.h"

// jsonファイルの読み取りで使用する標準キー
namespace {
  // jsonファイルの読み取りで使用するキー
  constexpr auto DataType = "data";       //!< データ判別用
  constexpr auto TypeGraph = 1;     //!< 画像情報
  constexpr auto TypeModel = 2;     //!< モデルデータ

  constexpr auto Values = "values";

  constexpr auto Extension = "expention"; //!< ファイル拡張子
  constexpr auto Directory = "directory"; //!< ディレクトリパス取得用
  constexpr auto File = "file";           //!< ファイル情報
  constexpr auto ModelKey = "key";        //!< サーバ登録時に紐づけるキー
  constexpr auto FileName = "filename";  //!< モデルファイル名
  // 画像読み取り用
  constexpr auto XNum = "xnum";     //!< x軸の分割数
  constexpr auto YNum = "ynum";     //!< y軸の分割数
  constexpr auto AllNum = "allnum"; //!< 画像の総分割数
  constexpr auto XSize = "xsize";   //!< 画像1枚あたりの横サイズ
  constexpr auto YSize = "ysize";   //!< 画像1枚あたりの縦サイズ
  constexpr auto GraphKey = "key";  //!< 

  constexpr auto DataTypeModel = "model"; //!< モデルデータ
  constexpr auto TextureData = "texture"; //!< 画像データ

  constexpr auto Param = "param";         //!< パラメータ
  constexpr auto Key = "key";             //!< 連想配列に登録するキー


  constexpr auto MAP = "map";             // マップ
  constexpr auto FORMAT = "format";       // フォーマット
  constexpr auto NUMS = "nums";           // 要素数取得キー
  constexpr auto KEY = "key";             // 連想配列登録用キー
  constexpr auto PATH = "path";           // ファイル名
} // namespace

namespace AppFrame {
  namespace FileServer {

    LoadJson::LoadJson(Application::ApplicationBase& app) : _app(app) {
    }

    bool LoadJson::LoadJsonFile(std::string_view path) {
      using json = nlohmann::json;
      std::ifstream read(path.data());
      // 読み取ったデータをjsonオブジェクトに変換
      json data = json::parse(read);
      // jsonファイルを閉じる
      read.close();
      // データタイプの取得
      auto type = data[DataType].get<int>();
      // 対応データが格納されたjsonオブジェクト
      auto values = data[Values];
      for (auto value : values) {
        // データタイプに対応した処理を呼び出す
        switch (type) {
        case TypeGraph: // 画像情報
          // 画像情報の読み取りを行う
          LoadDivGraphData(std::move(value));
          break;
        case TypeModel: // モデル情報
          // モデル情報の読み取りを行う
          LoadModelData(std::move(value));
          break;
        default:
          return false; // データタイプが不明
        }
      }
      return true; // 終了
    }

    bool LoadJson::LoadModelData(const nlohmann::json json) {
      // jsonファイルから各種データを取り出す
      auto directory = json[Directory].get<std::string>(); // ディレクトリパス
      // ディレクトリは有効か
      if (!std::filesystem::is_directory(directory)) {
        auto message = directory + ":ディレクトリパスが不正です\n";
        OutputDebugString(message.data()); // ログに出力する
        return false; // ディレクトリが有効ではない
      }
      auto extension = json[Extension].get<std::string>(); // ファイル拡張子
      auto files = json[File]; // ファイル名と登録用キーが格納されたコンテナ
      // 読み取ったデータをサーバに登録する
      for (auto data : files) {
        auto key = data[ModelKey].get<std::string>();      // 登録に使用する文字列
        auto fileName = data[FileName].get<std::string>(); // ファイル名
        auto filePath = directory + fileName + extension;  // ファイルパスの作成
        // MV1モデル情報を読み込む
        _app.GetModelServer().AddMV1Model(key, filePath);
      }
      return true;
    }

    bool LoadJson::LoadDivGraphData(const nlohmann::json json) {
      // jsonファイルから各種データを取り出す
      auto directory = json[Directory].get<std::string>(); // ディレクトリパス
      // ディレクトリは有効か
      if (!std::filesystem::is_directory(directory)) {
        auto message = directory + ":ディレクトリパスが不正です\n";
        OutputDebugString(message.data()); // ログに出力する
        return false; // ディレクトリが有効ではない
      }
      auto extension = json[Extension].get<std::string>(); // ファイル拡張子
      auto files = json[File]; // ファイル名と登録用キーが格納されたコンテナ
      for (auto data : files) {
        // サーバ登録時に紐づける文字列
        auto key = data[GraphKey].get<std::string>();
        // ファイルパス
        auto filePath = directory + data[FileName].get<std::string>() + extension;
        // 各種パラメータ
        auto xNum = data[XNum].get<int>();
        auto yNum = data[YNum].get<int>();
        auto allNum = data[AllNum].get<int>();
        auto xSize = data[XSize].get<int>();
        auto ySize = data[YSize].get<int>();
        // 取得した値を基に画像情報を作成
        Data::DivGraph divGraph(filePath, xNum, yNum, allNum, xSize, ySize);
#ifndef _DEBUG
        // 対象画像ファイルを読み込む
        _app.GetResourceServer().LoadDivGraph(key, divGraph);
#else
        // 登録に失敗した場合はキーとパスをログに出力する
        if (!_app.GetResourceServer().LoadDivGraph(key, divGraph)) {
          auto message = key + ":パスが有効ではありません\n";
          OutputDebugString(message.data());
        }
#endif
      }
      return true; // 処理終了
    }

    std::filesystem::path LoadJson::ToJsonName(std::string directory, std::string fileName) const {
      // jsonファイルのパスに変換する
      return std::filesystem::path(directory + fileName + JSON);
    }

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
      return std::logic_error("LoadJson:" + message + "\n");
    }
#endif

    bool LoadJson::IsJson(const std::filesystem::path path) {
      auto format = path.extension().string(); // ファイル拡張子
      // ファイル拡張子はjsonか
      if (format != ".json") {
#ifdef _DEBUG
        auto message = path.string() + ":対象はjsonファイルではありません\n";
        OutputDebugString(message.data());
#endif
        return false; // jsonファイルではない
      }
      return true; // jsonファイル
    }
  } // namespace FileServer
} // namespace AppFrame