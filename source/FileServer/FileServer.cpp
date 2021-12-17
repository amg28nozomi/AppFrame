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
  constexpr auto LOG_TEXT = "FileWorkerLog.txt"; // ログ用ファイル名
}

namespace AppFrame {
  namespace FileServer {

    FileServer::FileServer() : _debugLog(LOG_TEXT) {
      _debug = true;
      _fileMap.clear();
#ifdef _DEBUG
      _debugLog = FileOutput(LOG_TEXT);
#endif
      Release();
    }

    FileServer::~FileServer() {
      Release();
    }

    bool FileServer::Init() {
      Release();
      return true;
    }

    void FileServer::Release() {
      _fileMap.clear(); // 解放
    }

    bool FileServer::LoadFileMap(std::filesystem::path jsonPath) {
#ifdef _DEBUG
      auto stringPath = jsonPath.string();
#endif
      // 対象ファイルは存在しているか
      if (!std::filesystem::exists(jsonPath)) {
#ifdef _DEBUG
        const std::string message(stringPath + ":パスが不正です");
        DebugStringLog(message);
#endif
        return false; // パスが不正
      }
      // 対象がjsonファイルかの判定
      if (!LoadJson::IsJson(jsonPath)) {
#ifdef _DEBUG
        const std::string message(stringPath + ":対象はjsonファイルではありません");
        DebugStringLog(message);
#endif
        return false; // ファイル形式が異なる
      }
      auto fileMap = LoadJson::LoadJsonFile(jsonPath); // ファイル情報
      if (fileMap.empty()) {
        return false; // ファイル情報が空
      }
      auto counter = 0; // 登録失敗回数
      // 取得したファイル情報の登録
      for (auto [key, value] : fileMap) {
        if (_fileMap.contains(key)) {
#ifdef _DEBUG
          const std::string message = "キー:" + key + "は既に登録されています";
          DebugStringLog(message);
#endif
          ++counter;
          continue;
        }
        _fileMap.emplace(key, value);
      }
#ifdef _DEBUG
      // 途中、登録処理に失敗したか？
      if (counter) {
        const std::string message(counter + "回処理に失敗しました");
        DebugStringLog(message);
      }
#endif
      return true; // 登録終了
    }

    bool FileServer::SetLogTextFlag(bool flag, std::filesystem::path logPath) {
      return true;
    }

    bool FileServer::LoadFileMap(FileBaseMap& fileMap) {
      return true;
    }

    bool FileServer::FileCheck(const std::filesystem::path path) {
      return true;
    }

#ifdef _DEBUG
    void FileServer::DebugStringLog(const std::string text) {
      // ログへの出力
      std::string message("FileServer:" + text + "\n");
      OutputDebugString(message.data());
      if (!_debug) {
        return;
      }
      // テキストファイルへの出力
      _debugLog.OutputText(text);
    }
#endif
  } // namespace FileServer
} // namespace AppFrame