/*****************************************************************//**
 * @file   JsonServer.h
 * @brief  json�t�@�C���̓ǂݎ��E�����o�����s���T�[�o�N���X
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#pragma once
#include "../Data/ServerBase.h"

#include <nlohmann/json.hpp>
/**
 * @brief �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief �t�@�C���T�[�o
   */
  namespace FileServer {
    /**
     * @class JsonServer
     * @brief json���Ǘ�����T�[�o�N���X�̊��N���X
     */
    class JsonServer : public Data::ServerBase < std::filesystem::path, std::filesystem::path> {
    public:
      /**
       * @brief �R���X�g���N�^
       */
      JsonServer();
      /**
       * @brief �f�X�g���N�^
       */
      ~JsonServer() override;
      /**
       * @brief  �T�[�o�̏�����
       * @return true:���������� false:���������s
       */
      bool Init() override;
      /**
       * @brief  
       * @param  key
       * @param  path
       * @return 
       */
      bool Register(std::string_view key, std::filesystem::path path) override;

      /**
       * @brief  json�t�@�C���̓ǂݎ�菈��
       * @param  jsonFile �ǂݎ����s��json�t�@�C���̃p�X
       * @return true:�ǂݎ�萬�� false:�ǂݎ�莸�s
       */
      bool LoadJsonFile(std::filesystem::path jsonFile);
      /**
       * @brief  �Ō�ɊJ����json�t�@�C���̃p�X���擾
       * @return �Ō�ɊJ����json�t�@�C���̃p�X
       *         �t�@�C�����J���Ă��Ȃ��ꍇ�͋��path��Ԃ�
       */
      inline std::filesystem::path OpendFile() const {
        return _opendFile;
      }
    protected:
      //!< json�t�@�C���̃p�X���Ǘ�����f�[�^�x�[�X
      std::string _extension{".json"}; //!< �Ή����Ă���t�@�C���`��
      std::filesystem::path _opendFile{}; //!< �Ō�ɊJ�����t�@�C���̃p�X
      /**
       * @brief  �f�[�^�x�[�X�ւ̓o�^
       * @param  key �o�^���ɕR�Â��镶����
       * @param  jsonFile json�t�@�C���̃p�X
       * @return true:�o�^���� false:�o�^���s
       * @throw  Debug:logic_error
       */
      bool Register(std::string_view key, std::filesystem::path jsonFile);
      /**
       * @brief  �Ώۃt�@�C�����o�^�\���̔���
       * @param  key �o�^�Ɏg�p���镶����
       * @param  filePath �o�^����json�t�@�C���̃p�X
       * @param  extension �Ή����Ă���t�@�C���g���q(�f�t�H���g�͋�)
       * @return 
       */
      bool IsTarget(std::string_view key, std::filesystem::path filePath, std::string_view extension = "") const;
    };
  } // namespace FileServer
} // namespace AppFrame