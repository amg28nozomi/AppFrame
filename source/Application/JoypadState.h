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

namespace AppFrame {
  namespace Application {
    /**
     * @class JoypadState
     * @brief �W���C�p�b�h�̓��͏��(XInput)
     */
    class JoypadState : public InputBase {
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
      /**
       * @brief  �������̎擾
       * @return �������
       */
      inline const int GetPress() const {
        return _press;
      }
      /**
       * @brief  �g���K���̎擾
       * @return �g���K���
       */
      inline const int GetTrigger() const {
        return _trigger;
      }
      /**
       * @brief  ���͏��̎擾
       * @return ������� �g���K���
       */
      inline const std::pair<int, int> GetInput() const {
        return std::make_pair(_press, _trigger);
      }
      /**
       * @brief  �A�i���O�X�e�B�b�N�̓��͏�Ԃ̎擾
       * @return X���̓��͏�� y���̓��͏��
       */
      inline const std::pair<int, int> GetLever() const {
        return std::make_pair(_leverX, _leverY);
      }
    private:
      int _id{0};      //!< ���ʔԍ�
      int _leverX{0};  //!< �A�i���O�X�e�B�b�N�̓��͏��(�c)
      int _leverY{0};  //!< �A�i���O�X�e�B�b�N�̓��͏��(��)
    };
  } // namespace Application
} // namespace AppFrame