/*****************************************************************//**
 * @file   ModelServer.h
 * @brief  ��������L�[�Ƃ��ă��f�����ƃA�j���[�V�������Ǘ�����T�[�o�N���X
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#pragma once
#include "../Server/ServerTemplateUnordered.h"

namespace AppFrame {
  namespace Model {
    /**
     * @brief ���f�����
     */
    using ModelDatas = std::tuple<std::string, std::vector<int>, std::unordered_map<std::string, int>>;
    /**
     * @class ModelServer
     * @brief ��������L�[�Ƃ��ă��f�����ƃA�j���[�V�������Ǘ�����T�[�o
     */
    class ModelServer : Server::ServerTemplateUnordered<std::string, ModelDatas>{
    public:
      /**
       * @brief �R���X�g���N�^
       */
      ModelServer();
      /**
       * @brief  ���\�[�X�̉��
       * @return 
       */
      bool Release() override;
      /**
       * @brief  MV1�t�@�C���̓ǂݎ�菈��
       * @param  key  ���f�����ɕR�Â��镶����
       * @param  path �Ώۃt�@�C���̃p�X
       * @return true:�o�^���� false:�o�^���s
       */
      bool AddMV1Model(std::string_view key, std::string_view path);
      /**
       * @brief  ���f���n���h���̎擾
       * @param  key ���f�����ɕR�Â���ꂽ������
       * @return first:�擾�ɐ��������ꍇ�̓��f���n���h����Ԃ� ���s�����ꍇ��-1��Ԃ�
       *         second:���ʔԍ�
       */
      std::pair<int, int> GetModel(std::string_view key, const int no);
    private:
      /**
       * @brief �o�^����Ă��郂�f���n���h�����������
       * @param handles ���f���n���h�����i�[����Ă���R���e�i�̎Q��
       */
      void DeleteModels(std::vector<int>& handles);
      /**
       * @brief  ���f���n���h�����i�[����Ă���R���e�i�̎Q�Ƃ��擾
       * @param  key ������
       * @return ���f���n���h�����i�[����Ă���R���e�i�̎Q��
       */
      std::vector<int>& Handles(std::string_view key);
      /**
       * @brief  �A�j���[�V�������i�[����Ă���R���e�i�̎Q�Ƃ��擾
       * @param  key ������
       * @return �A�j���[�V�������i�[����Ă���R���e�i�̎Q��
       */
      std::unordered_map<std::string, int>& Animes(std::string_view key);
    };
  } // namespace Model
} // namespace AppFrame