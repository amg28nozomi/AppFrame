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
  constexpr auto ServerName = "FileServer";
  constexpr auto LogText = "FileWorkerLog.txt"; // ���O�p�t�@�C����
}

namespace AppFrame {
  namespace FileServer {

#ifndef _DEBUG
    FileServer::FileServer() : ServerBase() {
    }
#else
    FileServer::FileServer(std::filesystem::path filePath) : ServerBase(), _fileLog(filePath) {
      _name = ServerName;
    }
#endif

    FileServer::~FileServer() {
      Init();
    }

    bool FileServer::Init() {
      return ServerBase::Init();
    }

    bool FileServer::Release() {
      // �o�^����Ă���t�@�C�������ꊇ�폜����
      _registry.clear();
      return true;
    }
    // �ǉ�

    bool FileServer::Register(std::string_view key, const std::filesystem::path path) {
#ifndef _DEBUG
      // �Ώۂ͓o�^�\���H
      if (!IsTarget({key, path})) {
        return false;
      }
#else
      try {
        IsTarget((key, path));
      } catch (std::logic_error error) {
        DebugString(error.what());
        return false; // �o�^���s
      }
#endif
      _registry.emplace(key, path); // ���W�X�g���ɓo�^
      return true;
    }

    bool FileServer::LoadFiles(std::filesystem::path jsonPath) {
#ifndef _DEBUG
      // �p�X�͗L����
      if (!IsTarget(jsonPath, ".json")) {
        return false; // �ǂݎ��Ώۂł͂Ȃ�
      }
#else
      try {
        IsTarget(jsonPath, ".json");
      } catch (std::logic_error error) {
        DebugString(error.what());
        return false;
      }
#endif
      LoadJson::LoadJsonFile(jsonPath);
      
      return true;
    }



//    FileServer::FileServer() : _debugLog(LogText) {
//      _debug = true;
//      _fileMap.clear();
//#ifdef _DEBUG
//      _debugLog = FileOutput(LogText);
//#endif
//      Release();
//    }
//
//    FileServer::~FileServer() {
//      Release();
//    }
//
//    bool FileServer::Init() {
//      Release();
//      return true;
//    }
//
//    void FileServer::Release() {
//      _fileMap.clear(); // ���
//    }
//
//    bool FileServer::LoadFileMap(std::filesystem::path jsonPath) {
//#ifdef _DEBUG
//      auto stringPath = jsonPath.string();
//#endif
//      // �Ώۃt�@�C���͑��݂��Ă��邩
//      if (!std::filesystem::exists(jsonPath)) {
//#ifdef _DEBUG
//        const std::string message(stringPath + ":�p�X���s���ł�");
//        DebugStringLog(message);
//#endif
//        return false; // �p�X���s��
//      }
//      // �Ώۂ�json�t�@�C�����̔���
//      if (!LoadJson::IsJson(jsonPath)) {
//#ifdef _DEBUG
//        const std::string message(stringPath + ":�Ώۂ�json�t�@�C���ł͂���܂���");
//        DebugStringLog(message);
//#endif
//        return false; // �t�@�C���`�����قȂ�
//      }
//      auto fileMap = LoadJson::LoadJsonFile(jsonPath); // �t�@�C�����
//      if (fileMap.empty()) {
//        return false; // �t�@�C����񂪋�
//      }
//      auto counter = 0; // �o�^���s��
//      // �擾�����t�@�C�����̓o�^
//      for (auto [key, value] : fileMap) {
//        if (_fileMap.contains(key)) {
//#ifdef _DEBUG
//          const std::string message = "�L�[:" + key + "�͊��ɓo�^����Ă��܂�";
//          DebugStringLog(message);
//#endif
//          ++counter;
//          continue;
//        }
//        _fileMap.emplace(key, value);
//      }
//#ifdef _DEBUG
//      // �r���A�o�^�����Ɏ��s�������H
//      if (counter) {
//        const std::string message(counter + "�񏈗��Ɏ��s���܂���");
//        DebugStringLog(message);
//      }
//#endif
//      return true; // �o�^�I��
//    }
//
//    bool FileServer::SetLogTextFlag(bool flag, std::filesystem::path logPath) {
//      return true;
//    }
//
//    bool FileServer::LoadFileMap(FileBaseMap& fileMap) {
//      return true;
//    }
//
//    bool FileServer::FileCheck(const std::filesystem::path path) {
//      return true;
//    }
//
//#ifdef _DEBUG
//    void FileServer::DebugStringLog(const std::string text) {
//      // ���O�ւ̏o��
//      std::string message("FileServer:" + text + "\n");
//      OutputDebugString(message.data());
//      if (!_debug) {
//        return;
//      }
//      // �e�L�X�g�t�@�C���ւ̏o��
//      _debugLog.OutputText(text);
//    }
//#endif
  } // namespace FileServer
} // namespace AppFrame