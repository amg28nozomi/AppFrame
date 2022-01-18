/*****************************************************************//**
 * @file   XBoxState.cpp
 * @brief  Xbox�R���g���[���[�̓��͏�ԃN���X�̒�`
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "XBoxState.h"
#include <string>
#ifdef _DEBUG
#include <stdexcept>
#endif
#include "../Math/Arithmetic.h"

namespace AppFrame {
  namespace Application {
    constexpr auto JoypadLeftStick = false; // ���X�e�B�b�N
    constexpr auto JoypadRightStick = true; // �E�X�e�B�b�N

    XBoxState::XBoxState() : InputBase() {
      _press = XINPUT_STATE();
      _trigger = _press;
      _type = DeviceType::Joypad;
    }

    void XBoxState::Process() {
      auto old = _press;
      // ���͏�Ԃ̎擾
      if (GetJoypadXInputState(DX_INPUT_PAD1, &_press) == Error) {
        _state = State::NonActive;
#ifdef _DEBUG
        throw std::logic_error("����ID���L���ł͂���܂���\n");
#endif
        return; // �擾���s
      }
      // �e��g���K���̍X�V
      for (auto no = 0; auto&& button : _trigger.Buttons) {
        button = Trigger(_press.Buttons[no], old.Buttons[no]);
        ++no;
      }
    }

    bool XBoxState::GetButton(const int key, const bool type) const {
      // �͈͓��Ɏ��܂��Ă��邩�̔���
      if (!Math::Arithmetic::IsRange(key, 0, 15)) {
        return false; // �L�[���s��
      }
      // �t���O�ɉ����ĕԂ��l��؂�ւ���
      if (type == InputPress) {
        return _press.Buttons[key]; // ��������Ԃ�
      }
      return _trigger.Buttons[key]; // �g���K����Ԃ�
    }

    std::pair<int, int> XBoxState::GetStick(const bool stick) const {
      int x, y; // �c���̓��͏��
      // ���E�ǂ���̓��͏�Ԃ��擾���邩
      if (stick == JoypadLeftStick) {
        // ���X�e�B�b�N�̓��͏�Ԃ�Ԃ�
        x = static_cast<int>(_press.ThumbLX);
        y = static_cast<int>(_press.ThumbLY);
        return std::make_pair(x, y);
      }
      // �E�X�e�B�b�N�̓��͏�Ԃ�Ԃ�
      x = static_cast<int>(_press.ThumbRX);
      y = static_cast<int>(_press.ThumbRY);
      return std::make_pair(x, y);
    }
  } // namespace Application
} // namespace AppFrame