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
#include <stdexcept>
#include <DxLib.h>
#include "FileWorker/FileServer.h"

namespace {
  constexpr auto WidthMin = 640;
  constexpr auto HeightMin = 480;

  constexpr auto InitError = -1; // ���������s
}

namespace AppFrame {
  namespace App {
    
    ApplicationBase::ApplicationBase() {
#ifdef _DEBUG
      _windowMode = false;
#endif
#ifndef _DEBUG
      _windowMode = true;
#endif
      _fileServer = nullptr;
    }

    ApplicationBase::~ApplicationBase() {
    }

    bool ApplicationBase::Init() {
      SetWindowSize(WindowWidth, WindowHeight);
      ChangeWindowMode(true);
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
      _fileServer = std::make_unique<FileWorker::FileServer>();

      auto flag = false; // �������t���O
#ifndef _DEBUG
      // �t�@�C���T�[�o�̏�����
      // �������Ɏ��s�����ꍇ�͑Ή������G���[�𔭎�
      flag = _fileServer->Init();
#else
      try {
        flag = _fileServer->Init();
      }
      catch (std::logic_error error) {
        OutputDebugString(error.what());
      }
#endif
      if (!flag) {
        return false; // ���������s
      }
      return true;    // ����������
    }

    void ApplicationBase::SetWindowSize(int width, int height, bool bit) {
      // ��ʉ𑜓x�̐ݒ�
      auto&& [sizeX, sizeY, bitColor] = _window;
      sizeX = std::clamp(width, WidthMin, WindowWidth);
      sizeY = std::clamp(width, HeightMin, WindowHeight);
      if (bit) {
        bitColor = BitColor32;
      }
      else {
        bitColor = BitColor16;
      }
      SetGraphMode(sizeX, sizeY, bitColor);
    }
  } // namespace App
} // namespace AppFrame