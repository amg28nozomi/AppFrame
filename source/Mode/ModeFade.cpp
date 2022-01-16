/*****************************************************************//**
 * @file   ModeFade.cpp
 * @brief  ���[�h�x�[�X�̃T�u�N���X�̒�`
 *         �V�[���J�ڎ��̃t�F�[�h�������s��
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#include "ModeFade.h"
#include <DxLib.h>
#include "../Application/ApplicationBase.h"
#include "../Data/Color.h"

namespace AppFrame{
  namespace Mode {

    ModeFade::ModeFade(Application::ApplicationBase& app, const Data::Color color) : ModeBase(app) {
      // �J���[�l�̐ݒ�
      _basic = color;
      _color = _basic;
      // �E�B���h�E�T�C�Y�̎擾
      auto [width, height] = app.GetWindowSize();
      // �{�b�N�X�T�C�Y���E�B���h�E�T�C�Y�Ɠ����ɐݒ�
      _width = width;
      _height = height;
    }

    ModeFade::~ModeFade() {
    }

    bool ModeFade::Init() {
      _color = _basic;
      return true;
    }

    bool ModeFade::Enter() {
      return true;
    }

    bool ModeFade::Process() {
      return true;
    }

    bool ModeFade::Draw() const {
      // �u�����h���[�h�̐؂�ւ�
      SetDrawBlendMode(DX_BLENDMODE_ALPHA, _color.GetAlpha());
      // �t�F�[�h�����p�̃{�b�N�X��`��
      DrawBox(0, 0, _width, _height, _color.GetColorCode(), TRUE);
      // �u�����h���[�h���m�[�}���ɖ߂�
      SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    void ModeFade::SetColor(const Data::Color color) {
      // ���݂�RGB����ύX����
      _basic = color;
    }
  } // namespace Mode
} // namespace AppFrame