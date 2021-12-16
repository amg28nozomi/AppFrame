/*****************************************************************//**
 * @file   ModeBase.cpp
 * @brief  ���[�h�̊��N���X�̒�`
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "ModeBase.h"
#include "../Application/ApplicationBase.h"

namespace AppFrame {
  namespace Mode {

    ModeBase::ModeBase(App::ApplicationBase& app) : _app(app) {
    }

    ModeBase::~ModeBase() {
    }

    bool ModeBase::Init() {
      return true;
    }

    bool ModeBase::Enter() {
      return true;
    }

    bool ModeBase::Exit() {
      return true;
    }

    bool ModeBase::Process() {
      return true;
    }

    bool ModeBase::Draw() {
      return true;
    }
  }
}