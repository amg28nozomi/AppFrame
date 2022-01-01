#include "ServerBase.h"
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
    bool ServerBase<T, I>::Init() {
      _registry.clear();
      return true;
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

    template <typename T, typename I>
    bool ServerBase<T, I>::IsTarget(FileServer::FileBase file, std::string_view extension) const {
      // キーに使用する文字列とファイルパス
      auto [key, path] = file.GetFileData();
      // 拡張子に指定はあるか？
      if (!extension.empty()) {
        // 拡張子は対応しているか？
        if (path.stem() != extension.data()) {
#ifdef _DEBUG
          throw LogicError(file.GetFileName() + ":拡張子が異なります");
#endif
          return false; // ファイル形式が異なる
        }
      }
      // ファイルは存在するか
      if (!std::filesystem::exists(path)) {
#ifdef _DEBUG
        throw LogicError(file.GetFileName() + ":パスが有効ではありません");
#endif
        return false; // パスが有効ではない
      }
      // キーは使用されていないか
      if (_registry.contains(key.data())) {
#ifdef _DEBUG
        throw LogicError(file.GetFileName() + ":キーが重複しています");
#endif
        return false; // キーが重複している
      }
      return true;  // ターゲットである
    }

    template <typename T, typename I>
    bool ServerBase<T, I>::Exist(std::filesystem::path filePath) const {
      // ファイルは存在するか
      auto flag = std::filesystem::exists(filePath);
#ifdef _DEBUG
      if (!flag) {
        // ファイルが存在しない場合
        throw LogicError(filePath.string() + ":ファイルが存在しません");
      }
#endif
      return flag;
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