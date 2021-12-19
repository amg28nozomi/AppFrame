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
    public:
      /**
       * @brief �T�E���h�T�[�o�̐���
       */
      SoundServer();
      /**
       * @brief  ������
       * @return true:���������� false:���������s
       * @throw  std::logic_error
       */
      bool Init();
    private:
      std::filesystem::path _directory; // �f�B���N�g��
    };
  } // namespace Sound
} // namespace AppFrame