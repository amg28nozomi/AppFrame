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
      _id = id; // 接続数を識別番号に設定
      _type = Type::Joypad;
      _press.fill(0);
      _trigger.fill(0);
    }

    void JoypadState::Process() {
      auto old = _press; // 1フレーム前の入力情報
      XINPUT_STATE data;
      // 入力状態の更新
      if (!GetJoypadXInputState(_id, &data)) {
        return; // 取得失敗
      }



      _press = GetJoypadInputState(_id);
      // トリガ情報の更新
      _trigger = _press ^ old & _press;
      // アナログスティックの入力状態取得
      GetJoypadAnalogInput(&_leverX, &_leverY, _id);
    }

    void JoypadState::ChangeData(XINPUT_STATE press) {
      auto old = _press;
      auto num = 0; // 処理回数
      // 各種データの変換
      for (auto button : press.Buttons) {
        _press[num] = button;
      }
    }
  }
}