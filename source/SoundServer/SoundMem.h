/*****************************************************************//**
 * @file   SoundMem.h
 * @brief  
 * 
 * @author —é–ØŠóŠC
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "FileWorker.h"

namespace AppFrame {
  namespace Sound {
    /**
     * @class SoundMem
     * @brief
     */
    class SoundMem : public FileWorker::FileBase {
    public:
      SoundMem(fs::path filePath);
    private:
    };
  }
}

