/*****************************************************************//**
 * @file   Operation.cpp
 * @brief  ���͏����N���X�̒�`
 * 
 * @author ��؊�C
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
  constexpr auto PadMax = 4;   // �W���C�p�b�h�̐ڑ������
  constexpr auto MouseMax = 1; // �}�E�X�̐ڑ������
  constexpr auto Count120 = 120;
}

namespace AppFrame {
  namespace Application {
    // �W���C�p�b�h
    std::array<int, 4> JoypadType = {
      DX_INPUT_PAD1, // �W���C�p�b�h1
      DX_INPUT_PAD2, // �W���C�p�b�h2
      DX_INPUT_PAD3, // �W���C�p�b�h3
      DX_INPUT_PAD4  // �W���C�p�b�h4
    };

    Operation::Operation(ApplicationBase& app) : _app(app) {

    }

    Operation::~Operation() {
    }

    void Operation::Process() {
      // ��Ԃɉ����Ă������̎��s
      switch (_state) {
      case State::Active:
        // �ڑ�����
        if (GetJoypadNum() == 0) {
          _state = State::NonActive;
          return; // �ڑ��Ȃ�
        }
        // �e��f�o�C�X�̓��͏��������s
        for (auto&& device : _devices) {
          device.Process();
        }
      case State::Paused:
        return; // ���s�Ȃ�
      case State::NonActive:
        // �Đڑ��͊����������H
        if (GetJoypadNum() != 0) {
          // �Đڑ�����
          _state = State::Active;
          return;
        }
        // �w��t���[���Ɉ�x�A�Đݒ�����݂�
        if (_app.GetFrameCount() % Count120 == 0) {
          ReSetupJoypad();
        }
        return;
      }
    }

    bool Operation::AddDevice(class InputBase& device) {
      // ���̓f�o�C�X
      return false;
    }

    InputBase& Operation::GetDevice(int type, int number) {
#ifndef _DEBUG
#else
#endif
    }

    const bool Operation::IsConnection() {
      // �W���C�p�b�h�͐ڑ�����Ă��邩
      if (GetJoypadNum == 0) {
        // �ڑ���Ԃ̏ꍇ�͔�ڑ���ԂɈڍs
        if (_state == State::Active) {
          _state = State::NonActive;
        }
        return false; // �ڑ��Ȃ�
      }
      return true;    // �ڑ�����
    }

    //std::future<bool> Operation::ReConnect() {
    //  // 1�b�Ԃ�1�x�A�Đݒ���s��
    //  ReSetupJoypad();
    //  return true;
    //}
  } // namespace Application
} // namespace AppFrame