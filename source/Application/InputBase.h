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
     * @class  InputBase
     * @brief  ���͏�ԃN���X
     * @tparam T ���͏�Ԃ������^
     */
    template <typename T>
    class InputBase {
    public:
      /**
       * @brief ���̓f�o�C�X�̎�ނ�\��
       */
      enum class Type {
        Joypad, //!< �W���C�p�b�h
        Mouse   //!< �}�E�X
      };
      /**
       * @brief ���̓f�o�C�X�̏�ԗp�񋓌^�N���X
       */
      enum class State {
        Active,   // �ڑ��L��
        NonActive // �ڑ�����
      };
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
       * @brief  �f�o�C�X�^�C�v�̎擾
       * @return �f�o�C�X�^�C�v
       */
      inline const Type GetType() const {
        return _type;
      }
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
      /**
       * @brief  �������̎擾
       * @return �������
       */
      virtual T GetKey() const;
      /**
       * @brief  �g���K���̎擾
       * @return �g���K���
       */
      virtual T GetTriggerKey() const;
    protected:
      static inline int _connection{0}; //!< ���ڑ���
      Type _type{};       //!< �f�o�C�X�̋@��
      State _state{ State::Active }; //!< ���
      T _press;           //!< �������
      T _trigger;         //!< �g���K���
      bool _active{true}; //!< �L�����ǂ���
    };
  } // Application
} // AppFrame