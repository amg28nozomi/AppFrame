/*****************************************************************//**
 * @file   ModeServer.h
 * @brief  各種シーンを管理するサーバクラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "../Server/ServerTemplateUnordered.h"
#include <memory>
#include <list>
#include "ModeBase.h"

namespace AppFrame {
  namespace Mode {
    /**
     * @class ModeServer
     * @brief モードの管理を行うサーバ
     */
    class ModeServer : public Server::ServerTemplateUnordered<std::string, std::shared_ptr<Mode::ModeBase>> {
    public:
      /**
       * @brief コンストラクタ
       * @param key  登録に使用する文字列
       * @param mode 最初に登録するシーンのポインタ
       */
      ModeServer(std::string_view key, std::shared_ptr<ModeBase> mode);
      /**
       * @brief  モードの解放
       * @return true:開放成功 false:解放失敗
       */
      bool Release() override;
      /**
       * @brief  データベースにモードを登録する
       * @param  key 登録に使用する文字列
       * @param  mode 登録するモード
       * @return true:登録成功 false:登録失敗
       */
      bool AddMode(std::string_view key, std::shared_ptr<ModeBase> mode);
      /**
       * @brief  モードの更新
       * @return 
       */
      bool Process() const;
      /**
       * @brief  モードの描画
       * @return 
       */
      bool Draw() const;
    private:
      std::list<std::shared_ptr<Mode::ModeBase>> _list; //!< モードのスタック
    };

    /**
     * @class ModeServer
     * @brief モードの管理・制御を行うサーバ
     */
    //class ModeServer {
    //public:
    //  /**
    //   * @brief string型の文字列でモードのポインタを管理する連想配列
    //   */
    //  using ModeMap = std::unordered_map<std::string, std::shared_ptr<ModeBase>>;
    //  /**
    //   * @brief モードスタック用のリスト
    //   */
    //  using ModeList = std::list<std::shared_ptr<ModeBase>>;
    //  /**
    //   * @brief コンストラクタ
    //   * @param key  最初に登録するシーンのキー
    //   * @param mode 最初に登録するシーン
    //   */
    //  ModeServer(std::string_view key, std::shared_ptr<ModeBase> mode);
    //  /**
    //   * @brief モードの登録
    //   * @param key  キーとなる文字列
    //   * @param mode モード
    //   * @return ture:登録成功 false:登録失敗
    //   */
    //  bool Register(std::string_view key, std::shared_ptr<ModeBase> mode);
    //  /**
    //   * @brief  最前面のモードのみ更新を行う
    //   * @return true:正常終了 false:問題発生
    //   */
    //  bool Process() const;
    //  /**
    //   * @brief  スタックされているモードの描画処理呼び出し
    //   * @return true:正常終了 false:問題発生
    //   */
    //  bool Draw() const;
    //private:
    //  ModeMap _registry; //!< レジストリ―
    //  ModeList _modes;   //!< スタック
    //};
  } // namespace Mode
} // namespace AppFrame