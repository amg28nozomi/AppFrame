/*****************************************************************//**
 * @file   JoypadState.h
 * @brief  �W���C�p�b�h�̓��͏�ԃN���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "InputBase.h"
#include <utility>
#include <DxLib.h>

namespace AppFrame {
  namespace Application {
    constexpr auto JoypadButtonNum = 16; //!< �{�^������
    constexpr auto InputPress = true;    //!< �������
    constexpr auto InputTrigger = false; //!< �g���K����
    /**
     * @class JoypadState
     * @brief �W���C�p�b�h�̓��͏��(XInput)
     */
    class JoypadState : public InputBase  {
    public:
      /**
       * @brief �R���X�g���N�^
       */
      JoypadState();
      /**
       * @brief  ���͏�Ԃ̍X�V
       */
      void Process() override;
      /**
       * @brief  �{�^�����̎擾(����)
       * @param  key  �Ή�����L�[�ԍ�(0�`15)
       *              DX���C�u������XINPUT�{�^�����͒�`
       * @brief  type �擾������̎��
       *              InputPress:�������(�f�t�H���g) InputTrigger:�g���K���
       * @return true:���͗L�� false:���͖���
       */
      bool GetButton(const int key, const bool type = InputPress) const;
      /**
       * @brief  �A�i���O�X�e�B�b�N�̓��͏�Ԃ��擾
       * @brief  stick ���E�ǂ���̃A�i���O�X�e�B�b�N�̓��͂��擾���邩
       *               false:���X�e�B�b�N�@true:�E�X�e�B�b�N
       * @return first:�����̓��͏�� second:�c���̓��͏��
       */
      std::pair<int, int> GetStick(const bool stick) const;
      /**
       * @brief  ���E�g���K�[�{�^���̓��͏�Ԃ��擾
       * @return first:���g���K�[ second:�E�g���K�[
       */
      inline std::pair<int, int> GetTrigger() const {
        return std::make_pair(_press.LeftTrigger, _press.RightTrigger);
      }
    private:
      int _id; //!< �W���C�p�b�h�̎��ʔԍ�
      XINPUT_STATE _press;   //!< ���͏��(��������)
      XINPUT_STATE _trigger; //!< ���͏��(�g���K����)
      /**
       * @brief  �g���K���̐���
       * @param  press �ΏۃL�[�̉������
       * @param  old   �ΏۃL�[�̉������(�O�t���[��)
       * @return �ΏۃL�[�̃g���K���
       */
      inline int Trigger(const int press, const int old) {
        return press ^ old & press;
      }
    };
  } // namespace Application
} // namespace AppFrame