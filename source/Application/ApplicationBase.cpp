/*****************************************************************//**
 * @file   ApplicationBase.cpp
 * @brief  �A�v���P�[�V�����̃X�[�p�[�N���X�̒�`
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "ApplicationBase.h"

namespace AppFrame {
  namespace App {
    
    ApplicationBase::ApplicationBase() {
      // �E�B���h�E���̐ݒ�
      auto&& [width, height, bit] = _window;
      width = WINDOW_W;
      height = WINDOW_H;
      bit = WINDOW_B;
      // �����t���O�̓o�^
      if (!_instance) {
#ifdef _DEBUG

#endif
      }

    }

    ApplicationBase::~ApplicationBase() {

    }
  } // namespace App
} // namespace AppFrame
