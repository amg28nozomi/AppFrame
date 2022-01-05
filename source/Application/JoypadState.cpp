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
      _id = id; // �ڑ��������ʔԍ��ɐݒ�
      _type = Type::Joypad;
      _press.fill(0);
      _trigger.fill(0);
    }

    void JoypadState::Process() {
      auto old = _press; // 1�t���[���O�̓��͏��
      XINPUT_STATE data;
      // ���͏�Ԃ̍X�V
      if (!GetJoypadXInputState(_id, &data)) {
        return; // �擾���s
      }



      _press = GetJoypadInputState(_id);
      // �g���K���̍X�V
      _trigger = _press ^ old & _press;
      // �A�i���O�X�e�B�b�N�̓��͏�Ԏ擾
      GetJoypadAnalogInput(&_leverX, &_leverY, _id);
    }

    void JoypadState::ChangeData(XINPUT_STATE press) {
      auto old = _press;
      auto num = 0; // ������
      // �e��f�[�^�̕ϊ�
      for (auto button : press.Buttons) {
        _press[num] = button;
      }
    }
  }
}