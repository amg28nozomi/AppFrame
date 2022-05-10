/*****************************************************************//**
 * @file   ModeServer.h
 * @brief  各種モードを管理するサーバクラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "../Server/ServerTemplateUnordered.h"
#include <memory>
#include <list>
/**
 * @brief アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief アプリケーションベース
   */
  namespace Application {
    class ApplicationBase; //!< 前方宣言
  } // namespace Application
  /**
   * @brief モードベース
   */
  namespace Mode {
    class ModeBase;    //!< 前方宣言
    class ModeFadeOut; //!< フェードアウト
    /**
     * @class ModeServer
     * @brief モードの管理を行うサーバ
     */
    class ModeServer : public Server::ServerTemplateUnordered<std::string, std::shared_ptr<ModeBase>> {
    private:
      /**
       * @brief フェードアウトのフレンド指定
       */
      friend class ModeFadeOut;
    public:
      /**
       * @brief  コンストラクタ
       * @param  app アプリケーションの参照
       */
      ModeServer(Application::ApplicationBase& app);
      /**
       * @brief  コンストラクタ
       * @param  key  登録に使用する文字列
       * @param  mode 最初に登録するシーンのポインタ
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
       * @param  mode 登録するモードのシェアードポインタ
       */
      void AddMode(std::string_view key, std::shared_ptr<ModeBase> mode);
      /**
       * @brief  指定したモードをリストの末尾に追加する
       * @param  key 対象モードに紐づけられた文字列
       * @return true:追加成功 false:追加失敗
       */
      bool PushBack(std::string_view key);
      /**
       * @brief  リストの末尾に登録されているモードを削除する
       */
      void PopBack();
      /**
       * @brief  モードの遷移処理
       * @param  key 対象モードに紐づけられた文字列
       * @return true
       */
      bool TransionToMode(std::string_view key);
      /**
       * @brief  モードの更新
       * @return true:正常終了 false:問題発生
       */
      bool Process();
      /**
       * @brief  モードの描画
       * @return true:描画成功 false:問題発生
       */
      bool Draw() const;
      /**
       * @brief  フェードイン・フェードアウトへの遷移
       * @return true:設定 false:異常発生
       */
      bool FadeStart();
      /**
       * @brief  フェード処理フラグの取得
       * @return フェード処理フラグ
       */
      inline bool GetFadeFlag() const {
        return _fade;
      }
      /**
       * @brief  指定したモードを取得
       * @param  key モードに紐づけた文字列
       * @param  flag Enter処理を行うか(true:行う false:行わない)
       * @return 対象のモードを返す
       *         取得に失敗した場合はnullptrを返す
       */
      const std::shared_ptr<ModeBase> GetMode(const std::string_view key, const bool flag = true);
      /**
       * @brief  フェードアウトが終了したかの取得
       * @return true:終了 false:終わっていない/または処理が行われていない
       */
      inline bool IsFadeOutEnd() const {
        return _fadeOut;
      }
      /**
       * @brief  フェードアウトフラグをオフにする
       */
      void FadeOutReset() {
        _fadeOut = false;
      }
    private:
      //!< モードリスト
      std::list<std::shared_ptr<ModeBase>> _modes;
      //!< フェード処理フラグ
      bool _fade{false};
      //!< フェードアウト完了フラグ
      bool _fadeOut{false};
      /**
       * @brief  モードの登録
       * @param  key  モードに紐づける文字列
       * @param  mode 登録するモード
       * @return true
       */
      bool Register(std::string key, std::shared_ptr<ModeBase> mode) override;
      /**
       * @brief  データベースから指定したモードを取得する
       * @param  key 対象モードに紐づけられた文字列
       * @param  flag Enter処理フラグ(true:呼び出す false:呼び出さない)
       * @return 指定したモードを返す
       *         キーが有効ではない場合、nullptrを返す
       */
      std::shared_ptr<ModeBase> FetchMode(std::string_view key, const bool flag = true);
      /**
       * @brief  リストの末尾の要素の直前に指定したモードを追加する
       * @param  key 対象モードに紐づけられた文字列
       * @return true:追加成功 false:追加失敗
       */
      bool InsertBeforeBack(std::string_view key);
      /**
       * @brief  末尾のモードを削除するかの判定
       * @return true:削除 false:削除していない
       */
      bool DeleteMode();
      /**
       * @brief  フェードアウトフラグをオンにする
       */
      inline void FadeOutEnd() {
        _fadeOut = true;
      }
    };
  } // namespace Mode
} // namespace AppFrame