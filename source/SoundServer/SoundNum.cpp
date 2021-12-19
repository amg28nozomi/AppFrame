/*****************************************************************//**
 * @file   SoundNum.cpp
 * @brief  �����t�@�C�����N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "SoundNum.h"
#include <DxLib.h>

namespace AppFrame {
  namespace Sound {

    SoundNum::SoundNum(std::filesystem::path filePath, const int playType) : FileBase(filePath) {
      _playType = playType;
      _soundHandle = 0;
    }
  }
}