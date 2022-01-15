/*****************************************************************//**
 * @file   InputOperation.h
 * @brief  入力処理クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <string>
#include <vector>
#include <future>
#include "JoypadState.h"

namespace AppFrame {
  namespace Application {
    // デバイスタイプ(入力状態の取得で使用)
    constexpr auto DeviceKeyboard = 0; //!< キーボード
    constexpr auto DeviceMouse = 1;    //!< マウス
    constexpr auto DeviceJoypad = 2;   //!< ジョイパッド
    /**
     * @class InputOperation
     * @brief 入力処理
     */
    class InputOperation {
    public:
      /**
       * @brief 実行状態
       */
      enum class State {
        Active,   // 正常
        Paused,   // 一時停止
        NonActive // 接続なし
      };
      /**
       * @brief コンストラクタ
       * @param app アプリケーションの参照
       */
      InputOperation(class ApplicationBase& app);
      /**
       * @brief デストラクタ
       */
      ~InputOperation();
      /**
       * @brief 更新処理
       */
      void Process();
      /**
       * @brief  入力デバイスの登録
       * @return true:追加成功 false:追加失敗
       */
      bool AddJoypad();
      /**
       * @brief  入力デバイスが接続されているかの判定
       * @return true:接続あり　false:接続なし
       */
      const bool IsConnection();
      /**
       * @brief  実行状態の取得
       * @return 実行状態
       */
      const State OperationState() const {
        return _state;
      }
      /**
       * @brief  ジョイパッドの押下情報取得
       * @return ジョイパッドの押下情報
       */
      bool JoypadInputButtons(const int id) const;
    private:
      ApplicationBase& _app; //!< アプリケーションの参照
      State _state{};        //!< 状態
      JoypadState _joypad;  //!< ジョイパッドの入力状態
      int _accessLimit{0};   //!< デバイスの接続上限
    };
  } // namespace Application
} // namespace AppFrame