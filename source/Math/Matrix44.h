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
     * @brief 4*4行列クラス
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
      /**
       * @brief  単位行列の作成
       * @return 単位行列
       */
      static Matrix44 Identyty();
      /**
       * @brief  平行移動行列の取得
       * @param  x x軸方向ベクトル
       * @param  y y軸方向ベクトル
       * @param  z z軸平行ベクトル
       * @return 平行移動行列
       */
      static Matrix44 Translate(float x, float y, float z);
      /**
       * @brief  拡大縮小行列の取得
       * @param  x
       * @param  y
       * @param  z
       * @return 拡大縮小行列
       */
      static Matrix44 Scaling(float x, float y, float z);
      /**
       * @brief  回転行列(x軸)
       * @param  angle 
       */
      void RotateX(float angle);
      /**
       * @brief  回転行列(y軸)
       * @param  angle
       */
      void RotateY(float angle);
      /**
       * @brief  回転行列(z軸)
       * @param  angle
       */
      void RotateZ(float angle);
    private:
      MatrixArray _rowColumn; //!< 行列
    };
  } // namespace Math
} // namespace AppFrame