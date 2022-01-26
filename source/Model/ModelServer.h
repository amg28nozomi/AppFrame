/*****************************************************************//**
 * @file   ModelServer.h
 * @brief  文字列をキーとしてモデル情報とアニメーションを管理するサーバクラス
 * 
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#pragma once
#include "../Server/ServerTemplateUnordered.h"

namespace AppFrame {
  namespace Model {
    /**
     * @brief モデル情報
     */
    using ModelDatas = std::tuple<std::string, std::vector<int>, std::unordered_map<std::string, int>>;
    /**
     * @class ModelServer
     * @brief 文字列をキーとしてモデル情報とアニメーションを管理するサーバ
     */
    class ModelServer : Server::ServerTemplateUnordered<std::string, ModelDatas>{
    public:
      /**
       * @brief コンストラクタ
       */
      ModelServer();
      /**
       * @brief  リソースの解放
       * @return 
       */
      bool Release() override;
      /**
       * @brief  MV1ファイルの読み取り処理
       * @param  key  モデル情報に紐づける文字列
       * @param  path 対象ファイルのパス
       * @return true:登録成功 false:登録失敗
       */
      bool AddMV1Model(std::string_view key, std::string_view path);
      /**
       * @brief  モデルハンドルの取得
       * @param  key モデル情報に紐づけられた文字列
       * @return first:取得に成功した場合はモデルハンドルを返す 失敗した場合は-1を返す
       *         second:識別番号
       */
      std::pair<int, int> GetModel(std::string_view key, const int no);
    private:
      /**
       * @brief 登録されているモデルハンドルを解放する
       * @param handles モデルハンドルが格納されているコンテナの参照
       */
      void DeleteModels(std::vector<int>& handles);
      /**
       * @brief  モデルハンドルが格納されているコンテナの参照を取得
       * @param  key 文字列
       * @return モデルハンドルが格納されているコンテナの参照
       */
      std::vector<int>& Handles(std::string_view key);
      /**
       * @brief  アニメーションが格納されているコンテナの参照を取得
       * @param  key 文字列
       * @return アニメーションが格納されているコンテナの参照
       */
      std::unordered_map<std::string, int>& Animes(std::string_view key);
    };
  } // namespace Model
} // namespace AppFrame