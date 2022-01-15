/*****************************************************************//**
 * @file   JoypadState.cpp
 * @brief  
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "JoypadState.h"
#include <string>
#ifdef _DEBUG
#include <stdexcept>
#endif
#include "../Math/Arithmetic.h"

namespace AppFrame {
  namespace Application {

    JoypadState::JoypadState(const int id) : InputBase() {
      _id = id; // �ڑ��������ʔԍ��ɐݒ�
      _press = XINPUT_STATE();
      _trigger = _press;
      _type = DeviceType::Joypad;
    }

    void JoypadState::Process() {
      auto old = _press;
      // ���͏�Ԃ̎擾
      if (!GetJoypadXInputState(_id, &_press)) {
#ifdef _DEBUG
        throw std::logic_error("����ID���L���ł͂���܂���\n");
#endif
        _state = State::NonActive;
        return; // �擾���s
      }
      // �e��g���K���̍X�V
      for (auto no = 0; auto&& button : _trigger.Buttons) {
        button = Trigger(_press.Buttons[no], old.Buttons[no]);
        ++no;
      }
      // �g���K�[�{�^���̍X�V
      _trigger.LeftTrigger = Trigger(_press.LeftTrigger, old.LeftTrigger);
      _trigger.RightTrigger = Trigger(_press.RightTrigger, old.RightTrigger);
      // �e��X�e�B�b�N�̍X�V
      _trigger.ThumbLX = Trigger(_press.ThumbLX, old.ThumbLX);
      _trigger.ThumbLY = Trigger(_press.ThumbLY, old.ThumbLY);
      _trigger.ThumbRX = Trigger(_press.ThumbRX, old.ThumbRX);
      _trigger.ThumbRY = Trigger(_press.ThumbRY, old.ThumbRY);
    }

    bool JoypadState::GetButton(const int key, const bool type) const {
      // �͈͓��Ɏ��܂��Ă��邩�̔���
      if (!Math::Arithmetic::IsRange(key, 0, 15)) {
        return false; // �L�[���s��
      }
      // �t���O�ɉ����ĕԂ��l��؂�ւ���
      if (type) {
        return _press.Buttons[key]; // ��������Ԃ�
      }
      return _trigger.Buttons[key]; // �g���K����Ԃ�
    }
  } // namespace Application
} // namespace AppFrame