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
      virtual bool Process() = 0;
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
      bool _active{true}; //!< �L�����ǂ���
    };
  } // Application
} // AppFrame