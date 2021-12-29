#include "ServerBase.h"
#include <filesystem>
#ifdef _DEBUG
#include <Windows.h>
#endif
#include "../FileServer/FileBase.h"

namespace AppFrame {
  namespace Data {

    template <typename T, typename I>
    ServerBase<T, I>::ServerBase() {
      _registry.clear();
#ifdef _DEBUG
      _name = "ServerBase";
#endif
    }

    template <typename T, typename I>
    bool ServerBase<T, I>::Register(std::string_view key, const I value) {
    }

    template <typename T, typename I>
    bool ServerBase<T, I>::LoadFiles(std::vector<FileServer::FileBase> files) {
      // ファイルは存在するか？
      if (files.empty()) {
        return false; // データが空
      }
      for (auto file : files) {
        auto [key, path] = file.GetFileData();
        // キーは既に登録されているか
        if (_registry.contains(key.data())) {
          continue; // 登録済み
        }
        // パスは有効か
        if (!std::filesystem::exists(path)) {
          continue; // 有効ではない
        }
#ifndef _DEBUG
        Register(key, path); // 登録処理に移行
#else
        try {
          Register(key, path);
        } catch (std::logic_error error) {
          // 例外がある場合は出力
          DebugString(error.what());
        }
#endif
      }
      return true; // 処理終了
    }

    template <typename T, typename I>
    bool ServerBase<T, I>::KeySearch(std::string_view key) {
      return true;
    }

#ifdef _DEBUG
    template <typename T, typename I>
    std::logic_error ServerBase<T, I>::LogicError(std::string_view message) const {
      // 指定した形式に修正
      std::string m = _name + ":" + message + "\n";
      return std::logic_error(m);
    }

    template <typename T, typename I>
    void ServerBase<T, I>::DebugString(std::string_view message) {
      OutputDebugString(message.data());
    }
#endif
  } // namespace Data
} // namespace AppFrame