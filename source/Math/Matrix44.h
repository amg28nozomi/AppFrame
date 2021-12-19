/*****************************************************************//**
 * @file   Matrix44.h
 * @brief  4*4行列クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <array>

namespace AppFrame {
  namespace Math {
    constexpr auto MaxRow = 4;    //!< 行の上限
    constexpr auto MaxColumn = 4; //!< 列の上限
    /**
     * @class Matrix4x4
     * @brief 行列クラス
     */
    class Matrix44 {
    private:
      /** float型の4*4行列を表す2次元配列 */
      using MatrixArray = std::array<std::array<float, MaxColumn>, MaxRow>;
    public:
      /**
       * @brief 空の行列を生成
       */
      Matrix44();
      /**
       * @brief 行列のコピー
       * @param values
       */
      Matrix44(const MatrixArray values);
      /**
       * @brief 行列の削除
       */
      ~Matrix44() = default;
      /**
       * @brief  行列の再設定
       * @param  matrix 行列クラスの参照
       * @return 初期化した行列を返す
       */
      static void Reset(MatrixArray& matrix);
    private:
      MatrixArray _rowColumn; //!< 行列
    };
  } // namespace Math
} // namespace AppFrame