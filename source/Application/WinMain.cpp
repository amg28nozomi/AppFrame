/*****************************************************************//**
 * @file   WinMain.cpp
 * @brief  プログラムのエントリーポイント
 * 
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#include "ApplicationBase.h"
#include <DxLib.h>

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
  namespace App = AppFrame::Application;
  // アプリケーションの実体を取得
  auto app = App::ApplicationBase::GetInstance();
  // 実体はあるか
  if (app == nullptr) {
    return -1; // 実体が空
  }
  // 初期化に成功した場合のみゲームに移行
  if (app->Init()) { 
    app->Run();
  }
  // アプリケーション終了
  app->Terminate();
  return 0;
}