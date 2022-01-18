/*****************************************************************//**
 * @file   ModeServer.cpp
 * @brief  �e�탂�[�h���Ǘ�����T�[�o�N���X�̒�`
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "ModeServer.h"
#include "ModeFadeIn.h"
#include "ModeFadeOut.h"

namespace {
  constexpr auto FadeIn = "FadeIn";   // �t�F�[�h�C���o�^�p�̃L�[
  constexpr auto FadeOut = "FadeOut"; // �t�F�[�h�A�E�g�o�^�p�̃L�[
}

namespace AppFrame {
  namespace Mode {

    ModeServer::ModeServer(std::string_view key, std::shared_ptr<ModeBase> mode) :
     Server::ServerTemplateUnordered<std::string, std::shared_ptr<ModeBase>>(){
      // �R���e�i�̏�����
      _registry.clear();
      _modes.clear();
#ifdef _DEBUG
      _name = "FileServer";
#endif
      // �e�탂�[�h�̓o�^
      Register(FadeIn, std::make_shared<ModeFadeIn>(mode->GetApplication()));
      Register(FadeOut, std::make_shared<ModeFadeOut>(mode->GetApplication()));
      Register(key.data(), mode);
    }

    bool ModeServer::Release() {
      // �o�^����Ă���S�V�[���̉�����s��
      for (auto mode : _modes) {
        mode->Exit(); // �I�������Ăяo��
      }
      return false;
    }

    void ModeServer::AddMode(std::string_view key, std::shared_ptr<ModeBase> mode) {
      Register(key.data(), mode);
    }

    bool ModeServer::PushBack(std::string_view key) {
      // ���[�h�̎擾
      auto mode = FetchMode(key.data());
      // ���[�h�̎擾�ɐ���������
      if (mode == nullptr) {
#ifdef _DEBUG
        throw LogicError("�ΏۃL�[���s���ł�");
#endif
        return false; // �L�[���s��
      }
      // ���X�g�̖����ɒǉ�
      _modes.push_back(mode);
      return true;
    }

    void ModeServer::PopBuck() {
      // ���[�h�͓o�^����Ă��邩
      if (_modes.empty()) {
        return; // ���[�h�����o�^
      }
      // �����̃��[�h���폜����
      _modes.back()->Exit();
      _modes.pop_back();
    }

    void ModeServer::InsertBeforeBack(std::string_view key) {
      auto mode = FetchMode(key.data());
      // �擾�ɐ���������
      if (mode == nullptr) {
        return;
      }
      _modes.insert(std::prev(_modes.end()), mode);
    }

    bool ModeServer::Process() {
      // ���[�h�̓X�^�b�N����Ă��邩
      if (_modes.empty()) {
        return true; // ���o�^
      }
#ifndef _DEBUG
      return _modes.back()->Process();
#else
      auto flag = true; // �����t���O
      try {
        flag = _modes.back()->Process();
      } catch (std::logic_error error) {
        OutputDebugString(error.what());
      }
      return flag;
#endif
    }

    bool ModeServer::Draw() const {
      auto flag = true; // �����t���O
      // �X�^�b�N����Ă��郂�[�h�̕`��
      for (auto&& mode : _modes) {
#ifndef _DEBUG
        // �`�揈���͐���I��������
        if (!mode->Draw()) {
          flag = false; // ��蔭��
        }
#else
        try {
          if (!mode->Draw()) {
            flag = false; 
          }
        } catch (std::logic_error error) {
          // ��O�����������ꍇ�̓��O�ɏo��
          DebugString(error.what());
        }
#endif
      }
      return flag;
    }

    bool ModeServer::Register(std::string key, std::shared_ptr<ModeBase> mode) {
      // �L�[�͓o�^���Ă��邩
      if (!UseKey(key)) {
        // �d�����Ă���ꍇ�͑Ώۂ��폜
        _registry.erase(key);
      }
      mode->Init();
      _registry.emplace(key, mode);
      return true;
    }

    std::shared_ptr<ModeBase> ModeServer::FetchMode(std::string_view key) {
      // ���[�h�͓o�^����Ă��邩
      if (!_registry.contains(key.data())) {
        return nullptr; // ���o�^
      }
      auto mode = _registry.at(key.data());
      mode->Enter(); // �������������s
      return mode;
    }

    bool ModeServer::TransionToMode(std::string_view key) {
      InsertBeforeBack(key);
      InsertBeforeBack(FadeIn);
      PushBack(FadeOut);
      return true;
    }
  } // namespace Mode
} // namespace AppFrame