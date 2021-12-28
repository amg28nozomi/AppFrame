/*****************************************************************//**
 * @file   Operation.cpp
 * @brief  ���͏����N���X�̒�`
 * 
 * @author ��؊�C
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
      // �f�o�C�X�͐ڑ�����Ă��邩�H
      if (GetJoypadNum() == 0) {
        return; // �ڑ�����Ă��Ȃ�
      }
      for (auto&& pad : _joypads) {
        pad.Process(); // �X�V�����Ăяo��
      }
    }
  } // namespace Application
} // namespace AppFrame