/*****************************************************************//**
 * @file   LoadJson.cpp
 * @brief  Json�t�@�C���̓ǂݎ�菈���N���X�̒�`
 *
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "LoadJson.h"
#include <Windows.h>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <nlohmann/json.hpp>
#include "../Data/DivGraph.h"
#include "FileBase.h"
#include "FileServer.h"
#include "../SoundServer/SoundMem.h"

// json�t�@�C���̓ǂݎ��Ŏg�p����W���L�[
namespace {
  constexpr auto Directory = "directory"; //!< �f�B���N�g��
  constexpr auto Param = "param";         //!< �p�����[�^
  constexpr auto Extension = "extension"; //!< �t�@�C���g���q
  constexpr auto Key = "key";             //!< �A�z�z��ɓo�^����L�[
  constexpr auto FileName = "filename";   //!< �t�@�C����


  constexpr auto MAP = "map";             // �}�b�v
  constexpr auto DIRECTORY = "directory"; // �f�B���N�g���p�X
  constexpr auto FORMAT = "format";       // �t�H�[�}�b�g
  constexpr auto NUMS = "nums";           // �v�f���擾�L�[
  constexpr auto KEY = "key";             // �A�z�z��o�^�p�L�[
  constexpr auto PATH = "path";           // �t�@�C����
}

namespace AppFrame {
  namespace FileServer {

    std::unordered_map<std::string, FileBase> LoadJson::LoadJsonFile(std::filesystem::path jsonPath) {
      // �t�@�C���̓W�J
      std::ifstream jsonFile(jsonPath);
      // �ǂݎ�莸�s
      if (!jsonFile) {
#ifdef _DEBUG
        throw std::logic_error(jsonPath.string() + " : �t�@�C���̓ǂݎ��Ɏ��s���܂���\n");
#endif
        return FileBaseMap(); // ��f�[�^��Ԃ�
      }
      // 
      namespace json = nlohmann;
      json::json j = json::json::parse(jsonFile);
      jsonFile.close();

      auto map = j[MAP]; // �f�[�^
      // �L�[�ƃp�X�̃T�C�Y�͓�������
      if (map[KEY].size() != map[PATH].size()) {
#ifdef _DEBUG
        auto error = Differebce(static_cast<int>(map[KEY].size()), map[PATH]);
        throw std::logic_error("�L�[�ƃp�X�̃T�C�Y����v���Ă��܂���Bjson�t�@�C�����m�F���ĉ�����");
#endif
      }
      const std::string directry = map[DIRECTORY]; // �f�B���N�g���p�X
      const std::string format = map[FORMAT];      // �t�H�[�}�b�g
      std::queue<std::string_view> keys;           // �o�^�p�L�[
      // �L�[�̃R�s�[
      for (auto key : map[KEY]) {
        keys.push(key);
      }
      FileBaseMap fileMap; // �t�@�C���f�[�^
      // �A�z�z��ւ̓o�^
      for (auto path : map[PATH]) {
        std::string fileName = path; // �t�@�C����
        // �t�@�C���p�X
        std::string filePath = directry + fileName + format;
        // �p�X�͑��݂��邩
        if (std::filesystem::exists(filePath)) {
#ifdef _DEBUG
          OutputDebugString(filePath.c_str());
          OutputDebugString(" : �Ώۃt�@�C���͑��݂��Ă��܂���B\n");
#endif
          keys.pop(); // �擪�̃L�[��j��
          continue;
        }

      }
      return fileMap;
    }

//    bool LoadJson::LoadDivGraphData(nlohmann::json json) {
//      // �摜�t�@�C�������݂���f�B���N�g���p�X
//      auto directory = json["directory"].get<std::string>();
//      for (auto data : json["file"]["data"]) {
//#ifndef _DEBUG
//#else
//#endif
//        auto key = data["key"].get<std::string>();
//        auto divGraph =  AddDivGraph(data, directory);
//        // �R���e�i�ɓo�^����
//
//      }
//      return true;
//    }
//
//    Data::DivGraph LoadJson::AddDivGraph(nlohmann::json param, std::string_view directory) {
//      // �e��p�����[�^�̎擾
//      auto filePath = directory.data() + param["filename"].get<std::string>() + ".png";
//      auto xNum = param["xnum"].get<int>();
//      auto yNum = param["ynum"].get<int>();
//      auto allNum = param["allnum"].get<int>();
//      auto xSize = param["xsize"].get<int>();
//      auto ySize = param["ysize"].get<int>();
//      // ���������摜����Ԃ�
//      return Data::DivGraph(filePath, xNum, yNum, allNum, xSize, ySize);
//    }
//
//    Sound::SoundMem LoadJson::AddSoundMem(nlohmann::json param, std::string_view directory, std::string_view extension) {
//      auto filePath = directory.data() + param["filename"].get<std::string>() + extension.data();
//      auto playType = param["playtype"].get<int>();
//      return Sound::SoundMem(filePath, playType);
//    }
//
//    bool LoadJson::TypeChack(nlohmann::json json) {
//      switch (json.get<int>()) {
//      default:
//        return false;
//      }
//      return true;
//    }


#ifdef _DEBUG
    std::string_view LoadJson::Differebce(const int key, const int path) noexcept {
      std::string message;
      // �����̎Z�o
      auto value = key - path;
      if (value < 0) {
        value *= -1;
        message = "�p�X�̃T�C�Y���L�[����" + std::to_string(value) + "�����ł�\n";
      }
      else {
        message = "�L�[�̃T�C�Y���p�X����" + std::to_string(value) + "�����ł�\n";
      }
      return std::string_view(message);
    }

    std::logic_error LoadJson::GetLogicError(std::string message) {
      return std::logic_error("LoadJson::" + message + "/n");
    }
#endif

    bool LoadJson::IsJson(const std::filesystem::path path) {
      auto format = path.stem().string(); // �t�@�C���g���q
      if (format != "json") {
#ifdef _DEBUG
        throw std::logic_error(format + ":�Ώۂ�json�t�@�C���ł͂���܂���\n");
#endif
        return false; // json�t�@�C���ł͂Ȃ�
      }
      return true; // json�t�@�C��
    }
  } // namespace FileServer
} // namespace AppFrame