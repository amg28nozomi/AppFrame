/*****************************************************************//**
 * @file   FileServer.cpp
 * @brief  �t�@�C���f�[�^���Ǘ�����T�[�o�N���X�̒�`
 *
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "FileServer.h"
#include <stdexcept>
#include <Windows.h>
#include "FileBase.h"
#include "LoadJson.h"

namespace {
  constexpr auto LOG_TEXT = "FileWorkerLog.txt"; // ���O�p�t�@�C����
}

namespace AppFrame {
  namespace FileServer {

    FileServer::FileServer() : _debugLog(LOG_TEXT) {
      _debug = true;
      _fileMap.clear();
#ifdef _DEBUG
      _debugLog = FileOutput(LOG_TEXT);
#endif
      Release();
    }

    FileServer::~FileServer() {
      Release();
    }

    bool FileServer::Init() {
      Release();
      return true;
    }

    void FileServer::Release() {
      _fileMap.clear(); // ���
    }

    bool FileServer::LoadFileMap(std::filesystem::path jsonPath) {
#ifdef _DEBUG
      auto stringPath = jsonPath.string();
#endif
      // �Ώۃt�@�C���͑��݂��Ă��邩
      if (!std::filesystem::exists(jsonPath)) {
#ifdef _DEBUG
        const std::string message(stringPath + ":�p�X���s���ł�");
        DebugStringLog(message);
#endif
        return false; // �p�X���s��
      }
      // �Ώۂ�json�t�@�C�����̔���
      if (!LoadJson::IsJson(jsonPath)) {
#ifdef _DEBUG
        const std::string message(stringPath + ":�Ώۂ�json�t�@�C���ł͂���܂���");
        DebugStringLog(message);
#endif
        return false; // �t�@�C���`�����قȂ�
      }
      auto fileMap = LoadJson::LoadJsonFile(jsonPath); // �t�@�C�����
      if (fileMap.empty()) {
        return false; // �t�@�C����񂪋�
      }
      auto counter = 0; // �o�^���s��
      // �擾�����t�@�C�����̓o�^
      for (auto [key, value] : fileMap) {
        if (_fileMap.contains(key)) {
#ifdef _DEBUG
          const std::string message = "�L�[:" + key + "�͊��ɓo�^����Ă��܂�";
          DebugStringLog(message);
#endif
          ++counter;
          continue;
        }
        _fileMap.emplace(key, value);
      }
#ifdef _DEBUG
      // �r���A�o�^�����Ɏ��s�������H
      if (counter) {
        const std::string message(counter + "�񏈗��Ɏ��s���܂���");
        DebugStringLog(message);
      }
#endif
      return true; // �o�^�I��
    }

    bool FileServer::SetLogTextFlag(bool flag, std::filesystem::path logPath) {
      return true;
    }

    bool FileServer::LoadFileMap(FileBaseMap& fileMap) {
      return true;
    }

    bool FileServer::FileCheck(const std::filesystem::path path) {
      return true;
    }

#ifdef _DEBUG
    void FileServer::DebugStringLog(const std::string text) {
      // ���O�ւ̏o��
      std::string message("FileServer:" + text + "\n");
      OutputDebugString(message.data());
      if (!_debug) {
        return;
      }
      // �e�L�X�g�t�@�C���ւ̏o��
      _debugLog.OutputText(text);
    }
#endif
  } // namespace FileServer
} // namespace AppFrame