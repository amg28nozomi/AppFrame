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

    ModelServer::ModelServer() : Server::ServerTemplateUnordered<std::string, ModelMap>() {
    }

    bool ModelServer::Release() {
      // 登録されている全データの削除を行う
      for (auto&& [key, model] : _registry) {
        // モデルハンドルとアニメーションを取得
        auto&& [handles, anima] = model;
        // モデルデータの削除
        for (auto handle : handles) {
          MV1DeleteModel(handle);
        }
        // コンテナの解放
        handles.clear();
        anima.clear();
      }
    }
    
    bool AddModel(std::string_view key, std::string_view path) {
      return true;
    }

    bool ModelServer::LoadModel(std::string_view key) {
      // ファイルの読み取り
      if (_registry.contains(key.data())) {
        auto [handles, animas] = _registry.at(key.data());
        // モデルが登録されている場合は既存モデルを削除する
        
      }
    }

  } // namespace Model
} // namespace AppFrame