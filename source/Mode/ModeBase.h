/*****************************************************************//**
 * @file   ModeBase.h
 * @brief  モードの基底クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once

namespace AppFrame {
  namespace Application {
    /**
     * @class ApplicationBase
     * @brief 前方宣言
     */
    class ApplicationBase;
  }
  /**
   * @brief モード用の名前空間
   */
  namespace Mode {
    /**
     * @class ModeBase
     * @brief シーンの基底クラス
     */
    class ModeBase {
    public:
      /**
       * @brief モードの生成
       * @param app アプリケーションの参照
       */
      ModeBase(Application::ApplicationBase& app);
      /**
       * @brief モードの削除
       */
      ~ModeBase();
      /**
       * @brief  モードの初期化
       * @return true:初期化成功 false:初期化失敗
       */
      virtual bool Init() = 0;
      /**
       * @brief  入口処理
       * @return true:処理成功 false:処理失敗
       */
      virtual bool Enter();
      /**
       * @brief  出口処理
       * @return true:処理成功 false:失敗
       */
      virtual bool Exit();
      /**
       * @brief  モードの更新
       * @return true:更新成功 false:更新失敗
       */
      virtual bool Process();
      /**
       * @brief  モードの描画
       * @return true:描画成功 false:描画失敗
       */
      virtual bool Draw();
      /**
       * @brief  アプリケーションの取得
       * @return アプリケーションの参照
       */
      inline Application::ApplicationBase& GetApplication() const {
        return _app;
      }
    protected:
      Application::ApplicationBase& _app; //!< アプリケーションの参照
    };
  } // namespace Mode
} // namespace AppFrame