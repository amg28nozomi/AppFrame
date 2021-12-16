/*****************************************************************//**
 * @file   Color.cpp
 * @brief  RGBAカラーモデルクラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "Color.h"
#include <algorithm>
#include <DxLib.h>

namespace {
  constexpr auto MinLuminace = 0;
  constexpr auto MaxLuminace = 255;
}

namespace AppFrame {
  namespace Data {

    Color::Color() {
      _red = 0;
      _green = 0;
      _blue = 0;
      _alpha = 0;
      _code = 0;
    }

    Color::Color(const int red, const int green, const int blue, const int alpha) {
      _red = std::clamp(red, MinLuminace, MaxLuminace);
      _green = std::clamp(green, MinLuminace, MaxLuminace);
      _blue = std::clamp(blue, MinLuminace, MaxLuminace);
      _alpha = std::clamp(alpha, MinLuminace, MaxLuminace);
      _code = GetColor(red, green, blue);
    }
  }
}