/*****************************************************************//**
 * @file   FileBase.h
 * @brief  �t�@�C���f�[�^��ێ�����X�[�p�[�N���X
 *
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <filesystem>

/** FileWorker�p���O��� */
namespace AppFrame {
  namespace FileServer {
    /**
     * @class FileBase
     * @brief �t�@�C���f�[�^
     */
    class FileBase {
    public:
      /**
       * @brief ��f�[�^�𐶐�
       */
      FileBase();
      /**
       * @brief �t�@�C���f�[�^�̐���
       * @param filePath �t�@�C���̃p�X
       */
      FileBase(std::filesystem::path filePath);
      /**
       * @brief �t�@�C���f�[�^�̔j��
       */
      ~FileBase();
      /**
       * @brief �p�X�̔j��
       */
      inline void Clear() {
        _path.clear();
      }
      /**
       * @brief  �p�X�̎擾
       * @return �t�@�C���p�X��Ԃ�
       */
      inline std::filesystem::path GetFilePath() const {
        return _path;
      }
      /**
       * @brief  �t�@�C�����̎擾
       * @return �g���q���������t�@�C������Ԃ�
       */
      inline std::string GetFileName() const {
        return _path.stem().string();
      }
    protected:
      std::filesystem::path _path; //!< �t�@�C���p�X
    };
  } // namespace FileServer
} // namespace AppFrame