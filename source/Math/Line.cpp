/*****************************************************************//**
 * @file   Line.cpp
 * @brief  線分クラスの定義
 * 
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#include "Line.h"
#include "Vector4.h"

namespace AppFrame {
  namespace Math {

    Line::Line() : _start(), _end() {
    }

    Line::Line(Vector4 start, Vector4 end) : _start(start), _end(end){
    }
  }
}