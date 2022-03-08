/*****************************************************************//**
 * @file   ModeBase.cpp
 * @brief  モードの基底クラスの定義
 * 
 * @author 鈴木希海
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
      // 経過時間の初期化
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
      ++_count; // カウンタの経過
    }

    bool ModeBase::PlayBgm(std::string_view key, const int volume) {
      // BGMの再生に成功したか
      if (!_app.GetSoundComponent().PlayLoop(key.data())) {
        return false; // 再生失敗
      }
      // 音量を設定する
      _app.GetSoundComponent().SetVolume(key.data(), volume);
      // 再生した音声に紐づけた文字列をセットする
      _bgm = key.data();
      return true;
    }
  } // namespace Mode
} // namespace AppFrame