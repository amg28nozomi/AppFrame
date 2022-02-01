/*****************************************************************//**
 * @file   Utility.cpp
 * @brief  算術処理用の補助機能クラスの定義
 *
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#include "Utility.h"
#include "Matrix44.h"
#include "Vector4.h"

namespace AppFrame{
  namespace Math {

    Matrix44 Utility::ToWorldMatrix(const Vector4& position, Vector4 rotation, const Vector4& scale, const bool angle) {
      // rotationがデグリー値の場合はラジアン値に変換する
      if (angle) {
        rotation = RotationToRadian(rotation);
      }
      // 単位行列の取得
      auto worldMatrix = Matrix44::Identity();
      worldMatrix.MulScaling(scale); // スケーリング
      worldMatrix.RotateZ(rotation.GetZ()); // Z軸回転
      worldMatrix.RotateY(rotation.GetY()); // Y軸回転
      worldMatrix.RotateX(rotation.GetX()); // X軸回転
      worldMatrix.MulTranslate(position); // 平行移動
      return worldMatrix;
    }

    Vector4 Utility::RotationToRadian(const Vector4& rotation) {
      // 各種成分の取得
      auto [x, y, z] = rotation.GetVector3();
      // 各成分をラジアンに変換する
      x = DegreeToRadian(x);
      y = DegreeToRadian(y);
      z = DegreeToRadian(z);
      return Vector4(x, y, z);
    }
  } // namespace Math
} // namespace AppFrame