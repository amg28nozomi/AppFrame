/*****************************************************************//**
 * @file   ModeFadeIn.cpp
 * @brief  ���[�h�t�F�[�h�̃T�u�N���X
 *         ���[�h�J�ڎ��̃t�F�[�h�C���������s��
 *
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#include "ModeFadeIn.h"
#include "../Data/Color.h"

namespace AppFrame{
  namespace Mode {
    ModeFadeIn::ModeFadeIn(Application::ApplicationBase& app, Data::Color color) : ModeFade(app, color) {
    }

    bool ModeFadeIn::Enter() {
      // �e��p�����[�^�̏�����
      _alpha = AlphaMax;
      _deltaAlpha = -AlphaDelta;
    }

    bool ModeFadeIn::Process() {
      // �A���t�@�l�̉��Z
      _alpha += _deltaAlpha;
      // �t�F�[�h�C�������̏I������
      if (IsFinish()) {
        return true;
      }
      return false;
    }

    bool ModeFadeIn::IsFinish() {
      // �A���t�@�l�͉����ȉ���
      return _alpha <= AlphaMin;
    }
  } // namespace Mode
} // namespace AppFrame