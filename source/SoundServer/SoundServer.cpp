/*****************************************************************//**
 * @file   SoundServer.cpp
 * @brief  �������Ǘ�����T�[�o�N���X�̒�`
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "SoundServer.h"
#include <DxLib.h>
#include "SoundMem.h"
#include "../FileServer/LoadJson.h"

namespace AppFrame {
  namespace Sound {

    SoundServer::SoundMap SoundServer::_sounds;
    std::filesystem::path SoundServer::_directory;

    void SoundServer::Init() {
      _sounds.clear();
      _directory.clear();
    }

    bool SoundServer::AddSound(std::string_view key, std::filesystem::path path) {
      namespace fs = std::filesystem;
      // �t�@�C���͑��݂��邩
      if (!fs::exists(path)) {
#ifdef _DEBUG
        throw std::logic_error("�p�X���s���ł�");
#endif
        return false; // ���݂��Ȃ�
      }
      // �L�[�͊��ɓo�^����Ă��邩
      if (_sounds.contains(key.data())) {
#ifdef _DEBUG
        throw std::logic_error("SoundServer:�L�[���d�����Ă��܂�\n");
#endif
        return false;
      }
      // �T�E���h�n���h���̎擾
      auto handle = LoadSoundMem(path.string().c_str());
      if (handle == -1) {
        // �ǂݎ�莸�s
#ifdef _DEBUG
        throw std::logic_error("SoundServer:�����t�@�C���̓ǂݎ��Ɏ��s���܂���\n");
#endif
        return false;
      }
      _sounds.emplace(key.data(), handle);
      return true; // �o�^����
    }

    bool SoundServer::LoadSoundFiles(std::vector<class SoundMem> soundFile) {
      if (soundFile.empty()) {
        return false; // �v�f����
      }
#ifdef _DEBUG
      int miss = 0; // �o�^�Ɏ��s������
#endif
      for (auto file : soundFile) {
        // �o�^���
        auto key = file.GetKey();
        auto path = file.GetFilePath();
#ifndef _DEBUG
        AddSound(key, path);
      }
      return true;
    }
#else
        try {
          // �o�^�Ɏ��s�����ꍇ�̓J�E���g�𑝉�������
          if (!AddSound(key, path)) {
            ++miss;
          }
        }
        catch (std::logic_error error) {
          OutputDebugString(error.what());
        }
      }
      if (miss) {
        throw std::logic_error("SoundServer:" + std::to_string(miss) + "��o�^�����Ɏ��s���܂���");
      }
      return true; // ����I��
    }
#endif

    const int SoundServer::GetSoundMem(std::string_view key) {
      // �L�[�̌���
      auto ite = _sounds.find(key.data());
      if (ite == _sounds.end()) {
        return -1; // ���o�^
      }
      return ite->second; // �擾����
    }

  } // namespace Sound
} // nemaspace AppFrame