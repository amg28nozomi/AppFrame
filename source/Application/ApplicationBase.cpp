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
#ifdef _DEBUG
#include <stdexcept>
#endif
#include "EffekseerForDXLib.h"
#include "InputOperation.h"
#include "../FileServer/FileServer.h"
#include "../FileServer/FileBase.h"

namespace {
  constexpr auto WidthMin = 640;
  constexpr auto HeightMin = 480;

  constexpr auto InitError = -1; // 初期化失敗
}

namespace AppFrame {
  namespace Application {
    ApplicationBase::ApplicationBase() {
      _particleMax = 4000;
#ifndef _DEBUG
      _windowMode = true;
#else
      _windowMode = false;
#endif
    }

    ApplicationBase::~ApplicationBase() {
    }

    bool ApplicationBase::SetInstance() {
      // 実態が登録されているかの判定
      if (!_setInstance) {
        if (_instance == nullptr) {
          _setInstance = true; 
          return true; // 登録を行う
        }
      }
      return false; // 登録済み
    }

    bool ApplicationBase::Init() {
      // 各種初期化実行
      SetWindowSize(WindowWidth, WindowHeight);
      ChangeWindowMode(_windowMode);
      // DXライブラリの初期化
      if (DxLib::DxLib_Init() == InitError) {
#ifdef _DEBUG
        throw std::logic_error("ApplicationBase:DXライブラリの初期化に失敗しました\n");
#endif
        return false; // 初期化失敗
      }
      SetBackgroundColor(0, 0, 255);
      SetDrawScreen(DX_SCREEN_BACK);
//      // Effekseerの初期化
//      if (Effekseer_Init(_particleMax) == InitError) {
//#ifdef _DEBUG
//        throw std::logic_error("ApplicationBase:Effekseerの初期化に失敗しました\n");
//#endif
//        return false; // 初期化失敗
//      }
      // Zバッファの設定
      SetUseZBuffer3D(TRUE);
      SetWriteZBuffer3D(TRUE);
      // ファイルサーバの生成
      _fileServer = std::make_unique<FileServer::FileServer>();
      // 

#ifndef _DEBUG
      if (!_fileServer->Init()) {
        return false; // 初期化失敗
      }
#else
      try {
        // ファイルサーバの初期化
        // 初期化に失敗した場合は対応したエラーを発射
        _fileServer->Init();
      }
      catch (std::logic_error error) {
        OutputDebugString(error.what());
        return false; // 初期化失敗
      }
#endif
      return true;    // 初期化成功
    }

    void ApplicationBase::Release() {
      DxLib_End();
    }

    void ApplicationBase::Run() {
      // メインループ
      while (_state != State::Quit) {
#ifndef _DEBUG
        Input();   // 入力
        Process(); // 更新
        Draw();    // 描画
#else
        try {
          Input();   // 入力
          Process(); // 更新
          Draw();    // 描画
        } catch (std::logic_error error) {
          // 例外発生時、出力を行う
          OutputDebugString(error.what());
        }
#endif
      }
    }

    bool ApplicationBase::Input() {
      IsQuit(); // 終了判定
      _input->Process(); // 入力状態の更新
      return true;
    }

    bool ApplicationBase::Process() {
      return true;
    }

    bool ApplicationBase::Draw() {
      return true;
    }

    void ApplicationBase::Terminate() {
      // DXライブラリの終了
      DxLib_End();
    }

    void ApplicationBase::SetWindowSize(int width, int height, bool bit) {
      // 画面解像度の設定
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

    void ApplicationBase::IsQuit() {
      // メッセージループに失敗した場合は終了
      if (ProcessMessage() == Error) {
        _state = State::Quit; // 終了状態に遷移
      }
    }
  } // namespace Application
} // namespace AppFrame