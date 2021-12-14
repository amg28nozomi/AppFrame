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
        return false;
      }
      SetBackgroundColor(0, 0, 255);
      SetDrawScreen(DX_SCREEN_BACK);
      // Z�o�b�t�@�̐ݒ�
      SetUseZBuffer3D(TRUE);
      SetWriteZBuffer3D(TRUE);
      return true;
    }

    void ApplicationBase::SetWindowSize(int width, int height, bool bit) {
      // �𑜓x���̐ݒ�
      auto&& [sizeX, sizeY, colorBit] = _window;
      sizeX = std::clamp(width, WidthMin, WindowWidth);
      sizeY = std::clamp(width, HeightMin, WindowHeight);
      if (bit) {
        colorBit = ColorBit32;
      }
      else {
        colorBit = ColorBit16;
      }
      SetGraphMode(sizeX, sizeY, colorBit);
    }
  } // namespace App
} // namespace AppFrame