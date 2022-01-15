/*****************************************************************//**
 * @file   InputOperation.h
 * @brief  ���͏����N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <string>
#include <vector>
#include <future>
#include "JoypadState.h"

namespace AppFrame {
  namespace Application {
    // �f�o�C�X�^�C�v(���͏�Ԃ̎擾�Ŏg�p)
    constexpr auto DeviceKeyboard = 0; //!< �L�[�{�[�h
    constexpr auto DeviceMouse = 1;    //!< �}�E�X
    constexpr auto DeviceJoypad = 2;   //!< �W���C�p�b�h
    /**
     * @class InputOperation
     * @brief ���͏���
     */
    class InputOperation {
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
      InputOperation(class ApplicationBase& app);
      /**
       * @brief �f�X�g���N�^
       */
      ~InputOperation();
      /**
       * @brief �X�V����
       */
      void Process();
      /**
       * @brief  ���̓f�o�C�X�̓o�^
       * @return true:�ǉ����� false:�ǉ����s
       */
      bool AddJoypad();
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
      /**
       * @brief  �W���C�p�b�h�̉������擾
       * @return �W���C�p�b�h�̉������
       */
      bool JoypadInputButtons(const int id) const;
    private:
      ApplicationBase& _app; //!< �A�v���P�[�V�����̎Q��
      State _state{};        //!< ���
      JoypadState _joypad;  //!< �W���C�p�b�h�̓��͏��
      int _accessLimit{0};   //!< �f�o�C�X�̐ڑ����
    };
  } // namespace Application
} // namespace AppFrame