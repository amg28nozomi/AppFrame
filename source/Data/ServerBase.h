/*****************************************************************//**
 * @file   ServerBase.h
 * @brief  �T�[�o�̊��N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
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
      /**
       * @brief  �R���X�g���N�^
       */
      ServerBase();
      /**
       * @brief  �f�X�g���N�^
       */
      virtual ~ServerBase() = 0;
      /**
       * @brief  �o�^����
       * @param  files �t�@�C�����
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
       * @brief  �L�[�̌���
       * @param  key �������镶����
       * @return true:�o�^�ς� false:���o�^
       */
      bool KeySearch(std::string_view key);
#ifdef _DEBUG
      std::string _name; //!< �T�[�o�[��
      /**
       * @brief  logic_error�̐���
       * @param  message �g�p����G���[��
       * @return �w�肵���`���ɕϊ�����logic_error
       */
      std::logic_error LogicError(std::string_view message);
      /**
       * @brief ���O�ւ̏o�͏���
       * @param message �o�͂��镶����
       */
      void DebugString(std::string_view message);
#endif
    };

  } // namespace Data
} // namespace AppFrame
