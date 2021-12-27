/*****************************************************************//**
 * @file   JoypadState.cpp
 * @brief  
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "JoypadState.h"
#include <stdexcept>

namespace {
  constexpr auto InputError = -1; // ���͏������s
}

namespace AppFrame {
  namespace Application {

    JoypadState::JoypadState() : InputBase() {
      // �ڑ��������ʔԍ��ɐݒ�
      _id = _connection;
      ++_connection;
      _press = 0;
      _trigger = 0;
      _leverX = 0;
      _leverY = 0;
    }

    bool JoypadState::Process() {
      auto old = _press; // 1�t���[���O�̓��͏��
      _press = GetJoypadInputState(_id);
      if (_press == InputError) {
#ifdef _DEBUG
        throw std::logic_error("�W���C�p�b�h�̓��͏�Ԃ̎擾�Ɏ��s���܂���\n");
#endif
        return false; // �X�V���s
      }
      // �g���K���̍X�V
      _trigger = _press ^ old & _press;
      // �A�i���O�X�e�B�b�N�̓��͏�Ԏ擾
      if (!GetJoypadAnalogInput(&_leverX, &_leverY, _id)) {
#ifdef _DEBUG
        throw std::logic_error("�A�i���O�X�e�B�b�N�̓��͏�Ԃ̎擾�Ɏ��s���܂���\n");
#endif
        return false; // �X�V���s
      }
      return true;    // �X�V����
    }
  }
}