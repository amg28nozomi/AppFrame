/*****************************************************************//**
 * @file   ResourceServer.cpp
 * @brief  2D素材を管理するリソースサーバクラスの定義
 * 
 * @author 鈴木希海
 * @date   February 2022
 *********************************************************************/
#include "ResourceServer.h"
#include <DxLib.h>
#include "../Math/Arithmetic.h"

namespace AppFrame{
  namespace Resource {

    ResourceServer::ResourceServer(std::string_view path) : Server::ServerTemplateUnordered<std::string, std::pair<Data::DivGraph, std::vector<int>>>() {
#ifdef _DEBUG
      SetServerName("ResourceServer"); // サーバ名の設定
#endif
      SetDirectryPath(path.data());    // ディレクトリパスの設定
    }

    bool ResourceServer::Release() {
      // 登録されている画像情報の解放
      for (auto&& [key , graphs] : _registry) {
        auto&& [divGraph, handles] = graphs;
        // グラフィックハンドルの削除
        DeleteGraphs(std::move(handles));
        handles.clear();
      }
      _registry.clear();
      return true;
    }

    bool ResourceServer::LoadDivGraph(std::string_view key, Data::DivGraph divGraph) {
      // キーは登録されているか
      if (_registry.contains(key.data())) {
        // キーが重複している場合は既存データを削除
        auto&& [graph, handles] = _registry.at(key.data());
        // グラフィックハンドルの削除
        DeleteGraphs(std::move(handles));
      }
      namespace fs = std::filesystem;
      // ファイル名の取得
      auto filePath = FilePath(divGraph.GetFilePath());
      // 対象ファイルは存在しているか
      if (!fs::exists(filePath)) {
        return false; // パスが有効ではない
      }
      // 画像情報の取得
      auto [xNum, yNum, allNum] = divGraph.GetNum();
      auto [xSize, ySize] = divGraph.GetSize();
      // グラフィックハンドルを格納するコンテナを用意
      std::vector<int> handles;
      handles.resize(allNum);
      // グラフィックハンドルの読み取り
      if (DxLib::LoadDivGraph(filePath.string().data(), xNum, yNum, allNum, xSize, ySize, handles.data()) == -1) {
        return false; // 読み取りに失敗
      }
      // データベース上に登録する
      _registry.emplace(key.data(), std::make_pair(divGraph, handles));
      return true; // 登録成功
    }

    bool ResourceServer::LoadDivGraph(DivGraphTable divGraphTable) {
      // 要素が空の場合は登録を行わない
      if (divGraphTable.empty()) {
        return false;
      }
      // 登録情報を全て登録する
      for (auto&& [key, data] : divGraphTable) {
        // 画像の読み取りを行う
        ResourceServer::LoadDivGraph(key, data);
      }
      return true; // 成功
    }

    void ResourceServer::DeleteGraphs(std::vector<int> handles) const {
      for (auto handle : handles) {
        // グラフィックハンドルの削除
        DeleteGraph(handle);
      }
    }

    Data::DivGraph ResourceServer::GetDivGraph(std::string_view key) const {
      // キーは登録されているか
      if (!UseKey(key.data())) {
        return Data::DivGraph(); // 登録されていない場合は空情報を返す
      }
      // 対象の画像情報を返す
      return _registry.at(key.data()).first;
    }

    const int ResourceServer::GetHandle(std::string_view key, const int no) const {
      // キーは登録されているか
      if (!Contains(key.data())) {
        return -1; // 未登録
      }
      // 情報の取得
      auto [divGraph, handles] = _registry.at(key.data());
      // 対象範囲内に収まっているかの判定
      if (!IsRange(static_cast<int>(handles.size()), no)) {
        return -1; // ハンドル番号が範囲外
      }
      return handles.at(no); // 対応するグラフィックハンドルを返す
    }

    std::vector<int> ResourceServer::GetHandles(std::string_view key) const {
      // キーが未登録の場合
      if (!Contains(key.data())) {
        // ハンドルを格納するコンテナ
        std::vector<int> handles{};
        // 空のコンテナを返す
        return handles;
      }
      // ハンドルを返す
      auto [divGraph, handle] = _registry.at(key.data());
      return handle;
    }

    bool ResourceServer::SetDirectryPath(std::filesystem::path path) {
      // ディレクトリは空か
      if (!_directory.empty()) {
        return true; // 登録されている
      }
      // パスは有効か
      if (std::filesystem::is_directory(path)) {
        _directory = path;
        return true;
      }
      return false;
    }

    bool ResourceServer::IsRange(int num, int value) const {
      /**
       * @brief  引数の判定
       * @param  number 対象の値
       * @return 1以上の場合は-1した値を返す 0以下の場合は-1を返す
       */
      auto CheckNum = [](int number) {
        // 引数は0以下か
        if (number <= 0) {
          return -1;
        }
        return number - 1;
      };
      // 引数を修正
      value = CheckNum(value);
      // 対象範囲内に収まっているか
      return 0 <= value && num <= value;
    }
  } // namespace Resource
} // namespace AppFrame