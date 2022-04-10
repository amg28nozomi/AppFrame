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
#include "FileBase.h"
#include "FileServer.h"
#include "../Application/ApplicationBase.h"
#include "../Data/DivGraph.h"
#include "../SoundServer/SoundMem.h"
#include "../Resource/ResourceServer.h"
#include "../Model/ModelServer.h"

// json�t�@�C���̓ǂݎ��Ŏg�p����W���L�[
namespace {
  // json�t�@�C���̓ǂݎ��Ŏg�p����L�[
  constexpr auto DataType = "data";       //!< �f�[�^���ʗp
  constexpr auto TypeGraph = 1;     //!< �摜���
  constexpr auto TypeModel = 2;     //!< ���f���f�[�^

  constexpr auto Values = "values";

  constexpr auto Extension = "expention"; //!< �t�@�C���g���q
  constexpr auto Directory = "directory"; //!< �f�B���N�g���p�X�擾�p
  constexpr auto File = "file";           //!< �t�@�C�����
  constexpr auto ModelKey = "key";        //!< �T�[�o�o�^���ɕR�Â���L�[
  constexpr auto FileName = "filename";  //!< ���f���t�@�C����
  // �摜�ǂݎ��p
  constexpr auto XNum = "xnum";     //!< x���̕�����
  constexpr auto YNum = "ynum";     //!< y���̕�����
  constexpr auto AllNum = "allnum"; //!< �摜�̑�������
  constexpr auto XSize = "xsize";   //!< �摜1��������̉��T�C�Y
  constexpr auto YSize = "ysize";   //!< �摜1��������̏c�T�C�Y
  constexpr auto GraphKey = "key";  //!< 

  constexpr auto DataTypeModel = "model"; //!< ���f���f�[�^
  constexpr auto TextureData = "texture"; //!< �摜�f�[�^

  constexpr auto Param = "param";         //!< �p�����[�^
  constexpr auto Key = "key";             //!< �A�z�z��ɓo�^����L�[


  constexpr auto MAP = "map";             // �}�b�v
  constexpr auto FORMAT = "format";       // �t�H�[�}�b�g
  constexpr auto NUMS = "nums";           // �v�f���擾�L�[
  constexpr auto KEY = "key";             // �A�z�z��o�^�p�L�[
  constexpr auto PATH = "path";           // �t�@�C����
} // namespace

namespace AppFrame {
  namespace FileServer {

    LoadJson::LoadJson(Application::ApplicationBase& app) : _app(app) {
    }

    bool LoadJson::LoadJsonFile(std::string_view path) {
      using json = nlohmann::json;
      std::ifstream read(path.data());
      // �ǂݎ�����f�[�^��json�I�u�W�F�N�g�ɕϊ�
      json data = json::parse(read);
      // json�t�@�C�������
      read.close();
      // �f�[�^�^�C�v�̎擾
      auto type = data[DataType].get<int>();
      // �Ή��f�[�^���i�[���ꂽjson�I�u�W�F�N�g
      auto values = data[Values];
      for (auto value : values) {
        // �f�[�^�^�C�v�ɑΉ������������Ăяo��
        switch (type) {
        case TypeGraph: // �摜���
          // �摜���̓ǂݎ����s��
          LoadDivGraphData(std::move(value));
          break;
        case TypeModel: // ���f�����
          // ���f�����̓ǂݎ����s��
          LoadModelData(std::move(value));
          break;
        default:
          return false; // �f�[�^�^�C�v���s��
        }
      }
      return true; // �I��
    }

    bool LoadJson::LoadModelData(const nlohmann::json json) {
      // json�t�@�C������e��f�[�^�����o��
      auto directory = json[Directory].get<std::string>(); // �f�B���N�g���p�X
      // �f�B���N�g���͗L����
      if (!std::filesystem::is_directory(directory)) {
        auto message = directory + ":�f�B���N�g���p�X���s���ł�\n";
        OutputDebugString(message.data()); // ���O�ɏo�͂���
        return false; // �f�B���N�g�����L���ł͂Ȃ�
      }
      auto extension = json[Extension].get<std::string>(); // �t�@�C���g���q
      auto files = json[File]; // �t�@�C�����Ɠo�^�p�L�[���i�[���ꂽ�R���e�i
      // �ǂݎ�����f�[�^���T�[�o�ɓo�^����
      for (auto data : files) {
        auto key = data[ModelKey].get<std::string>();      // �o�^�Ɏg�p���镶����
        auto fileName = data[FileName].get<std::string>(); // �t�@�C����
        auto filePath = directory + fileName + extension;  // �t�@�C���p�X�̍쐬
        // MV1���f������ǂݍ���
        _app.GetModelServer().AddMV1Model(key, filePath);
      }
      return true;
    }

    bool LoadJson::LoadDivGraphData(const nlohmann::json json) {
      // json�t�@�C������e��f�[�^�����o��
      auto directory = json[Directory].get<std::string>(); // �f�B���N�g���p�X
      // �f�B���N�g���͗L����
      if (!std::filesystem::is_directory(directory)) {
        auto message = directory + ":�f�B���N�g���p�X���s���ł�\n";
        OutputDebugString(message.data()); // ���O�ɏo�͂���
        return false; // �f�B���N�g�����L���ł͂Ȃ�
      }
      auto extension = json[Extension].get<std::string>(); // �t�@�C���g���q
      auto files = json[File]; // �t�@�C�����Ɠo�^�p�L�[���i�[���ꂽ�R���e�i
      for (auto data : files) {
        // �T�[�o�o�^���ɕR�Â��镶����
        auto key = data[GraphKey].get<std::string>();
        // �t�@�C���p�X
        auto filePath = directory + data[FileName].get<std::string>() + extension;
        // �e��p�����[�^
        auto xNum = data[XNum].get<int>();
        auto yNum = data[YNum].get<int>();
        auto allNum = data[AllNum].get<int>();
        auto xSize = data[XSize].get<int>();
        auto ySize = data[YSize].get<int>();
        // �擾�����l����ɉ摜�����쐬
        Data::DivGraph divGraph(filePath, xNum, yNum, allNum, xSize, ySize);
#ifndef _DEBUG
        // �Ώۉ摜�t�@�C����ǂݍ���
        _app.GetResourceServer().LoadDivGraph(key, divGraph);
#else
        // �o�^�Ɏ��s�����ꍇ�̓L�[�ƃp�X�����O�ɏo�͂���
        if (!_app.GetResourceServer().LoadDivGraph(key, divGraph)) {
          auto message = key + ":�p�X���L���ł͂���܂���\n";
          OutputDebugString(message.data());
        }
#endif
      }
      return true; // �����I��
    }

    std::filesystem::path LoadJson::ToJsonName(std::string directory, std::string fileName) const {
      // json�t�@�C���̃p�X�ɕϊ�����
      return std::filesystem::path(directory + fileName + JSON);
    }

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
      return std::logic_error("LoadJson:" + message + "\n");
    }
#endif

    bool LoadJson::IsJson(const std::filesystem::path path) {
      auto format = path.extension().string(); // �t�@�C���g���q
      // �t�@�C���g���q��json��
      if (format != ".json") {
#ifdef _DEBUG
        auto message = path.string() + ":�Ώۂ�json�t�@�C���ł͂���܂���\n";
        OutputDebugString(message.data());
#endif
        return false; // json�t�@�C���ł͂Ȃ�
      }
      return true; // json�t�@�C��
    }
  } // namespace FileServer
} // namespace AppFrame