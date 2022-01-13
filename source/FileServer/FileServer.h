/*****************************************************************//**
 * @file   FileServer.h
 * @brief  �t�@�C���f�[�^���Ǘ�����T�[�o�N���X
 *
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "FileOutput.h"
#include "FileBase.h"

/** FileWorker�p���O��� */
namespace AppFrame {
  namespace FileServer {

//    class FileServer : public Data::ServerBase < FileBase, std::filesystem::path > {
//    public:
//#ifndef _DEBUG
//      /**
//       * @brief �R���X�g���N�^
//       */
//      FileServer();
//#else
//      /**
//       * @brief �R���X�g���N�^
//       * @param filePath ���O�o�͗p�t�@�C���̃p�X(�f�t�H���g�ł͋�)
//       */
//      FileServer(std::filesystem::path filePath = "");
//#endif
//      /**
//       * @brief �f�X�g���N�^
//       */
//      ~FileServer() override;
//      /**
//       * @brief  ������
//       */
//      bool Init() override;
//      /**
//       * @brief  ���W�X�g���̏�����
//       * @return 
//       */
//      bool Release() override;
//      /**
//       * @brief  �t�@�C�����̓o�^
//       * @param  key  �o�^�Ɏg�p���镶����
//       * @param  path �t�@�C���̃p�X
//       * @return true:�o�^���� false:�o�^���s
//       */
//      bool Register(std::string_view key, const std::filesystem::path path) override;
//      /**
//       * @brief  �t�@�C�����̓ǂݎ��
//       * @param  jsonPath json�t�@�C���̃|�X
//       * @return true:�ǂݎ�萬�� false:��蔭��
//       */
//      bool LoadFiles(std::filesystem::path jsonPath);
//    protected:
//#ifdef _DEBUG
//      class FileOutput _fileLog; //!< �t�@�C���o�̓V�X�e��
//      bool _debug{false};        //!< ���O�o�̓t���O
//#endif
//    };

    /**
     * @class FileServer
     * @brief �t�@�C���f�[�^���Ǘ�����T�[�o
     */
//    class FileServer {
//    private:
//      /** ��������L�[�Ƃ��ăt�@�C���f�[�^���Ǘ�����A�z�z�� */
//      using FileBaseMap = std::unordered_map<std::string, FileBase>;
//    public:
//      /**
//       * @brief  �t�@�C���T�[�o�̐���
//       */
//      FileServer();
//      /**
//       * @brief  �t�@�C���T�[�o�̔j��
//       */
//      ~FileServer();
//      /**
//       * @brief  �T�[�o�̏���������
//       * @return �������t���O
//       */
//      bool Init();
//      /**
//       * @brief  �f�[�^�̉������
//       */
//      void Release();
//      /**
//       * @brief  �t�@�C�����̓ǂݎ�菈��
//       * @param  jsonPath �ǂݎ��Json�t�@�C���̃p�X
//       * @return �ǂݎ�菈���ɐ��������ꍇ��true��Ԃ�
//       */
//      bool LoadFileMap(std::filesystem::path jsonPath);
//      /**
//       * @brief  ���O�o�̓t���O�̐ݒ�
//       * @param  flag �o�̓t���O
//       * @param  logPath ���O�t�@�C�����o�͂���f�B���N�g���p�X
//       * @return �ݒ�ɐ��������ꍇ��true
//       *         ���s�����ꍇ��false��Ԃ�
//       */
//      bool SetLogTextFlag(bool flag, std::filesystem::path logPath);
//    private:
//      FileBaseMap _fileMap; //!< �t�@�C�������Ǘ�����R���e�i
//      FileOutput _debugLog; //!< �f�o�b�O�p�t�@�C���o�̓V�X�e��
//      bool _debug;          //!< �f�o�b�O�o�͗p�t���O
//      /**
//       * @brief  �t�@�C�����̓o�^����
//       * @param  fileMap �o�^���s���t�@�C�����
//       * @return �o�^����������I�������ꍇ��true
//       *         ���s�����ꍇ��false��Ԃ�
//       */
//      bool LoadFileMap(FileBaseMap& fileMap);
//      /**
//       * @brief      ���ʎq�̔�����s��
//       * @param path ����t�@�C��
//       * @return
//       */
//      bool FileCheck(const std::filesystem::path path);
//#ifdef _DEBUG
//      /**
//       * @brief  ���O�o��
//       * @param  text �o�͂��镶����
//       */
//      void DebugStringLog(const std::string text);
//#endif
//    };
  } // namespace FileServer
} // namespace AppFrame