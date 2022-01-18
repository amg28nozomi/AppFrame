/*****************************************************************//**
 * @file   ModelServer.cpp
 * @brief  モデルの管理を行うモデルサーバ
 * 
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#include "ModelServer.h"

namespace AppFrame {
  namespace Model {

    ModelServer::ModelServer() : Server::ServerTemplateUnordered<std::string, std::vector<int>>() {
      // アニメーションの解放
      _animations.clear();
    }

    bool ModelServer::Release() {
      // 登録されているモデルデータの解放
      for (auto&& [key, handles] : _registry) {
        // モデルデータの削除
        for (auto handle : handles) {
          MV1DeleteModel(handle);
        }
        // ハンドルを削除する
        handles.clear();
      }
      // アニメーションの削除
      _animations.clear();
    }
    
    bool ModelServer::AddModel(std::string_view key, std::string_view path) {
      return true;
    }

    bool ModelServer::LoadModel(std::string_view key) {
      // ファイルの読み取り
      if (_registry.contains(key.data())) {
        auto handles = _registry.at(key.data());

        // モデルが登録されている場合は既存モデルを削除する
        
      }
    }

  } // namespace Model
} // namespace AppFrame