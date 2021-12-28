/*****************************************************************//**
 * @file   JoypadState.cpp
 * @brief  
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "JoypadState.h"
#include <DxLib.h>

namespace AppFrame {
  namespace Application {

    JoypadState::JoypadState(const int id) : InputBase() {
      // 接続数を識別番号に設定
      _id = id;
      _type = Type::Joypad;
      ++_connection;
    }

    void JoypadState::Process() {
      auto old = _press; // 1フレーム前の入力情報
      _press = GetJoypadInputState(_id);
      // トリガ情報の更新
      _trigger = _press ^ old & _press;
      // アナログスティックの入力状態取得
      GetJoypadAnalogInput(&_leverX, &_leverY, _id);
    }
  }
}