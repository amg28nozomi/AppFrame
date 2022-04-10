/*****************************************************************//**
 * @file   FileServer.h
 * @brief  �t�@�C���f�[�^���Ǘ�����T�[�o�N���X
 *
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "../Server/ServerTemplateUnordered.h"
#include <filesystem>
#include "FileOutput.h"
#include "FileBase.h"

/** FileWorker�p���O��� */
namespace AppFrame {
  /**
   * @brief �A�v���P�[�V�����x�[�X
   */
  namespace Application {
    class ApplicationBase; //!< �A�v���P�[�V����
  } // namespace Application
  /**
   * @brief �t�@�C���T�[�o
   */
  namespace FileServer {
    class LoadJson; //!< �O���錾
    /**
     * @class FileServer
     * @brief �t�@�C���Ǘ��p�T�[�o
     */
    class FileServer : public Server::ServerTemplateUnordered<std::string, std::filesystem::path> {
    public:
      /**
       * @brief �R���X�g���N�^
       */
      FileServer(Application::ApplicationBase& app);
      /**
       * @brief  ������
       * @return true:���������� false:���������s
       */
      bool Init() override;
      /**
       * @brief  json�t�@�C���̓ǂݎ��
       * @param  jsonFile json�t�@�C���̃p�X
       * @return true:�ǂݎ����s false:��蔭��
       */
      bool LoadJsonFile(std::string_view jsonFile) const;
      /**
       * @brief  �Ώۃt�@�C���`���̎w��(Instance��A��x�̂ݐݒ�\)
       * @param  extensions �t�@�C���g���q(������)���i�[�������I�z��
       */
      bool SetExtension(std::vector<std::string> extensions);
    protected:
      std::unique_ptr<LoadJson> _loadJson;  //!< json�t�@�C���̓ǂݎ��
      std::vector<std::string> _extensions; //!< �Ή��t�@�C���`��
      bool _setExtension{false}; //!< �Ώۃt�@�C���`�����w�肵�����̔���
      /**
       * @brief  �Ώۃt�@�C�����o�^�Ώۂ��̔���
       * @param  filePath �Ώۃt�@�C���̃p�X
       * @param  extension �o�^�\�ȃt�@�C���`��
       * @return true:�o�^�Ώ� false:��o�^�Ώ�
       */
      bool IsTarget(std::filesystem::path filePath, std::string_view extension = "") const;
      /**
       * @brief  �t�@�C���`������v���Ă��邩�̔���
       * @param  filePath �Ώۃt�@�C���̃p�X
       * @return true:��v false:�Ώۂł͂Ȃ�
       */
      bool HasExtension(std::filesystem::path filePath, std::string_view extension = "") const;
      /**
       * @brief  �Ώۃp�X�����݂��邩�̔���
       * @param  filePath �Ώۃt�@�C���̃p�X
       * @return true:�L�� false:�p�X���s��
       */
      bool Exist(std::filesystem::path filePath) const;
    };
  } // namespace FileServer
} // namespace AppFrame