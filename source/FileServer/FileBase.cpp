/*****************************************************************//**
 * @file   FileBase.cpp
 * @brief  ファイルデータを保持するスーパークラスの定義
 *
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "FileBase.h"

namespace AppFrame {
  namespace FileServer {

    FileBase::FileBase() {
      Clear();
    }

    FileBase::FileBase(std::filesystem::path filePath) {
      // ファイルは存在しているか
      if (!std::filesystem::exists(filePath)) {
        Clear();
        return; // 対象ファイルは存在しない
      }
      _path = filePath;
    }

    FileBase::~FileBase() {
      Clear();
    }
  } // namespace FileServer
} // namespace AppFrame