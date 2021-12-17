/*****************************************************************//**
 * @file   FileServer.h
 * @brief  �t�@�C���f�[�^���Ǘ�����T�[�o�N���X
 *
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <unordered_map>
#include "FileOutput.h"

/** FileWorker�p���O��� */
namespace AppFrame {
  namespace FileServer {
    class FileBase;
    /**
     * @class FileServer
     * @brief �t�@�C���f�[�^���Ǘ�����T�[�o
     */
    class FileServer {
    private:
      /** ��������L�[�Ƃ��ăt�@�C���f�[�^���Ǘ�����A�z�z�� */
      using FileBaseMap = std::unordered_map<std::string, FileBase>;
    public:
      /**
       * @brief  �t�@�C���T�[�o�̐���
       */
      FileServer();
      /**
       * @brief  �t�@�C���T�[�o�̔j��
       */
      ~FileServer();
      /**
       * @brief  �T�[�o�̏���������
       * @return �������t���O
       */
      bool Init();
      /**
       * @brief  �f�[�^�̉������
       */
      void Release();
      /**
       * @brief  �t�@�C�����̓ǂݎ�菈��
       * @param  jsonPath �ǂݎ��Json�t�@�C���̃p�X
       * @return �ǂݎ�菈���ɐ��������ꍇ��true��Ԃ�
       */
      bool LoadFileMap(std::filesystem::path jsonPath);
      /**
       * @brief  ���O�o�̓t���O�̐ݒ�
       * @param  flag �o�̓t���O
       * @param  logPath ���O�t�@�C�����o�͂���f�B���N�g���p�X
       * @return �ݒ�ɐ��������ꍇ��true
       *         ���s�����ꍇ��false��Ԃ�
       */
      bool SetLogTextFlag(bool flag, std::filesystem::path logPath);
    private:
      FileBaseMap _fileMap; //!< �t�@�C�������Ǘ�����R���e�i
      FileOutput _debugLog; //!< �f�o�b�O�p�t�@�C���o�̓V�X�e��
      bool _debug;          //!< �f�o�b�O�o�͗p�t���O
      /**
       * @brief  �t�@�C�����̓o�^����
       * @param  fileMap �o�^���s���t�@�C�����
       * @return �o�^����������I�������ꍇ��true
       *         ���s�����ꍇ��false��Ԃ�
       */
      bool LoadFileMap(FileBaseMap& fileMap);
      /**
       * @brief      ���ʎq�̔�����s��
       * @param path ����t�@�C��
       * @return
       */
      bool FileCheck(const std::filesystem::path path);
#ifdef _DEBUG
      /**
       * @brief  ���O�o��
       * @param  text �o�͂��镶����
       */
      void DebugStringLog(const std::string text);
#endif
    };
  } // namespace FileServer
} // namespace AppFrame