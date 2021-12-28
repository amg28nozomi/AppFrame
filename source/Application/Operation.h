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
       * @brief  ���s��Ԃ̎擾
       * @return ���s���
       */
      const State OperationState() const {
        return _state;
      }
    private:
      ApplicationBase& _app; //!< �A�v���P�[�V����
      State _state{}; //!< ���
      std::vector<class JoypadState> _joypads; //!< �ڑ�����Ă���W���C�p�b�h
      /**
       * @brief  ���̓f�o�C�X���ڑ�����Ă��邩�̔���
       * @return true:�ڑ�����@false:�ڑ��Ȃ�
       */
      const bool IsConnection() const;
      /**
       * @brief  �W���C�p�b�h�̍Đڑ�����
       * @return true:�Đڑ����� false:�ڑ�����
       */
      /*std::future<bool> ReConnect();*/
    };
  } // namespace Application
} // namespace AppFrame