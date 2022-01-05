/*****************************************************************//**
 * @file   FileServer.cpp
 * @brief  ファイルデータを管理するサーバクラスの定義
 *
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "FileServer.h"
#include <stdexcept>
#include <Windows.h>
#include "FileBase.h"
#include "LoadJson.h"

namespace {
  constexpr auto ServerName = "FileServer";
  constexpr auto LogText = "FileWorkerLog.txt"; // ログ用ファイル名
}

namespace AppFrame {
  namespace FileServer {

#ifndef _DEBUG
    FileServer::FileServer() : ServerBase() {
    }
#else
    FileServer::FileServer(std::filesystem::path filePath) : ServerBase(), _fileLog(filePath) {
      _name = ServerName;
    }
#endif

    FileServer::~FileServer() {
      Init();
    }

    bool FileServer::Init() {
      return ServerBase::Init();
    }

    bool FileServer::Release() {
      // 登録されているファイル情報を一括削除する
      _registry.clear();
      return true;
    }
    // 追加

    bool FileServer::Register(std::string_view key, const std::filesystem::path path) {
#ifndef _DEBUG
      // 対象は登録可能か？
      if (!IsTarget({key, path})) {
        return false;
      }
#else
      try {
        IsTarget((key, path));
      } catch (std::logic_error error) {
        DebugString(error.what());
        return false; // 登録失敗
      }
#endif
      _registry.emplace(key, path); // レジストリに登録
      return true;
    }

    bool FileServer::LoadFiles(std::filesystem::path jsonPath) {
#ifndef _DEBUG
      // パスは有効か
      if (!IsTarget(jsonPath, ".json")) {
        return false; // 読み取り対象ではない
      }
#else
      try {
        IsTarget(jsonPath, ".json");
      } catch (std::logic_error error) {
        DebugString(error.what());
        return false;
      }
#endif
      LoadJson::LoadJsonFile(jsonPath);
      
      return true;
    }



//    FileServer::FileServer() : _debugLog(LogText) {
//      _debug = true;
//      _fileMap.clear();
//#ifdef _DEBUG
//      _debugLog = FileOutput(LogText);
//#endif
//      Release();
//    }
//
//    FileServer::~FileServer() {
//      Release();
//    }
//
//    bool FileServer::Init() {
//      Release();
//      return true;
//    }
//
//    void FileServer::Release() {
//      _fileMap.clear(); // 解放
//    }
//
//    bool FileServer::LoadFileMap(std::filesystem::path jsonPath) {
//#ifdef _DEBUG
//      auto stringPath = jsonPath.string();
//#endif
//      // 対象ファイルは存在しているか
//      if (!std::filesystem::exists(jsonPath)) {
//#ifdef _DEBUG
//        const std::string message(stringPath + ":パスが不正です");
//        DebugStringLog(message);
//#endif
//        return false; // パスが不正
//      }
//      // 対象がjsonファイルかの判定
//      if (!LoadJson::IsJson(jsonPath)) {
//#ifdef _DEBUG
//        const std::string message(stringPath + ":対象はjsonファイルではありません");
//        DebugStringLog(message);
//#endif
//        return false; // ファイル形式が異なる
//      }
//      auto fileMap = LoadJson::LoadJsonFile(jsonPath); // ファイル情報
//      if (fileMap.empty()) {
//        return false; // ファイル情報が空
//      }
//      auto counter = 0; // 登録失敗回数
//      // 取得したファイル情報の登録
//      for (auto [key, value] : fileMap) {
//        if (_fileMap.contains(key)) {
//#ifdef _DEBUG
//          const std::string message = "キー:" + key + "は既に登録されています";
//          DebugStringLog(message);
//#endif
//          ++counter;
//          continue;
//        }
//        _fileMap.emplace(key, value);
//      }
//#ifdef _DEBUG
//      // 途中、登録処理に失敗したか？
//      if (counter) {
//        const std::string message(counter + "回処理に失敗しました");
//        DebugStringLog(message);
//      }
//#endif
//      return true; // 登録終了
//    }
//
//    bool FileServer::SetLogTextFlag(bool flag, std::filesystem::path logPath) {
//      return true;
//    }
//
//    bool FileServer::LoadFileMap(FileBaseMap& fileMap) {
//      return true;
//    }
//
//    bool FileServer::FileCheck(const std::filesystem::path path) {
//      return true;
//    }
//
//#ifdef _DEBUG
//    void FileServer::DebugStringLog(const std::string text) {
//      // ログへの出力
//      std::string message("FileServer:" + text + "\n");
//      OutputDebugString(message.data());
//      if (!_debug) {
//        return;
//      }
//      // テキストファイルへの出力
//      _debugLog.OutputText(text);
//    }
//#endif
  } // namespace FileServer
} // namespace AppFrame