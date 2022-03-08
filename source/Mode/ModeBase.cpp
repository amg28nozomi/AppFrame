/*****************************************************************//**
 * @file   ModeBase.cpp
 * @brief  ���[�h�̊��N���X�̒�`
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "ModeBase.h"
#include <time.h>
#include "ModeServer.h"
#include "../Application/ApplicationBase.h"
#include "../FileServer/FileServer.h"
#include "../SoundServer/SoundComponent.h"

namespace AppFrame {
  namespace Mode {

    ModeBase::ModeBase(Application::ApplicationBase& app) : _app(app) {
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

    bool ModeBase::Input(Application::InputOperation& input) {
      return true;
    }

    bool ModeBase::Process() {
      return true;
    }

    bool ModeBase::Draw() const {
      return true;
    }

    void ModeBase::TimeClear() {
      // �o�ߎ��Ԃ̏�����
      _count = 0;
    }

    Application::ApplicationBase& ModeBase::GetApplication() {
      return _app;
    }

    ModeServer& ModeBase::GetModeServer() {
      return _app.GetModeServer();
    }

    FileServer::FileServer& ModeBase::GetFileServer() {
      return _app.GetFileServer();
    }

    void ModeBase::StepTime() {
      ++_count; // �J�E���^�̌o��
    }

    bool ModeBase::PlayBgm(std::string_view key, const int volume) {
      // BGM�̍Đ��ɐ���������
      if (!_app.GetSoundComponent().PlayLoop(key.data())) {
        return false; // �Đ����s
      }
      // ���ʂ�ݒ肷��
      _app.GetSoundComponent().SetVolume(key.data(), volume);
      // �Đ����������ɕR�Â�����������Z�b�g����
      _bgm = key.data();
      return true;
    }
  } // namespace Mode
} // namespace AppFrame