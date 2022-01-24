/*****************************************************************//**
 * @file   Matrix44.cpp
 * @brief  4*4行列クラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "Matrix44.h"
#include <cmath>
#include <tuple>
#include "Arithmetic.h"

namespace AppFrame {
  namespace Math {

    Matrix44::Matrix44() {
      Reset(_rowColumn);
    }

    Matrix44::Matrix44(const MatrixArray values) {
      _rowColumn = values;
    }

    void Matrix44::Reset(MatrixArray& matrix) {
      for (auto&& values : matrix) {
        values.fill(0.0);
      }
    }

    Matrix44 Matrix44::Identyty() {
      MatrixArray identyty;
      Reset(identyty);
      // 単位行列の作成
      identyty[0][0] = 1.0f;
      identyty[1][1] = 1.0f;
      identyty[2][2] = 1.0f;
      identyty[3][3] = 1.0f;
      return Matrix44(identyty);
    }

    Matrix44 Matrix44::Translate(float x, float y, float z) {
      // 単位行列の取得
      auto translate = Identyty();
      translate._rowColumn[0][3] = x;
      translate._rowColumn[1][3] = y;
      translate._rowColumn[2][3] = z;
      return translate;
    }

    Matrix44 Matrix44::Scaling(float x, float y, float z) {
      auto scaling = Identyty();
      // 拡縮値の設定
      scaling._rowColumn[0][0] = x;
      scaling._rowColumn[1][1] = y;
      scaling._rowColumn[2][2] = z;
      return scaling;
    }

    void Matrix44::RotateX(float angle) {
      auto cos = std::cos(angle);
      auto sin = std::sin(angle);
      _rowColumn[1][1] = cos;
      _rowColumn[1][2] = sin;
      _rowColumn[2][1] = -sin;
      _rowColumn[2][2] = cos;
    }

    void Matrix44::RotateY(float angle) {
      auto cos = std::cos(angle);
      auto sin = std::sin(angle);
      _rowColumn[0][0] = cos;
      _rowColumn[0][2] = sin;
      _rowColumn[2][0] = -sin;
      _rowColumn[2][2] = cos;
    }

    void Matrix44::RotateZ(float angle) {
      auto cos = std::cos(angle);
      auto sin = std::sin(angle);
      _rowColumn[0][0] = cos;
      _rowColumn[0][1] = sin;
      _rowColumn[1][0] = -sin;
      _rowColumn[1][1] = cos;
    }

    Matrix44 Matrix44::operator*(const Matrix44 rhs) const {
      MatrixArray matrix;
      for (auto row = 0; row < MaxRow; ++row) {
        for (auto column = 0; column < MaxColumn; ++column) {
          float value = 0.0f;
          for (auto m = 0; m < 4; ++m) {
            value += _rowColumn[row][column] * rhs.GetValue(m, column);
          }
          matrix[row][column] = value;
        }
      }
      return Matrix44(matrix);
    }

    float Matrix44::GetValue(const int row, const int column) const {
      return _rowColumn[row][column];
    }
  } // namespace Math
} // namespace AppFrame