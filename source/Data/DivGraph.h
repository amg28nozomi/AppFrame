/*****************************************************************//**
 * @file   DivGraph.h
 * @brief  画像ファイルの情報クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "FileWorker/FileBase.h"

namespace fs = std::filesystem;

namespace AppFrame {
  /**
   * @class DivGraph
   * @brief 画像ファイル情報
   */
  class DivGraph : public FileWorker::FileBase {
  public:
    /**
     * @brief 空の画像情報生成
     */
    DivGraph();
    /**
     * @brief 画像情報の設定
     * @param filePath ファイルのパス
     * @param xNum     横分割数
     * @param yNum     縦分割数
     * @param allNum   総分割数
     * @param xSize    分割後の画像サイズ(横)
     * @param ySize    分割後の画像サイズ(縦)
     */
    DivGraph(fs::path filePath, int xNum, int yNum, int allNum, int xSize, int ySize);
    /**
     * @brief  画像情報の解放
     */
    void Clear();
    /**
     * @brief  分割情報の取得
     * @return 画像の分割数を返す
     */
    inline const auto GetNum() const {
      return std::make_tuple(_xNum, _yNum, _allNum);
    }
    /**
     * @brief  分割後の画像サイズの取得
     * @return 画像サイズを返す
     */
    inline const auto GetSize() const {
      return std::make_pair(_xSize, _ySize);
    }
  private:
    int _xNum;   //!< 縦分割数
    int _yNum;   //!< 縦分割数
    int _allNum; //!< 総分割数
    int _xSize;  //!< 分割後の画像サイズ(幅)
    int _ySize;  //!< 分割後の画像サイズ(高さ)
  };
}