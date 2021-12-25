/*****************************************************************//**
 * @file   SoundServer.h
 * @brief  �������Ǘ�����T�[�o�N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <filesystem>
#include <unordered_map>

namespace AppFrame {
  namespace Sound {
    /**
     * @class SoundServer
     * @brief �������Ǘ�����T�E���h�T�[�o
     */
    class SoundServer {
    private:
      /**
       * @brief �T�E���h�n���h����
       */
      using SoundMap = std::unordered_map<std::string, int>;
    public:
      /**
       * @brief  ������
       *         �T�E���h�T�[�o���g�p����ꍇ�͕K�����������邱��
       * @return true:���������� false:���������s
       * @throw  std::logic_error
       */
      static void Init();
      /**
       * @brief  �������̓o�^
       * @param  key   �o�^�p������
       * @param  path  �����t�@�C���̃p�X
       * @return true:�o�^���� false:�o�^���s
       */
      static bool AddSound(std::string_view key, std::filesystem::path path);
      /**
       * @brief  �����t�@�C�����̓ǂݎ��E�o�^����
       * @param  soundFile �������̓��I�z��
       * @return true:�o�^���� false:��蔭��
       */
      static bool LoadSoundFiles(std::vector<class SoundMem> soundFile);
      /**
       * @brief  �w�肵���T�E���h�n���h���̎擾
       * @param  key �L�[(������)
       * @return �擾�ɐ��������ꍇ�̓T�E���h�n���h����Ԃ�
       *         ���s�����ꍇ��-1��Ԃ�
       */
      static const int GetSoundMem(std::string_view key);
    private:
      static std::filesystem::path _directory; // �f�B���N�g��
      static SoundMap _sounds; //!< �T�E���h���
    };
  } // namespace Sound
} // namespace AppFrame