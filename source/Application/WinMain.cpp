/*****************************************************************//**
 * @file   WinMain.cpp
 * @brief  �v���O�����̃G���g���[�|�C���g
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#include "ApplicationBase.h"
#include <DxLib.h>

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
  namespace App = AppFrame::Application;
  // �A�v���P�[�V�����̎��̂��擾
  auto app = App::ApplicationBase::GetInstance();
  // ���̂͂��邩
  if (app == nullptr) {
    return -1; // ���̂���
  }
  // �������ɐ��������ꍇ�̂݃Q�[���Ɉڍs
  if (app->Init()) { 
    app->Run();
  }
  // �A�v���P�[�V�����I��
  app->Terminate();
  return 0;
}