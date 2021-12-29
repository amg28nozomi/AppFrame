/*****************************************************************//**
 * @file   Operation.cpp
 * @brief  入力処理クラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "Operation.h"
#include <array>
#include <DxLib.h>
#include "ApplicationBase.h"
#include "InputBase.h"
#include "JoypadState.h"
#include "MouseState.h"

namespace {
  constexpr auto PadMax = 4;   // ジョイパッドの接続数上限
  constexpr auto MouseMax = 1; // マウスの接続数上限
  constexpr auto Count120 = 120;
}

namespace AppFrame {
  namespace Application {
    // ジョイパッド
    std::array<int, 4> JoypadType = {
      DX_INPUT_PAD1, // ジョイパッド1
      DX_INPUT_PAD2, // ジョイパッド2
      DX_INPUT_PAD3, // ジョイパッド3
      DX_INPUT_PAD4  // ジョイパッド4
    };

    Operation::Operation(ApplicationBase& app) : _app(app) {

    }

    Operation::~Operation() {
    }

    void Operation::Process() {
      // 状態に応じてた処理の実行
      switch (_state) {
      case State::Active:
        // 接続判定
        if (GetJoypadNum() == 0) {
          _state = State::NonActive;
          return; // 接続なし
        }
        // 各種デバイスの入力処理を実行
        for (auto&& device : _devices) {
          device.Process();
        }
      case State::Paused:
        return; // 実行なし
      case State::NonActive:
        // 再接続は完了したか？
        if (GetJoypadNum() != 0) {
          // 再接続完了
          _state = State::Active;
          return;
        }
        // 指定フレームに一度、再設定を試みる
        if (_app.GetFrameCount() % Count120 == 0) {
          ReSetupJoypad();
        }
        return;
      }
    }

    bool Operation::AddDevice(class InputBase& device) {
      // 入力デバイス
      return false;
    }

    InputBase& Operation::GetDevice(int type, int number) {
#ifndef _DEBUG
#else
#endif
    }

    const bool Operation::IsConnection() {
      // ジョイパッドは接続されているか
      if (GetJoypadNum == 0) {
        // 接続状態の場合は非接続状態に移行
        if (_state == State::Active) {
          _state = State::NonActive;
        }
        return false; // 接続なし
      }
      return true;    // 接続あり
    }

    //std::future<bool> Operation::ReConnect() {
    //  // 1秒間に1度、再設定を行う
    //  ReSetupJoypad();
    //  return true;
    //}
  } // namespace Application
} // namespace AppFrame