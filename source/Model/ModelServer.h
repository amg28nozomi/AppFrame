/*****************************************************************//**
 * @file   ModelServer.h
 * @brief  ���f���n���h���̊Ǘ����s�����f���T�[�o
 *
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#pragma once
#include "../Server/ServerTemplateUnordered.h"
#include <vector>
/**
 * @brief �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief ���f���x�[�X
   */
  namespace Model {
    /**
     * @class ModelServer
     * @brief ���f���̊Ǘ����s�����f���T�[�o
     */
    class ModelServer : Server::ServerTemplateUnordered<std::string, std::vector<int>> {
    public:
      /**
       * @brief �R���X�g���N�^
       */
      ModelServer();
      /**
       * @brief  ���f���̉������
       * @return true:����I�� false:��蔭��
       */
      bool Release() override;
      /**
       * @brief  ���f���̓o�^����
       * @param  key  ���f���ɕR�Â��镶����
       * @param  path �Ώۃ��f���t�@�C���̃p�X
       * @return true:�o�^���� false:�o�^���s
       */
      bool AddModel(std::string_view key, std::string_view path);
      /**
       * @brief  ���f���̓ǂݎ�菈��
       * @param  filePath �Ώۃ��f���̃t�@�C����(���f���ɕR�Â��镶����)
       * @return true:�o�^���� false:�o�^���s
       */
      bool LoadModel(std::string_view filePath);
    private:
      //!< �A�j���[�V������ێ�����f�[�^�x�[�X
      std::unordered_map<std::string, std::pair<std::string, int>> _animas;
    };
  } // namespace Model
} // namespace AppFrame