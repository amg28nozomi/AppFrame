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
#include "Utility.h"
#include "Vector4.h"

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

    Matrix44 Matrix44::Identity(const Matrix44& matrix) {
      auto m = matrix._rowColumn;
      for (auto i = 0; i < MaxRow; ++i) {
        m[i][i] = 1.0f;
      }
      return Matrix44(m);
    }

    Matrix44 Matrix44::Identity() {
      MatrixArray identity;
      Reset(identity);
      // 単位行列の作成
      for (auto i = 0; i < MaxRow; ++i) {
        identity[i][i] = 1.0f;
      }
      return Matrix44(identity);
    }

    Matrix44 Matrix44::Translate(float x, float y, float z) {
      // 単位行列の生成
      auto translate = Identity();
      translate._rowColumn[0][3] = x;
      translate._rowColumn[1][3] = y;
      translate._rowColumn[2][3] = z;
      return translate;
    }

    Matrix44 Matrix44::Scaling(float x, float y, float z) {
      // 単位行列の生成
      auto scaling = Identity();
      // 拡縮値の設定
      scaling._rowColumn[0][0] = x;
      scaling._rowColumn[1][1] = y;
      scaling._rowColumn[2][2] = z;
      return scaling;
    }

    void Matrix44::RotateX(float radian) {
      auto identity = Identity(); // 単位行列の取得
      auto cos = std::cos(radian);
      auto sin = std::sin(radian);
      identity._rowColumn[1][1] = cos;
      identity._rowColumn[1][2] = sin;
      identity._rowColumn[2][1] = -sin;
      identity._rowColumn[2][2] = cos;
      *this = *this * identity;
    }

    void Matrix44::RotateY(float radian) {
      auto identity = Identity(); // 単位行列の取得
      auto cos = std::cos(radian);
      auto sin = std::sin(radian);
      identity._rowColumn[0][0] = cos;
      identity._rowColumn[0][2] = sin;
      identity._rowColumn[2][0] = -sin;
      identity._rowColumn[2][2] = cos;
      *this = *this * identity;
    }

    void Matrix44::RotateZ(float radian) {
      auto identity = Identity(); // 単位行列の取得
      auto cos = std::cos(radian);
      auto sin = std::sin(radian);
      identity._rowColumn[0][0] = cos;
      identity._rowColumn[0][1] = -sin;
      identity._rowColumn[1][0] = sin;
      identity._rowColumn[1][1] = cos;
      *this = *this * identity;
    }

    void Matrix44::MulTranslate(const AppFrame::Math::Vector4 translate) {
      _rowColumn[3][0] += translate.GetX();
      _rowColumn[3][1] += translate.GetY();
      _rowColumn[3][2] += translate.GetZ();
    }

    void Matrix44::MulScaling(const AppFrame::Math::Vector4 scale) {
      _rowColumn[0][0] *= scale.GetX();
      _rowColumn[1][1] *= scale.GetY();
      _rowColumn[2][2] *= scale.GetZ();
    }

    Matrix44 Matrix44::operator*(const Matrix44 rhs) const {
      MatrixArray matrix;
      for (auto row = 0; row < MaxRow; ++row) {
        for (auto column = 0; column < MaxColumn; ++column) {
          float value = 0.0f;
          for (auto m = 0; m < 4; ++m) {
            value += _rowColumn[row][m] * rhs.GetValue(m, column);
          }
          matrix[row][column] = value;
        }
      }
      return Matrix44(matrix);
    }

    Vector4 Matrix44::operator* (const Vector4& vector) const {
      // 各成分の取得
      auto [x, y, z, w] = vector.GetVector4();
      // 処理用に配列を作成
      std::array<float, MaxRow> vector4 = { x, y, z, w };
      auto r = _rowColumn;
      for (auto i = 0; i < MaxRow; ++i) {
        vector4[i] = r[i][0] * x + r[i][1] * y + r[i][2] * z + r[i][3] * w;
      }
      return Vector4(vector4.at(0), vector4.at(1), vector4.at(2), vector4.at(3));
    }

    float Matrix44::GetValue(const int row, const int column) const {
      return _rowColumn[row][column];
    }

    Matrix44 Matrix44::Inverse(const Matrix44 matrix) {
      // 単位行列を用意
      auto inverse = Identity();
      auto rowColumn = matrix._rowColumn;
      // 掃き出し法による逆行列の算出
      for (auto i = 0; i < MaxColumn; ++i) {
        auto dot = 1.0f / matrix._rowColumn[i][i];
        
        for (auto j = 0; j < MaxRow; ++j) {
          rowColumn[i][j] *= dot;
          inverse._rowColumn[i][j] *= dot;
        }

        for (auto j = 0; j < MaxRow; ++j) {

          if (i == j) {
            continue;
          }

          dot = rowColumn[j][i];

          for (auto k = 0; k < MaxRow; ++k) {
            rowColumn[j][k] -= rowColumn[i][k] * dot;
            inverse._rowColumn[j][k] -= inverse._rowColumn[i][k] * dot;
          }
        }
      }

      return inverse;
    }
  } // namespace Math
} // namespace AppFrame