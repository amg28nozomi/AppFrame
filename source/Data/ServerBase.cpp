#include "ServerBase.h"
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
    bool ServerBase<T, I>::Init() {
      _registry.clear();
      return true;
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

    template <typename T, typename I>
    bool ServerBase<T, I>::IsTarget(FileServer::FileBase file, std::string_view extension) const {
      // �L�[�Ɏg�p���镶����ƃt�@�C���p�X
      auto [key, path] = file.GetFileData();
      // �g���q�Ɏw��͂��邩�H
      if (!extension.empty()) {
        // �g���q�͑Ή����Ă��邩�H
        if (path.stem() != extension.data()) {
#ifdef _DEBUG
          throw LogicError(file.GetFileName() + ":�g���q���قȂ�܂�");
#endif
          return false; // �t�@�C���`�����قȂ�
        }
      }
      // �t�@�C���͑��݂��邩
      if (!std::filesystem::exists(path)) {
#ifdef _DEBUG
        throw LogicError(file.GetFileName() + ":�p�X���L���ł͂���܂���");
#endif
        return false; // �p�X���L���ł͂Ȃ�
      }
      // �L�[�͎g�p����Ă��Ȃ���
      if (_registry.contains(key.data())) {
#ifdef _DEBUG
        throw LogicError(file.GetFileName() + ":�L�[���d�����Ă��܂�");
#endif
        return false; // �L�[���d�����Ă���
      }
      return true;  // �^�[�Q�b�g�ł���
    }

    template <typename T, typename I>
    bool ServerBase<T, I>::Exist(std::filesystem::path filePath) const {
      // �t�@�C���͑��݂��邩
      auto flag = std::filesystem::exists(filePath);
#ifdef _DEBUG
      if (!flag) {
        // �t�@�C�������݂��Ȃ��ꍇ
        throw LogicError(filePath.string() + ":�t�@�C�������݂��܂���");
      }
#endif
      return flag;
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