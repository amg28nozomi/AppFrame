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

    ModeServer::ModeServer(std::string_view key, std::shared_ptr<ModeBase> mode) {
      // �R���e�i�̏�����
      _registry.clear();
      _modes.clear();

    }

    bool ModeServer::Register(std::string_view key, std::shared_ptr<ModeBase> mode) {
      if (_registry.contains(key.data())) {
        _registry.erase(key.data());
      }
      // ���[�h�̓o�^
      _registry.emplace(key, mode);
      auto flag = false; // �������t���O
      // ���[�h�̏�����
#ifndef _DEBUG
      flag = mode->Init();
#else
      try {
        flag = mode->Init();
      } catch (std::logic_error error) {
        // �������������s
        OutputDebugString(error.what());
      }
#endif
      return flag;
    }

    bool ModeServer::Process() const {
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
          OutputDebugString(error.what());
        }
#endif
      }
      return flag;
    }
  } // namespace Mode
} // namespace AppFrame