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
       * @param id �p�b�h�̎��ʎq
       */
      JoypadState(const int id = 0);
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
       * @brief  �������̎擾
       * @return �������
       */
      XINPUT_STATE GetPress() const {
        return _press;
      }
      /**
       * @brief  �g���K���͂̎擾
       * @return �g���K����
       */
      XINPUT_STATE GetTrigger() const {
        return _trigger;
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