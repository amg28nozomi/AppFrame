/*****************************************************************//**
 * @file   GravityBase.cpp
 * @brief  重力の基底クラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "GravityBase.h"

namespace AppFrame{
  namespace Math {

    GravityBase::GravityBase(float acceleration) {
      _acceleration = acceleration;
    }
  }
}