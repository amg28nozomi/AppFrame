/*****************************************************************//**
 * @file   Operation.cpp
 * @brief  入力処理クラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "Operation.h"
#include <DxLib.h>
#include "JoypadState.h"

namespace AppFrame {
  namespace Application {

    Operation::Operation() {
      _joypads.clear();
    }

    Operation::~Operation() {
    }

    void Operation::Process() {
      // デバイスは接続されているか？
      if (JoypadState::GetConnection() != GetJoypadNum()) {
        return; // 接続されていない
      }
      for (auto&& pad : _joypads) {
        pad.Process();
      }
    }
  } // namespace Application
} // namespace AppFrame