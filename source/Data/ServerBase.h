/*****************************************************************//**
 * @file   ServerBase.h
 * @brief  �T�[�o�̊��N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <filesystem>
#include <unordered_map>
#include <vector>
#ifdef _DEBUG
#include <stdexcept>
#endif

namespace AppFrame {

  namespace FileServer {
    class FileBase;
  }

  namespace Data {
    /**
     * @tparam T �A�z�z��̒l�ɊY������^
     * @tparam I �o�^�����Ŏg�p����^
     */
    template <typename T, typename I>
    /**
     * @class ServerBase
     * @brief �T�[�o�̊��N���X
     */
    class ServerBase {
    public:
#ifndef _DEBUG
      /**
       * @brief  �R���X�g���N�^(Release)
       */
      ServerBase();
#else
      /**
       * @brief  �R���X�g���N�^(Debug)
       * @param  flag ���O�o�̓t���O(�f�t�H���g�ł�false)
       */
      ServerBase(const bool flag = false);
#endif
      /**
       * @brief  �f�X�g���N�^
       */
      virtual ~ServerBase() = 0;
      /**
       * @brief  ������
       */
      virtual bool Init();
      /**
       * @brief  �������
       * @return true:�������� false:��蔭��
       */
      virtual bool Release() = 0;
      /**
       * @brief  �o�^�����p�������z�֐�
       *         �o�^�����͔h���N���X���Ŏ������邱��
       * @param  files �t�@�C�����
       * @param  value �o�^����l
       * @return true:�o�^���� false:�o�^���s
       */
      virtual bool Register(std::string_view key, const I value) = 0;
      /**
       * @brief  �t�@�C�����̓ǂݍ���
       * @param  files �t�@�C�����
       * @return true:�������� false:��蔭��
       */
      virtual bool LoadFiles(std::vector<FileServer::FileBase> files);
      /**
       * @brief  �w�肵���l�̎擾
       * @param  key �l�ɕR�Â���ꂽ������
       */
      virtual T Get(std::string_view key) const = 0;
    protected:
      std::unordered_map<std::string, T> _registry; //!< ���W�X�g���[
      /**
       * @brief  �Ώۃt�@�C�������݂��邩�̔���
       * @param  filePath �Ώۃt�@�C���̃p�X
       * @return true:�t�@�C���͑��݂��� false:�t�@�C���͑��݂��Ȃ�
       * @throw  Debug:�p�X���L���ł͂Ȃ��ꍇ�Alogic_error��Ԃ�
       */
      bool Exist(std::filesystem::path filePath) const;
      /**
       * @brief  �t�@�C���g���q����v���Ă��邩�̔���(Debug)
       * @param  filePath �t�@�C���̃p�X
       * @param  extension �Ή�����t�@�C���g���q
       * @return true:��v false:��v���Ă��Ȃ�
       * @throw  ��v���Ă��Ȃ��ꍇ�Alogic_error��Ԃ�
       */
      bool HasExtension(std::filesystem::path filePath, std::string_view extension) const;
      /**
       * @brief  �L�[���g�p�\���̔���
       * @param  key ���W�X�g���ւ̓o�^�Ŏg�p���镶����
       * @return true:�g�p�\ false:���łɎg�p����Ă���
       */
      bool UsedKey(std::string_view key) const;
      /**
       * @brief  �Ώۃf�[�^���L�����̔���
       * @param  file �t�@�C���f�[�^
       * @param  extension �t�@�C���g���q(�f�t�H���g�͊g���q�Ȃ�)
       * @return true:�L�� false:�L���ł͂Ȃ�
       */
      bool IsTarget(FileServer::FileBase file, std::string_view extension = "") const;
      /**
       * @brief  �L�[�̌���
       * @param  key �������镶����
       * @return true:�o�^�ς� false:���o�^
       * @throw  Debug:���Ɏg�p����Ă���ꍇ�A��O�𔭎˂���
       */
      bool KeySearch(std::string_view key);
#ifdef _DEBUG
      std::string _name; //!< �T�[�o�[��
      bool _debug;       //!< ���O�o�̓t���O
      /**
       * @brief  logic_error�̐���
       * @param  message �g�p����G���[��
       * @return �w�肵���`���ɕϊ�����logic_error
       */
      std::logic_error LogicError(std::string_view message) const;
      /**
       * @brief ���O�ւ̏o�͏���
       * @param message �o�͂��镶����
       */
      void DebugString(std::string_view message);
#endif
    };

  } // namespace Data
} // namespace AppFrame
