/*****************************************************************//**
 * @file   JoypadState.cpp
 * @brief  ジョイパッドの入力状態クラス
 *
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#include "JoypadState.h"

/**
 * @brief アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief アプリケーションベース
   */
  namespace Application {

    JoypadState::JoypadState() : InputBase() {
    }

    void JoypadState::Process() {
      if (_state != State::Active) {
        return; // 入力処理を行わない
      }
      auto old = _press;
      // 入力状態の更新
      _press = GetJoypadInputState(PAD_INPUT_1);
      GetJoypadAnalogInput(&_stickX, &_stickY, PAD_INPUT_1);
      // トリガ情報の算出
      _trigger = _press ^ old & _press;
    }
  } // namespace Application
} // namespace AppFrame