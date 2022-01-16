/*****************************************************************//**
 * @file   JoypadState.cpp
 * @brief  
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "JoypadState.h"
#include <string>
#ifdef _DEBUG
#include <stdexcept>
#endif
#include "../Math/Arithmetic.h"

namespace AppFrame {
  namespace Application {
    constexpr auto JoypadLeftStick = false; // 左スティック
    constexpr auto JoypadRightStick = true; // 右スティック

    JoypadState::JoypadState(const int id) : InputBase() {
      _id = id; // 接続数を識別番号に設定
      _press = XINPUT_STATE();
      _trigger = _press;
      _type = DeviceType::Joypad;
    }

    void JoypadState::Process() {
      auto old = _press;
      // 入力状態の取得
      if (!GetJoypadXInputState(_id, &_press)) {
#ifdef _DEBUG
        throw std::logic_error("識別IDが有効ではありません\n");
#endif
        _state = State::NonActive;
        return; // 取得失敗
      }
      // 各種トリガ情報の更新
      for (auto no = 0; auto&& button : _trigger.Buttons) {
        button = Trigger(_press.Buttons[no], old.Buttons[no]);
        ++no;
      }
    }

    bool JoypadState::GetButton(const int key, const bool type) const {
      // 範囲内に収まっているかの判定
      if (!Math::Arithmetic::IsRange(key, 0, 15)) {
        return false; // キーが不正
      }
      // フラグに応じて返す値を切り替える
      if (type == InputPress) {
        return _press.Buttons[key]; // 押下情報を返す
      }
      return _trigger.Buttons[key]; // トリガ情報を返す
    }

    std::pair<int, int> JoypadState::GetStick(const bool stick) const {
      int x, y; // 縦横の入力状態
      // 左右どちらの入力状態を取得するか
      if (stick == JoypadLeftStick) {
        // 左スティックの入力状態を返す
        x = static_cast<int>(_press.ThumbLX);
        y = static_cast<int>(_press.ThumbLY);
        return std::make_pair(x, y);
      }
      // 右スティックの入力状態を返す
      x = static_cast<int>(_press.ThumbRX);
      y = static_cast<int>(_press.ThumbRY);
      return std::make_pair(x, y);
    }
  } // namespace Application
} // namespace AppFrame