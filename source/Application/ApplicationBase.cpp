/*****************************************************************//**
 * @file   ApplicationBase.cpp
 * @brief  アプリケーションのスーパークラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "ApplicationBase.h"
#include <string>
#include <algorithm>
#include <stdexcept>
#include <DxLib.h>

namespace {
  constexpr auto WIDTH_MIN = 640;
  constexpr auto HEIGHT_MIN = 480;

  constexpr auto INIT_ERROR = -1; // 初期化失敗
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
      SetWindowSize(WINDOW_W, WINDOW_H);
      ChangeWindowMode(true);
      if (DxLib::DxLib_Init() == INIT_ERROR) {
#ifdef _DEBUG
        throw std::logic_error("ApplicationBase:DXライブラリの初期化に失敗しました\n");
#endif
        return false;
      }
      SetBackgroundColor(0, 0, 255);
      SetDrawScreen(DX_SCREEN_BACK);
      // Zバッファの設定
      SetUseZBuffer3D(TRUE);
      SetWriteZBuffer3D(TRUE);
      return true;
    }

    void ApplicationBase::SetWindowSize(int width, int height, bool bit) {
      // 解像度情報の設定
      auto&& [sizeX, sizeY, colorBit] = _window;
      sizeX = std::clamp(width, WIDTH_MIN, WINDOW_W);
      sizeY = std::clamp(width, HEIGHT_MIN, WINDOW_H);
      if (bit) {
        colorBit = COLOR_BIT_32;
      }
      else {
        colorBit = COLOR_BIT_16;
      }
      SetGraphMode(sizeX, sizeY, colorBit);
    }
  } // namespace App
} // namespace AppFrame
