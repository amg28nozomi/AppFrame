/*****************************************************************//**
 * @file   InputBase.h
 * @brief  ���͏�Ԃ̊��N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once

namespace AppFrame {
  namespace Application {
    constexpr auto ProcessError = -1; // �������s
    /**
     * @class InputBase
     * @brief ���͏�ԃN���X
     */
    class InputBase {
    public:
      /**
       * @brief  �R���X�g���N�^
       */
      InputBase();
      /**
       * @brief  �f�X�g���N�^
       */
      ~InputBase();
      /**
       * @brief  �X�V����
       */
      virtual void Process() = 0;
      /**
       * @brief  ���ڑ����̎擾
       * @return ���ڑ���
       */
      static inline int GetConnection() {
        return _connection;
      }
      /**
       * @brief  �L�����ǂ����̔���
       * @return true:�L�� false:��L��
       */
      bool IsActive() const {
        return _active;
      }
    protected:
      static inline int _connection{0}; //!< ���ڑ���
      int _press{0};   //!< �������
      int _trigger{0}; //!< �g���K���
      bool _active{true}; //!< �L�����ǂ���
      /**
       * @brief  �g���K���̍X�V
       * @param  old �O�t���[���̓��͏��
       */
      inline void Trigger(int old) {
        _trigger =  _press ^ old & _press;
      }
    };
  } // Application
} // AppFrame