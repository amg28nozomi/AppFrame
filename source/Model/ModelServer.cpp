/*****************************************************************//**
 * @file   ModelServer.cpp
 * @brief  ���f���̊Ǘ����s�����f���T�[�o
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#include "ModelServer.h"

namespace AppFrame {
  namespace Model {

    ModelServer::ModelServer() : Server::ServerTemplateUnordered<std::string, std::vector<int>>() {
      // �A�j���[�V�����̉��
      _animations.clear();
    }

    bool ModelServer::Release() {
      // �o�^����Ă��郂�f���f�[�^�̉��
      for (auto&& [key, handles] : _registry) {
        // ���f���f�[�^�̍폜
        for (auto handle : handles) {
          MV1DeleteModel(handle);
        }
        // �n���h�����폜����
        handles.clear();
      }
      // �A�j���[�V�����̍폜
      _animations.clear();
    }
    
    bool ModelServer::AddModel(std::string_view key, std::string_view path) {
      return true;
    }

    bool ModelServer::LoadModel(std::string_view key) {
      // �t�@�C���̓ǂݎ��
      if (_registry.contains(key.data())) {
        auto handles = _registry.at(key.data());

        // ���f�����o�^����Ă���ꍇ�͊������f�����폜����
        
      }
    }

  } // namespace Model
} // namespace AppFrame