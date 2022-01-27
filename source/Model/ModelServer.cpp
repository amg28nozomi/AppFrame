/*****************************************************************//**
 * @file   ModelServer.cpp
 * @brief  文字列をキーとしてモデル情報とアニメーションを管理するサーバクラス
 *
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#include "ModelServer.h"
#include <utility>
#include <DxLib.h>
#include "../Math/Arithmetic.h"
#include "../Model/ModelData.h"

namespace AppFrame {
  namespace Model {
//
//    ModelServer::ModelServer() : Server::ServerTemplateUnordered<std::string, ModelData>() {
//#ifdef _DEBUG
//      SetServerName("ModelServer");
//#endif
//      Server::ServerTemplateUnordered<std::string, ModelData>::Release();
//    }
//
//    bool ModelServer::Release() {
//      // 各種コンテナの解放処理を行う
//      for (auto&& [key, value] : _registry) {
//        DeleteModels(value.GetHandles()); // モデルハンドルを削除する
//        value.AnimeClear(); // アニメーション情報の削除
//      }
//      _registry.clear(); // コンテナを解放する
//    }
//
//    bool ModelServer::AddMV1Model(std::string_view key, std::string_view path) {
//      // キーが重複してるかの判定
//      if (!UseKey(key.data())) {
//        // 
//
//        // キーが重複している場合は既存データを削除
//        auto&& [path, handles, animes] = _registry.at(key.data());
//        DeleteModels(handles); // モデルハンドルを削除
//        animes.clear();        // アニメーションを削除する
//        _registry.erase(key.data());
//      }
//      // モデルハンドルの読み取り
//      auto handle = MV1LoadModel(path.data());
//      // モデルハンドルの取得に成功したか
//      if (handle == -1) {
//#ifdef _DEBUG
//        // モデルハンドルの読み取りに失敗した場合はログに出力する
//        auto message = static_cast<std::string>(path) + ":mv1ファイルの読み取りに失敗しました\n";
//        DebugString(message);
//#endif
//        return false; // 取得失敗
//      }
//      // モデルハンドルを格納するコンテナ
//      std::vector<int> handles{ handle };
//      auto animNum = MV1GetAnimNum(handle); // アニメーション番号の取得
//      // アニメーション情報を格納する連想配列
//      std::unordered_map<std::string, int> animes;
//      // アニメーション情報を登録する
//      for (auto num = 0; num < animNum; ++num) {
//        // アニメーション名の取得
//        auto animName = MV1GetAnimName(handle, num);
//        // 取得したデータを基に要素を構築
//        animes.emplace(animName, num);
//      }
//      // 読み取ったデータを登録する
//      _registry.emplace(key.data(), path.data(), handles, animes);
//      return true; // 登録成功
//    }
//
//    void ModelServer::DeleteModels() {
//      Release(); // 全てのモデルハンドルを削除
//    }
//
//    bool ModelServer::DeleteDuplicateModels(std::string_view key, bool flag) {
//      // フラグが立っている場合は全要素に処理を行う
//      if (flag) {
//        for (auto [key, value] : _registry) {
//          auto [path, handle, animes] = value;
//          // 複製されたモデルハンドルのみを削除
//          DeleteDuplicateModels(handle);
//        }
//      }
//      // 要素はあるか
//      if (!_registry.contains(key.data())) {
//        return false; // 未登録
//      }
//      // 複製されたモデルハンドルのみを削除する
//      DeleteDuplicateModels(Handles(key.data()));
//      return true; // 削除完了
//    }
//
//    std::pair<int, unsigned short> ModelServer::GetModel(std::string_view key, unsigned short number) {
//      // キーが登録されているかの判定
//      if (_registry.contains(key.data())) {
//        return std::make_pair(-1, MaxNumber); // キーが未登録
//      }
//      auto handles = Handles(key.data()); // コンテナを取得
//      auto size = static_cast<int>(handles.size());
//      // 識別番号は範囲内に収まっているか
//      if (Math::Arithmetic::IsRange(no, 0, size - 1)) {
//        return std::make_pair(handles.at(no), no); // 対応するモデルハンドルを返す
//      }
//      // オリジナルハンドルを基に複製
//      auto handle = DxLib::MV1DuplicateModel(handles.front());
//      // 複製したモデルハンドルを末尾に登録
//      handles.emplace_back(handle);
//      // モデルハンドルと識別番号を返す
//      return std::make_pair(handle, size);
//    }
//
//    int ModelServer::GetAnimIndex(std::string_view key, std::string_view animName) {
//      // キーは有効か
//      if (!_registry.contains(key.data())) {
//        return -1; // 未登録
//      }
//      const auto animes = Animes(key.data());
//      // 対象アニメーションは存在するか
//      if (!animes.contains(animName.data())) {
//        return -1; // 存在しない
//      }
//      // アニメーション番号を返す
//      return animes.at(animName.data());
//    }
//
//    void ModelServer::DeleteModels(std::unordered_map<unsigned short, int>& handles) {
//      for (auto [number, handle] : handles) {
//        MV1DeleteModel(handle); // モデルハンドルを削除
//      }
//      handles.clear(); // コンテナを解放する
//    }
//
//    void ModelServer::DeleteDuplicateModels(std::vector<int>& handles) {
//      // オリジナルのモデルハンドル
//      auto original = handles.front();
//      // 複製されたモデルハンドルを削除する
//      std::erase_if(handles, [original](int handle) {
//        if (original != handle) {
//          MV1DeleteModel(handle); // モデルハンドルを削除する
//          return true;
//        }
//        return false;
//        });
//    }
//
//    std::vector<int>& ModelServer::Handles(std::string_view key) {
//      auto [path, handles, animes] = _registry[key.data()];
//      return handles;
//    }
//
//    const std::unordered_map<std::string, int>& ModelServer::Animes(std::string_view key) {
//      auto [path, handles, animes] = _registry[key.data()];
//      return animes;
//    }
  } // namespace Model
} // namespace AppFrame