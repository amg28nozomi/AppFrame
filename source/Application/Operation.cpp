/*****************************************************************//**
 * @file   Operation.cpp
 * @brief  入力処理クラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "Operation.h"
#include <DxLib.h>
#include "InputBase.h"
#include "JoypadState.h"

namespace AppFrame {
  namespace Application {

    const int joypad[] = {
      DX_INPUT_PAD1, DX_INPUT_PAD2, DX_INPUT_PAD3, DX_INPUT_PAD4
    };

    Operation::Operation(ApplicationBase& app) : _app(app) {
      _joypads.clear();
    }

    Operation::~Operation() {
    }

    void Operation::Process() {
      // 接続がない場合
      if (_state != State::NonActive) {
        // デバイスは接続されているか？
        if (GetJoypadNum() == 0) {
          _state = State::NonActive; // 接続無し
          return; // 接続されていない
        }
      }

      // デバイスは接続されているか？
      if (GetJoypadNum() == 0) {
        return; // 接続されていない
      }
      for (auto&& pad : _joypads) {
        // 有効な場合は処理を実行する
        pad.Process();
      }
    }

    bool Operation::AddDevice(class InputBase& device) {
      // 入力デバイス
      return false;
    }

    const bool Operation::IsConnection() const {
      // ジョイパッドは接続されているか
      // 各種デバイスは接続されているか
      if (GetJoypadNum() == 0) {
        return false;
      }
      return true;
    }

    //std::future<bool> Operation::ReConnect() {
    //  // 1秒間に1度、再設定を行う
    //  ReSetupJoypad();
    //  return true;
    //}
  } // namespace Application
} // namespace AppFrame