#include "ModelServer.h"
#include "../Math/Arithmetic.h"

namespace AppFrame {
  namespace Model {

    ModelServer::ModelServer() : Server::ServerTemplateUnordered<std::string, ModelDatas>() {
    }

    bool ModelServer::Release() {
      // �e��R���e�i�̉���������s��
      for (auto&& [key, value] : _registry) {
        // �l�Ƃ��Ċi�[����Ă���f�[�^���擾
        auto&& [path, handles, animes] = value;
        DeleteModels(handles); // ���f���n���h�����폜
        animes.clear();        // �A�j���[�V�������폜����
      }
      _registry.clear(); // �R���e�i���������
    }

    bool ModelServer::AddMV1Model(std::string_view key, std::string_view path) {
      // �L�[���d�����Ă邩�̔���
      if (!UseKey(key.data())) {
        // �L�[���d�����Ă���ꍇ�͊����f�[�^���폜
        auto&& [path, handles, animes] = _registry.at(key.data());
        DeleteModels(handles); // ���f���n���h�����폜
        animes.clear();        // �A�j���[�V�������폜����
        _registry.erase(key.data());
      }
      // ���f���n���h���̓ǂݎ��
      auto handle = MV1LoadModel(path.data());
      // ���f���n���h���̎擾�ɐ���������
      if (handle == -1) {
#ifdef _DEBUG
        // ���f���n���h���̓ǂݎ��Ɏ��s�����ꍇ�̓��O�ɏo�͂���
        auto message = static_cast<std::string>(path) + ":mv1�t�@�C���̓ǂݎ��Ɏ��s���܂���\n";
        DebugString(message);
#endif
        return false; // �擾���s
      }
      // ���f���n���h�����i�[����R���e�i
      std::vector<int> handles{ handle };
      auto animNum = MV1GetAnimNum(handle); // �A�j���[�V�����ԍ��̎擾
      // �A�j���[�V���������i�[����A�z�z��
      std::unordered_map<std::string, int> animes;
      // �A�j���[�V��������o�^����
      for (auto num = 0; num < animNum; ++num) {
        // �A�j���[�V�������̎擾
        auto animName = MV1GetAnimName(handle, num);
        // �擾�����f�[�^����ɗv�f���\�z
        animes.emplace(animName, num);
      }
      // �ǂݎ�����f�[�^��o�^����
      _registry.emplace(key.data(), path.data(), std::move(handles), std::move(animes));
      return true; // �o�^����
    }

    std::pair<int, int> ModelServer::GetModel(std::string_view key, const int no) {
      // �L�[���o�^����Ă��邩�̔���
      if (_registry.contains(key.data())) {
        return std::make_pair(-1, -1); // �L�[�����o�^
      }
      auto handles = Handles(key.data()); // �R���e�i���擾
      auto size = static_cast<int>(handles.size());
      // ���ʔԍ��͔͈͓��Ɏ��܂��Ă��邩
      if (Math::Arithmetic::IsRange(no, 0, size - 1)) {
        return std::make_pair(handles.at(no), no); // �Ή����郂�f���n���h����Ԃ�
      }
      // �I���W�i���n���h������ɕ���
      auto handle = MV1DuqlicateModel(handles.front());
      // �����������f���n���h���𖖔��ɓo�^
      handles.emplace_back(handle);
      // ���f���n���h���Ǝ��ʔԍ���Ԃ�
      return std::make_pair(handle, size);
    }

    void ModelServer::DeleteModels(std::vector<int>& handles) {
      for (auto handle : handles) {
        MV1DeleteModel(handle); // ���f���n���h�����폜����
      }
      handles.clear(); // �R���e�i���������
    }

    std::vector<int>& ModelServer::Handles(std::string_view key) {
      auto [path, handles, animes] = _registry[key.data()];
      return handles;
    }

    std::unordered_map<std::string, int>& ModelServer::Animes(std::string_view key) {
      auto [path, handles, animes] = _registry[key.data()];
      return animes;
    }
  } // namespace Model
} // namespace AppFrame