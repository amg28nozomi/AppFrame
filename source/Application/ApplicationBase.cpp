/*****************************************************************//**
 * @file   ApplicationBase.cpp
 * @brief  �A�v���P�[�V�����̃X�[�p�[�N���X�̒�`
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "ApplicationBase.h"
#include <string>
#include <algorithm>
#ifdef _DEBUG
#include <stdexcept>
#endif
#include "EffekseerForDXLib.h"
#include "InputOperation.h"
#include "../FileServer/FileServer.h"
#include "../FileServer/FileBase.h"
#include "../Mode/ModeBase.h"
#include "../Mode/ModeFadeIn.h"

namespace {
  constexpr auto WidthMin = 640;
  constexpr auto HeightMin = 480;

  constexpr auto InitError = -1; // ���������s
}

namespace AppFrame {
  namespace Application {
    ApplicationBase::ApplicationBase() {
      _particleMax = 4000;
#ifndef _DEBUG
      _windowMode = false;
#else
      _windowMode = true;
#endif
      // ���O�t�@�C���̏o�͂��s�����̐ݒ�
      SetOutApplicationLogValidFlag(_windowMode);
    }

    ApplicationBase::~ApplicationBase() {
    }

    bool ApplicationBase::SetInstance() {
      // ���Ԃ��o�^����Ă��邩�̔���
      if (!_setInstance) {
        if (_instance == nullptr) {
          _setInstance = true; 
          return true; // �o�^���s��
        }
      }
      return false; // �o�^�ς�
    }

    bool ApplicationBase::Init() {
      // �e�평�������s
      SetWindowSize(WindowWidth, WindowHeight);
      ChangeWindowMode(_windowMode);
      // DX���C�u�����̏�����
      if (DxLib::DxLib_Init() == InitError) {
#ifdef _DEBUG
        throw std::logic_error("ApplicationBase:DX���C�u�����̏������Ɏ��s���܂���\n");
#endif
        return false; // ���������s
      }
      SetBackgroundColor(0, 0, 255);
      SetDrawScreen(DX_SCREEN_BACK);
      // Z�o�b�t�@�̐ݒ�
      SetZBuffer();
      // �t�@�C���T�[�o�̐���
      _fileServer = std::make_unique<FileServer::FileServer>();
      // �C���v�b�g�I�y���[�V�����̐���
      _input = std::make_unique<InputOperation>(*this);
      // ���[�h�T�[�o�̐���
      _modeServer = std::make_unique<Mode::ModeServer>("base", std::make_unique<Mode::ModeFadeIn>(*this));
      // �T�E���h�T�[�o�̐���
      _soundServer = std::make_unique<Sound::SoundServer>();
#ifndef _DEBUG
      if (!_fileServer->Init()) {
        return false; // ���������s
      }
#else
      try {
        // �t�@�C���T�[�o�̏�����
        // �������Ɏ��s�����ꍇ�͑Ή������G���[�𔭎�
        _fileServer->Init();
      }
      catch (std::logic_error error) {
        OutputDebugString(error.what());
        return false; // ���������s
      }
#endif
      return true;    // ����������
    }

    void ApplicationBase::Release() {
      DxLib_End();
    }

    void ApplicationBase::Run() {
      // ���C�����[�v
      while (_state != State::Quit) {
#ifndef _DEBUG
        Input();   // ����
        Process(); // �X�V
        Draw();    // �`��
#else
        try {
          Input();   // ����
          Process(); // �X�V
          Draw();    // �`��
        } catch (std::logic_error error) {
          // ��O�������A�o�͂��s��
          OutputDebugString(error.what());
        }
#endif
      }
    }

    bool ApplicationBase::Input() {
      IsQuit();          // �I������
      _input->Process(); // ���͏�Ԃ̍X�V
      return true;
    }

    bool ApplicationBase::Process() {
      // ���[�h�T�[�o�̍X�V���������s
      _modeServer->Process();
      return true;
    }

    bool ApplicationBase::Draw() {
      ClearDrawScreen();   // ��ʂ��N���A
      _modeServer->Draw(); // ���[�h�T�[�o�̕`�揈�����s
      ScreenFlip();        // ����ʂ̓��e��\��ʂɔ��f
      return true;
    }

    void ApplicationBase::Terminate() {
      // DX���C�u�����̏I��
      DxLib_End();
    }

    void ApplicationBase::RequestTerminate() {
      // �A�v���P�[�V�������I����Ԃł͂Ȃ��ꍇ
      if (_state != State::Quit) {
        _state = State::Quit;
      }
    }

    void ApplicationBase::SetWindowSize(int width, int height, bool bit) {
      // ��ʉ𑜓x�̐ݒ�
      _width = std::clamp(width, WidthMin, WindowWidth);
      _height = std::clamp(width, HeightMin, WindowHeight);
      if (bit) {
        _colorBit = BitColor32;
      }
      else {
        _colorBit = BitColor16;
      }
      SetGraphMode(_width, _height, _colorBit);
    }

    void ApplicationBase::SetZBuffer(bool flag) {
      // Z�o�b�t�@���g�p���邩�̐ݒ�
      SetUseZBuffer3D(flag);
      SetWriteZBuffer3D(flag);
    }

    void ApplicationBase::IsQuit() {
      // ���b�Z�[�W���[�v�Ɏ��s�����ꍇ�͏I��
      if (ProcessMessage() == Error) {
        _state = State::Quit; // �I����ԂɑJ��
      }
    }
  } // namespace Application
} // namespace AppFrame