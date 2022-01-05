/*****************************************************************//**
 * @file   JoypadState.h
 * @brief  �W���C�p�b�h�̓��͏�ԃN���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "InputBase.h"
#include <array>
#include <utility>

namespace AppFrame {
  namespace Application {
    constexpr auto XInputMax = 22; //!< �������̓f�[�^�̑���
    /**
     * @class JoypadState
     * @brief �W���C�p�b�h�̓��͏��(XInput)
     */
    class JoypadState : public InputBase < std::array<int, XInputMax> > {
    public:
      /**
       * @brief �R���X�g���N�^
       * @param id �p�b�h�̎��ʎq
       */
      JoypadState(const int id);
      /**
       * @brief  ���͏�Ԃ̍X�V
       */
      void Process() override;
      /**
       * @brief  ���ʔԍ��̎擾
       * @return ���ʔԍ�
       */
      inline const int GetId() const {
        return _id;
      }
    private:
      int _id{0};      //!< ���ʔԍ�
      std::
      /**
       * @brief XInput�̓��̓f�[�^��int�^�ɕϊ�����
       * @param press XInput�̓��͏����i�[����\����
       */
      void ChangeData(XINPUT_STATE press);
    };
  } // namespace Application
} // namespace AppFrame