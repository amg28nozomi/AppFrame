/*****************************************************************//**
 * @file   Operation.h
 * @brief  ���͏����N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <string>
#include <vector>
#include <future>

namespace AppFrame {
  namespace Application {
    // �f�o�C�X�^�C�v(���͏�Ԃ̎擾�Ŏg�p)
    constexpr auto DeviceKeyboard = 0; //!< �L�[�{�[�h
    constexpr auto DeviceMouse = 1;    //!< �}�E�X
    constexpr auto DeviceJoypad = 2;   //!< �W���C�p�b�h
    /**
     * @class Operation
     * @brief ���͏���
     */
    class Operation {
    public:
      /**
       * @brief ���s���
       */
      enum class State {
        Active,   // ����
        Paused,   // �ꎞ��~
        NonActive // �ڑ��Ȃ�
      };
      /**
       * @brief �R���X�g���N�^
       * @param app �A�v���P�[�V�����̎Q��
       */
      Operation(class ApplicationBase& app);
      /**
       * @brief �f�X�g���N�^
       */
      ~Operation();
      /**
       * @brief �X�V����
       */
      void Process();
      /**
       * @brief  ���̓f�o�C�X�̒ǉ�
       * @param  device ���̓f�o�C�X�̎Q��
       * @return true:�ǉ����� false:�ǉ����s
       */
      bool AddDevice(class InputBase& device);
      /**
       * @brief  �w�肵���f�o�C�X�̎擾
       * @param  type �f�o�C�X�^�C�v(0:�L�[�{�[�h  1:�}�E�X  2:�W���C�p�b�h)
       * @param  number �W���C�p�b�h�ԍ�(�f�t�H���g�ł�0)
       * @return ���͏�Ԃ̎Q��
       * @throw  std::logic_error
       */
      InputBase& GetDevice(int type, int number = 0);
      /**
       * @brief  ���̓f�o�C�X���ڑ�����Ă��邩�̔���
       * @return true:�ڑ�����@false:�ڑ��Ȃ�
       */
      const bool IsConnection();
      /**
       * @brief  ���s��Ԃ̎擾
       * @return ���s���
       */
      const State OperationState() const {
        return _state;
      }
    private:
      ApplicationBase& _app;     //!< �A�v���P�[�V�����̎Q��
      State _state{};            //!< ���
      std::vector<InputBase> _devices; //!< ���̓f�o�C�X
      int _access{0}; //!< �ڑ���
      /**
       * @brief  �W���C�p�b�h�̍Đڑ�����
       * @return true:�Đڑ����� false:�ڑ�����
       */
      /*std::future<bool> ReConnect();*/
    };
  } // namespace Application
} // namespace AppFrame