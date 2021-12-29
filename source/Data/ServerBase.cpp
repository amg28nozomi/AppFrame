#include "ServerBase.h"
#include <filesystem>
#ifdef _DEBUG
#include <Windows.h>
#endif
#include "../FileServer/FileBase.h"

namespace AppFrame {
  namespace Data {

    template <typename T, typename I>
    ServerBase<T, I>::ServerBase() {
      _registry.clear();
#ifdef _DEBUG
      _name = "ServerBase";
#endif
    }

    template <typename T, typename I>
    bool ServerBase<T, I>::Register(std::string_view key, const I value) {
    }

    template <typename T, typename I>
    bool ServerBase<T, I>::LoadFiles(std::vector<FileServer::FileBase> files) {
      // �t�@�C���͑��݂��邩�H
      if (files.empty()) {
        return false; // �f�[�^����
      }
      for (auto file : files) {
        auto [key, path] = file.GetFileData();
        // �L�[�͊��ɓo�^����Ă��邩
        if (_registry.contains(key.data())) {
          continue; // �o�^�ς�
        }
        // �p�X�͗L����
        if (!std::filesystem::exists(path)) {
          continue; // �L���ł͂Ȃ�
        }
#ifndef _DEBUG
        Register(key, path); // �o�^�����Ɉڍs
#else
        try {
          Register(key, path);
        } catch (std::logic_error error) {
          // ��O������ꍇ�͏o��
          DebugString(error.what());
        }
#endif
      }
      return true; // �����I��
    }

    template <typename T, typename I>
    bool ServerBase<T, I>::KeySearch(std::string_view key) {
      return true;
    }

#ifdef _DEBUG
    template <typename T, typename I>
    std::logic_error ServerBase<T, I>::LogicError(std::string_view message) const {
      // �w�肵���`���ɏC��
      std::string m = _name + ":" + message + "\n";
      return std::logic_error(m);
    }

    template <typename T, typename I>
    void ServerBase<T, I>::DebugString(std::string_view message) {
      OutputDebugString(message.data());
    }
#endif
  } // namespace Data
} // namespace AppFrame