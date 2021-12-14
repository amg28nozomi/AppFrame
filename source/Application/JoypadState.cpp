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
  namespace App {

    int JoypadState::_connection = 0;

    JoypadState::JoypadState() {
      // 接続数を識別番号に設定
      _id = _connection;
      ++_connection;
      _press = 0;
      _trigger = 0;
    }

    JoypadState::~JoypadState() {
      --_connection;
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
      auto&& [xBuf, yBuf] = _lever;
      if (!GetJoypadAnalogInput(&xBuf, &yBuf, _id)) {
#ifdef _DEBUG
        throw std::logic_error("アナログスティックの入力状態の取得に失敗しました\n");
#endif
        return false; // 更新失敗
      }
      return true;    // 更新成功
    }
  }
}