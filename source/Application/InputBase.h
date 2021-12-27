/*****************************************************************//**
 * @file   InputBase.h
 * @brief  入力状態の基底クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once

namespace AppFrame {
  namespace Application {
    /**
     * @class InputBase
     * @brief 入力状態クラス
     */
    class InputBase {
    public:
      /**
       * @brief  コンストラクタ
       */
      InputBase();
      /**
       * @brief  デストラクタ
       */
      ~InputBase();
      /**
       * @brief  更新処理
       */
      virtual bool Process() = 0;
      /**
       * @brief  総接続数の取得
       * @return 総接続数
       */
      static inline int GetConnection() {
        return _connection;
      }
      /**
       * @brief  有効かどうかの判定
       * @return true:有効 false:非有効
       */
      bool IsActive() const {
        return _active;
      }
    protected:
      static inline int _connection{0}; //!< 総接続数
      bool _active{true}; //!< 有効かどうか
    };
  } // Application
} // AppFrame