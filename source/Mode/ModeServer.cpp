/*****************************************************************//**
 * @file   ModeServer.cpp
 * @brief  
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "ModeServer.h"
#include <stdexcept>
#include <Windows.h>
#include "ModeBase.h"

namespace AppFrame {
  namespace Mode {

    ModeServer::ModeServer(std::string_view key, std::shared_ptr<ModeBase> mode) :
     Server::ServerTemplateUnordered<std::string, std::shared_ptr<ModeBase>>(){
      // �R���e�i�̏�����
      _registry.clear();
      _list.clear();
#ifdef _DEBUG
      _name = "FileServer";
#endif
    }

    bool ModeServer::Release() {
      // �o�^����Ă���S�V�[���̉�����s��
      for (auto mode : _list) {
        mode->Exit(); // �I�������Ăяo��
      }
      return false;
    }

    void ModeServer::AddMode(std::string_view key, std::shared_ptr<ModeBase> mode) {
      // �L�[���d�����Ă��邩
      if (!UsedKey(key.data())) {
        // �d�����Ă���ꍇ�͊��ɓo�^����Ă��郂�[�h���폜
        _registry.erase(key.data());
      }
      // ���[�h�̓o�^
      _registry.emplace(key.data(), mode);
#ifndef _DEBUG
      // ���[�h�̏�����
      mode->Init();
#else
      try {
        mode->Init();
      } catch (std::logic_error error) {
        // �������Ŗ�蔭��
        DebugString(error.what());
      }
#endif
    }

    bool ModeServer::Process() const {
      // ���[�h�̓X�^�b�N����Ă��邩
      if (_list.empty()) {
        return true; // ���o�^
      }
#ifndef _DEBUG
      return _list.back()->Process();
#else
      auto flag = true; // �����t���O
      try {
        flag = _list.back()->Process();
      } catch (std::logic_error error) {
        OutputDebugString(error.what());
      }
      return flag;
#endif
    }

    bool ModeServer::Draw() const {
      auto flag = true; // �����t���O
      // �X�^�b�N����Ă��郂�[�h�̕`��
      for (auto&& mode : _list) {
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
  } // namespace Mode
} // namespace AppFrame