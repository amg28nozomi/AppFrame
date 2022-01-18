/*****************************************************************//**
 * @file   ModelServer.h
 * @brief  モデルハンドルの管理を行うモデルサーバ
 *
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#pragma once
#include "../Server/ServerTemplateUnordered.h"
#include <vector>
/**
 * @brief アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief モデルベース
   */
  namespace Model {
    /**
     * @class ModelServer
     * @brief モデルの管理を行うモデルサーバ
     */
    class ModelServer : Server::ServerTemplateUnordered<std::string, std::vector<int>> {
    public:
      /**
       * @brief コンストラクタ
       */
      ModelServer();
      /**
       * @brief  モデルの解放処理
       * @return true:正常終了 false:問題発生
       */
      bool Release() override;
      /**
       * @brief  モデルの登録処理
       * @param  key  モデルに紐づける文字列
       * @param  path 対象モデルファイルのパス
       * @return true:登録成功 false:登録失敗
       */
      bool AddModel(std::string_view key, std::string_view path);
      /**
       * @brief  モデルの読み取り処理
       * @param  filePath 対象モデルのファイル名(モデルに紐づける文字列)
       * @return true:登録成功 false:登録失敗
       */
      bool LoadModel(std::string_view filePath);
    private:
      //!< アニメーションを保持するデータベース
      std::unordered_map<std::string, std::pair<std::string, int>> _animas;
    };
  } // namespace Model
} // namespace AppFrame