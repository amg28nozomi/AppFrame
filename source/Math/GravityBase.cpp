/*****************************************************************//**
 * @file   GravityBase.cpp
 * @brief  重力処理を行う静的クラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "GravityBase.h"
#include "Matrix44.h"
#include "Vector4.h"

namespace AppFrame{
  namespace Math {

    Matrix44 GravityBase::GravityImparted(float speed, float mass) {
      // 質量がマイナスかどうかの判定
      if(mass <= 0.0f) {
        // マイナスの場合は質量を0にする
        mass = 0.0f;
      }
      // 加速度に重力加速度を加算する
      speed += (_acceleration * mass);
      // 平行移動行列の作成
      return Matrix44::Translate(0.0f, speed, 0.0f);
    }
  }
}