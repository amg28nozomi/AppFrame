/*****************************************************************//**
 * @file   SoundServer.h
 * @brief  音源を管理するサーバクラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "../Server/ServerTemplateUnordered.h"
#include <filesystem>
#include <unordered_map>
/**
 * @brief アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief サウンドベース
   */
  namespace Sound {
    /**
     * @class SoundServer
     * @brief 音源を管理するサウンドサーバ
     */
    class SoundServer : Server::ServerTemplateUnordered<std::string, int> {
    public:
      /**
       * @brief コンストラクタ
       */
      SoundServer();
      /**
       * @brief  解放処理
       * @return true:正常 false:異常終了
       */
      bool Release() override;
      /**
       * @brief  音源ファイルの読み取り
       * @param  key サウンドハンドルに紐づける文字列
       * @param  soundFile 音源ファイルのパス
       * @return true:正常終了 false:読み取り失敗
       */
      bool AddSound(std::string_view key, const std::filesystem::path soundFile);
      /**
       * @brief  指定したサウンドハンドルの取得
       * @param  key 対象のサウンドハンドルに紐づけられた文字列
       * @return サウンドハンドル
       *         キーが有効ではない場合は-1を返す
       */
      int GetSoundMem(std::string_view key) const;
    };
  } // namespace Sound
} // namespace AppFrame