/*****************************************************************//**
 * @file   FileBase.cpp
 * @brief  �t�@�C���f�[�^��ێ�����X�[�p�[�N���X�̒�`
 *
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "FileBase.h"

namespace AppFrame {
  namespace FileServer {

    FileBase::FileBase() {
      Clear();
    }

    FileBase::FileBase(std::filesystem::path filePath) {
      // �t�@�C���͑��݂��Ă��邩
      if (!std::filesystem::exists(filePath)) {
        Clear();
        return; // �Ώۃt�@�C���͑��݂��Ȃ�
      }
      _path = filePath;
    }

    FileBase::~FileBase() {
      Clear();
    }
  } // namespace FileServer
} // namespace AppFrame