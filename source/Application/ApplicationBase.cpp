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
#include <DxLib.h>
#include "../FileServer/FileServer.h"
#include "../FileServer/FileBase.h"

namespace {
  constexpr auto WidthMin = 640;
  constexpr auto HeightMin = 480;

  constexpr auto InitError = -1; // ���������s
}

namespace AppFrame {
  namespace Application {
    ApplicationBase::ApplicationBase() {
#ifndef _DEBUG
      _windowMode = true;
#else
      _windowMode = false;
#endif
    }

    ApplicationBase::~ApplicationBase() {
    }

    bool ApplicationBase::SetInstance() {
      // ���Ԃ��o�^����Ă��邩�̔���
      if (!_setInstance) {
        if (_instance == nullptr) {
          return true; // �o�^���s��
        }
      }
      return false; // �o�^�ς�
    }

    bool ApplicationBase::Init() {
      // �e�평�������s
      SetWindowSize(WindowWidth, WindowHeight);
      ChangeWindowMode(_windowMode);
      // DX���C�u�����̏������ɐ���������
      if (DxLib::DxLib_Init() == InitError) {
#ifdef _DEBUG
        throw std::logic_error("ApplicationBase:DX���C�u�����̏������Ɏ��s���܂���\n");
#endif
        return false; // ���������s
      }
      SetBackgroundColor(0, 0, 255);
      SetDrawScreen(DX_SCREEN_BACK);
      // Z�o�b�t�@�̐ݒ�
      SetUseZBuffer3D(TRUE);
      SetWriteZBuffer3D(TRUE);
      // �t�@�C���T�[�o�̐���
      _fileServer = std::make_unique<FileServer::FileServer>();
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
      return true;
    }

    bool ApplicationBase::Process() {
      return true;
    }

    bool ApplicationBase::Draw() {
      return true;
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
  } // namespace Application
} // namespace AppFrame