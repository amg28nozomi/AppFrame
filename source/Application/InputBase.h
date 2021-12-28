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
    constexpr auto ProcessError = -1; // 処理失敗
    /**
     * @class InputBase
     * @brief 入力状態クラス
     */
    class InputBase {
    public:
      /**
       * @class Type
       * @brief 入力デバイスの種類
       */
      enum class Type {
        Joypad, //!< ジョイパッド
        Mouse   //!< マウス
      };
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
      virtual void Process() = 0;
      /**
       * @brief  デバイスタイプの取得
       * @return デバイスタイプ
       */
      inline const Type GetType() const {
        return _type;
      }
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
      Type _type{};
      int _press{0};   //!< 押下情報
      int _trigger{0}; //!< トリガ情報
      bool _active{true}; //!< 有効かどうか
      /**
       * @brief  トリガ情報の更新
       * @param  old 前フレームの入力状態
       */
      inline void Trigger(int old) {
        _trigger =  _press ^ old & _press;
      }
    };
  } // Application
} // AppFrame