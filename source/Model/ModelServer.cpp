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

    ModelServer::ModelServer() : Server::ServerTemplateUnordered<std::string, ModelMap>() {
    }

    bool ModelServer::Release() {
      // �o�^����Ă���S�f�[�^�̍폜���s��
      for (auto&& [key, model] : _registry) {
        // ���f���n���h���ƃA�j���[�V�������擾
        auto&& [handles, anima] = model;
        // ���f���f�[�^�̍폜
        for (auto handle : handles) {
          MV1DeleteModel(handle);
        }
        // �R���e�i�̉��
        handles.clear();
        anima.clear();
      }
    }
    
    bool AddModel(std::string_view key, std::string_view path) {
      return true;
    }

    bool ModelServer::LoadModel(std::string_view key) {
      // �t�@�C���̓ǂݎ��
      if (_registry.contains(key.data())) {
        auto [handles, animas] = _registry.at(key.data());
        // ���f�����o�^����Ă���ꍇ�͊������f�����폜����
        
      }
    }

  } // namespace Model
} // namespace AppFrame