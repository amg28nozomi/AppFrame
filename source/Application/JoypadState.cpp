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

namespace AppFrame {
  namespace Application {

    JoypadState::JoypadState(const int id) {
      _id = id; // 接続数を識別番号に設定
      _type = Type::Joypad;
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
      _trigger.LeftTrigger = Trigger(_press.LeftTrigger, old.LeftTrigger);
      _trigger.RightTrigger = Trigger(_press.RightTrigger, old.RightTrigger);
      _trigger.ThumbLX = Trigger(_press.ThumbLX, old.ThumbLX);
      _trigger.ThumbLY = Trigger(_press.ThumbLY, old.ThumbLY);
      _trigger.ThumbRX = Trigger(_press.ThumbRX, old.ThumbRX);
      _trigger.ThumbRY = Trigger(_press.ThumbRY, old.ThumbRY);
    }
  }
}