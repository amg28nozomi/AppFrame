/*****************************************************************//**
 * @file   ServerTemplateUnordered.h
 * @brief  サーバ用テンプレートクラス(unordered_map)
 * 
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#pragma once
#include "ServerBase.h"
#include <unordered_map>
/**
 * @brief アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief サーバベース
   */
  namespace Server {
    /**
     * @class  ServerTemplateUnordered
     * @brief  連想配列に対応したサーバテンプレート
     * @tparam Key 連想配列のキーとして使用する型
     * @tparam Value 連想配列の値として使用する型
     */
    template <typename Key, typename Value>
    class ServerTemplateUnordered : public ServerBase<std::unordered_map<Key, Value>> {
    public:
      /**
       * @brief コンストラクタ
       */
      ServerTemplateUnordered();
      /**
       * @brief  リソースの解放
       * @return true:解放成功 false:問題発生
       */
      virtual bool Release() override;
      /**
       * @brief  デフォルトの登録処理
       * @param  key 登録時に紐づけるキー情報
       * @param  value 登録用データ
       * @return true:登録成功 false:登録失敗
       */
      virtual bool Register(Key key, Value value);
    protected:
      /**
       * @brief  対象キーが未使用かの判定
       * @param  key 判定対象
       * @return true:登録可能 false:使用済み
       */
      bool UsedKey(Key key) const;


    };

    template <typename Key, typename Value>
    ServerTemplateUnordered<Key, Value>::ServerTemplateUnordered() {
    }

    template <typename Key, typename Value>
    bool ServerTemplateUnordered<Key, Value>::Release() {
      using UnorderedServer = ServerBase<std::unordered_map<Key, Value>>;
      // デフォルトでは全要素の解放のみを行う
      UnorderedServer::_registry.clear();
      return true;
    }

    template <typename Key, typename Value>
    bool ServerTemplateUnordered<Key, Value>::Register(Key key, Value value) {
      using UnorderedServer = ServerBase<std::unordered_map<Key, Value>>;
      // キーは登録可能か？
      if (!UsedKey(key)) {
        return false; // 登録済み
      }
      // 登録
      UnorderedServer::_registry.emplace(key, value);
      return true;    // 登録成功
    }

    template <typename Key, typename Value>
    bool ServerTemplateUnordered<Key, Value>::UsedKey(Key key) const {
      using UnorderedServer = ServerBase<std::unordered_map<Key, Value>>;
      // キーは未登録か
      if (!UnorderedServer::_registry.contains(key)) {
#ifdef _DEBUG
        throw UnorderedServer::LogicError("キーが重複しています");
#endif
        return false; // キーが重複している
      }
      return true;    // 使用可能
    }
  } // namespace Server
} // namespace AppFrame

