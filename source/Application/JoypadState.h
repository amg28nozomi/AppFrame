/*****************************************************************//**
 * @file   JoypadState.h
 * @brief  �W���C�p�b�h�̓��͏�ԃN���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <DxLib.h>
#include <tuple>

namespace AppFrame {
  namespace Application {
    /**
     * @class JoypadState
     * @brief �W���C�p�b�h�̓��͏��(XInput)
     */
    class JoypadState {
    public:
      /**
       * @brief �R���X�g���N�^
       */
      JoypadState();
      /**
       * @brief �f�X�g���N�^
       */
      ~JoypadState();
      /**
       * @brief  ���͏�Ԃ̍X�V
       * @return �X�V�ɐ��������ꍇ��true
       *         ���s�����ꍇ��false��Ԃ�
       */
      bool Process();
      /**
       * @brief  ���ڑ����̎擾
       * @return ���ڑ���
       */
      static inline const int ConnectJpypad() {
        return _connection;
      }
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
      static int _connection; //!< ���ڑ���
      int _id;                //!< ���ʔԍ�
      int _press;             //!< �������
      int _trigger;           //!< �g���K���
      int _leverX;            //!< �A�i���O�X�e�B�b�N�̓��͏��(�c)
      int _leverY;            //!< �A�i���O�X�e�B�b�N�̓��͏��(��)
    };
  } // namespace Application
} // namespace AppFrame