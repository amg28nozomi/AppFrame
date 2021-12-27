/*****************************************************************//**
 * @file   JoypadState.cpp
 * @brief  
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "JoypadState.h"
#include <stdexcept>

namespace {
  constexpr auto InputError = -1; // 入力処理失敗
}

namespace AppFrame {
  namespace Application {

    JoypadState::JoypadState() : InputBase() {
      // 接続数を識別番号に設定
      _id = _connection;
      ++_connection;
      _press = 0;
      _trigger = 0;
      _leverX = 0;
      _leverY = 0;
    }

    bool JoypadState::Process() {
      auto old = _press; // 1フレーム前の入力情報
      _press = GetJoypadInputState(_id);
      if (_press == InputError) {
#ifdef _DEBUG
        throw std::logic_error("ジョイパッドの入力状態の取得に失敗しました\n");
#endif
        return false; // 更新失敗
      }
      // トリガ情報の更新
      _trigger = _press ^ old & _press;
      // アナログスティックの入力状態取得
      if (!GetJoypadAnalogInput(&_leverX, &_leverY, _id)) {
#ifdef _DEBUG
        throw std::logic_error("アナログスティックの入力状態の取得に失敗しました\n");
#endif
        return false; // 更新失敗
      }
      return true;    // 更新成功
    }
  }
}