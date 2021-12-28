/*****************************************************************//**
 * @file   Operation.cpp
 * @brief  ���͏����N���X�̒�`
 * 
 * @author ��؊�C
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
      // �ڑ����Ȃ��ꍇ
      if (_state != State::NonActive) {
        // �f�o�C�X�͐ڑ�����Ă��邩�H
        if (GetJoypadNum() == 0) {
          _state = State::NonActive; // �ڑ�����
          return; // �ڑ�����Ă��Ȃ�
        }
      }

      // �f�o�C�X�͐ڑ�����Ă��邩�H
      if (GetJoypadNum() == 0) {
        return; // �ڑ�����Ă��Ȃ�
      }
      for (auto&& pad : _joypads) {
        // �L���ȏꍇ�͏��������s����
        pad.Process();
      }
    }

    bool Operation::AddDevice(class InputBase& device) {
      // ���̓f�o�C�X
      return false;
    }

    const bool Operation::IsConnection() const {
      // �W���C�p�b�h�͐ڑ�����Ă��邩
      // �e��f�o�C�X�͐ڑ�����Ă��邩
      if (GetJoypadNum() == 0) {
        return false;
      }
      return true;
    }

    //std::future<bool> Operation::ReConnect() {
    //  // 1�b�Ԃ�1�x�A�Đݒ���s��
    //  ReSetupJoypad();
    //  return true;
    //}
  } // namespace Application
} // namespace AppFrame