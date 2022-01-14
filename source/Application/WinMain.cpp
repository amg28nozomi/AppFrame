/*****************************************************************//**
 * @file   WinMain.cpp
 * @brief  
 * 
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#include "ApplicationBase.h"
#include <DxLib.h>

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
  namespace App = AppFrame::Application;
  // アプリケーションの取得
  auto app = App::ApplicationBase::GetApplication();
  if (app == nullptr) {
    return -1; // 実態がない
  }
  // 初期化に失敗した場合はプログラム終了
  if (!app->Init()) { 
    return -1; 
  }
  // 終了状態に移行するまで処理を継続
  while (app->GameEnd()) {
    app->Run();
  }
  app->Release(); // 解放
  return 0;
}