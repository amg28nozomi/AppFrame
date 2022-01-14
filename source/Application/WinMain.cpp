/*****************************************************************//**
 * @file   WinMain.cpp
 * @brief  
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#include "ApplicationBase.h"
#include <DxLib.h>

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
  namespace App = AppFrame::Application;
  // �A�v���P�[�V�����̎擾
  auto app = App::ApplicationBase::GetApplication();
  if (app == nullptr) {
    return -1; // ���Ԃ��Ȃ�
  }
  // �������Ɏ��s�����ꍇ�̓v���O�����I��
  if (!app->Init()) { 
    return -1; 
  }
  // �I����ԂɈڍs����܂ŏ������p��
  while (app->GameEnd()) {
    app->Run();
  }
  app->Release(); // ���
  return 0;
}