/*****************************************************************//**
 * @file   JoypadState.cpp
 * @brief  
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "JoypadState.h"
#include <DxLib.h>

namespace AppFrame {
  namespace Application {

    JoypadState::JoypadState(const int id) : InputBase() {
      // �ڑ��������ʔԍ��ɐݒ�
      _id = id;
      _type = Type::Joypad;
      ++_connection;
    }

    void JoypadState::Process() {
      auto old = _press; // 1�t���[���O�̓��͏��
      _press = GetJoypadInputState(_id);
      // �g���K���̍X�V
      _trigger = _press ^ old & _press;
      // �A�i���O�X�e�B�b�N�̓��͏�Ԏ擾
      GetJoypadAnalogInput(&_leverX, &_leverY, _id);
    }
  }
}