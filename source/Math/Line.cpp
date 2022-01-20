/*****************************************************************//**
 * @file   Line.cpp
 * @brief  ü•ªƒNƒ‰ƒX‚Ì’è‹`
 * 
 * @author —é–ØŠóŠC
 * @date   January 2022
 *********************************************************************/
#include "Line.h"

namespace AppFrame {
  namespace Math {

    Line::Line() : _start(), _end() {
    }

    Line::Line(Vector4 start, Vector4 end) : _start(start), _end(end){
    }
  }
}