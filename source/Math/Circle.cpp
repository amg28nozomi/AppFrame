/*****************************************************************//**
 * @file   Circle.cpp
 * @brief  ‰~ƒNƒ‰ƒX‚Ì’è‹`
 * 
 * @author —é–ØŠóŠC
 * @date   February 2022
 *********************************************************************/
#include "Circle.h"
#include "Vector4.h"

namespace AppFrame {
  namespace Math {

    Circle::Circle(const Vector4& center, const float radius) {
      _center = center;
      _radius = radius;
    }

  } // namespace Math
} // namespaece AppFrame