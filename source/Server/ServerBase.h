/*****************************************************************//**
 * @file   ServerBase.h
 * @brief  �T�[�o�̊��N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#ifdef _DEBUG
#include <stdexcept>
#include <Windows.h>
#endif
/**
 * @brief �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief �T�[�o�x�[�X
   */
  namespace Server {
    /**
     * @class ServerBase
     * @brief �T�[�o�̃e���v���[�g
     */
    template <typename T>
    class ServerBase {
    public:
      /**
       * @brief �T�[�o�̏�Ԃ�\���񋓌^�N���X
       */
      enum class ServerState {
        Active, // ����
        Paused, // ��~
        Error   // �ُ�
      };
      /**
       * @brief �R���X�g���N�^
       */
      ServerBase();
      /**
       * @brief �f�X�g���N�^
       */
      virtual ~ServerBase() = default;
      /**
       * @brief  ������
       * @return true:���������� false:���������s
       */
      virtual bool Init();
      /**
       * @brief  �ێ����Ă��郊�\�[�X�̉������
       *         �h����ŕK���Ē�`���s��
       * @return true:������� false:��蔭��
       */
      virtual bool Release() = 0;
    protected:
      ServerState _state; //!< ���
      T _registry{};      //!< �f�[�^�x�[�X
#ifdef _DEBUG
      std::string _name;  //!< �T�[�o��
      /**
       * @brief �f�o�b�O�����Ŏg�p����T�[�o���̐ݒ�
       * @param name �T�[�o��
       */
      void SetServerName(std::string_view name);
      /**
       * @brief  logic_error�̐���
       * @param  message �o�͂��镶����
       * @return logic_error
       */
      virtual std::logic_error LogicError(std::string_view message) const;
      /**
       * @brief �f�o�b�O�p���b�Z�[�W�̏o��
       * @param message �f�o�b�O�p�̕�����
       */
      virtual void DebugString(std::string_view message) const;
#endif
    };
    /**
     * @brief �R���X�g���N�^�̒�`
     */
    template <typename T>
    ServerBase<T>::ServerBase() {
      _state = ServerState::Active;
    }
    /**
     * @brief �������̒�`
     */
    template <typename T>
    bool ServerBase<T>::Init() {
#ifndef _DEBUG
      // ���\�[�X�̉�������ɐ���������
      if (!Release()) {
        _state = ServerState::Error;
        return false; // ���s
      }
      return true;    //����I��
#else
      bool flag;
      try {
        flag = Release(); // ���\�[�X�̉��
      }
      catch (std::logic_error error) {
        // ��O��catch�����ꍇ�́A�o�͂��s��
        DebugString(error.what());
      }
      // ����Ɏ��s�����ꍇ�̓G���[��ԂɑJ�ڂ���
      if (!flag) {
        _state = ServerState::Error;
      }
      return flag;
#endif
    }

#ifdef _DEBUG
    template <typename T>
    void ServerBase<T>::SetServerName(std::string_view name) {
      _name = name.data(); // �����̕�������T�[�o���Ƃ��Ďg�p����
    }

    template <typename T>
    std::logic_error ServerBase<T>::LogicError(std::string_view message) const {
      std::string error = _name + ":" + message.data() + "\n";
      return std::logic_error(error);
    }

    template <typename T>
    void ServerBase<T>::DebugString(std::string_view message) const {
      // �f�o�b�O�E�B���h�E�ɏo�͂���
      OutputDebugString(message.data());
    }
#endif
  } // namespace Server
} // namespace AppFrame