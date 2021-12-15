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
#include "FileWorker/FileServer.h"

namespace {
  constexpr auto WidthMin = 640;
  constexpr auto HeightMin = 480;

  constexpr auto InitError = -1; // 初期化失敗
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
        throw std::logic_error("ApplicationBase:DXライブラリの初期化に失敗しました\n");
#endif
        return false; // 初期化失敗
      }
      SetBackgroundColor(0, 0, 255);
      SetDrawScreen(DX_SCREEN_BACK);
      // Zバッファの設定
      SetUseZBuffer3D(TRUE);
      SetWriteZBuffer3D(TRUE);
      // ファイルサーバの生成
      _fileServer = std::make_unique<FileWorker::FileServer>();

      auto flag = false; // 初期化フラグ
#ifndef _DEBUG
      // ファイルサーバの初期化
      // 初期化に失敗した場合は対応したエラーを発射
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
        return false; // 初期化失敗
      }
      return true;    // 初期化成功
    }

    void ApplicationBase::SetWindowSize(int width, int height, bool bit) {
      // 画面解像度の設定
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