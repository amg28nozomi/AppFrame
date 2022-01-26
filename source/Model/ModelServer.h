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

    constexpr auto AllDelete = true;
    constexpr auto OneDelete = false;
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
       * @brief  登録されている全てのモデル情報を削除する
       */
      void DeleteModels();
      /**
       * @brief  複製したモデルハンドルを削除する
       * @param  key モデル情報に紐づけられた文字列
       * @param  flag 全削除フラグ(true:全ての複製ハンドルを削除 false:キーに対応したコンテナのみ削除)
       * @return true:処理成功 false:キーがヒットしなかった
       */
      bool DeleteDuqlicateModels(std::string_view key, bool flag = false);
      /**
       * @brief  モデルハンドルの取得
       * @param  key モデル情報に紐づけられた文字列
       * @return first:取得に成功した場合はモデルハンドルを返す 失敗した場合は-1を返す
       *         second:識別番号
       */
      std::pair<int, int> GetModel(std::string_view key, const int no);
      /**
       * @brief  指定したアニメーション番号の取得
       * @param  key モデル情報に紐づけられた文字列
       * @param  animeName アニメーション名
       * @return 取得に成功した場合はアニメーション番号を返す
       *         取得に失敗した場合は-1を返す
       */
      int GetAnimIndex(std::string_view key, std::string_view animName);
    private:
      /**
       * @brief 登録されているモデルハンドルを解放する
       * @param handles モデルハンドルが格納されているコンテナの参照
       */
      void DeleteModels(std::vector<int>& handles);
      /**
       * @brief 複製登録されているハンドルのみを削除する
       * @param handles モデルハンドルが格納されているコンテナの参照
       */
      void DeleteDuqlicateModels(std::vector<int>& handles);
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
      const std::unordered_map<std::string, int>& Animes(std::string_view key);
    };
  } // namespace Model
} // namespace AppFrame