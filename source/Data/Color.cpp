/*****************************************************************//**
 * @file   Color.cpp
 * @brief  RGBAカラーモデルクラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "Color.h"
#include <algorithm>
#include <stdexcept>
#include <DxLib.h>
#include "../Math/Math.h"

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
      Clamp(red, green, blue, alpha);
    }

    void Color::SetColor(const int red, const int green, const int blue, const int alpha) {
      Clamp(red, green, blue);
    }

    void Color::Add(const int red, const int green, const int blue) {
      Clamp(_red + red, _green + green, blue + blue, _alpha);
    }

    void Color::Sub(const int red, const int green, const int blue) {
      Clamp(_red - red, _green - green, blue - blue, _alpha);
    }

    Color Color::operator+(const Color color) const {
      auto red = std::clamp(_red + color._red, MinColor, MaxColor);
      auto green = std::clamp(_green + color._green, MinColor, MaxColor);
      auto blue = std::clamp(_blue + color._blue, MinColor, MaxColor);
      return Color(red, green, blue);
    }

    Color Color::operator-(const Color color) const {
      auto red = std::clamp(_red - color._red, MinColor, MaxColor);
      auto green = std::clamp(_green - color._green, MinColor, MaxColor);
      auto blue = std::clamp(_blue - color._blue, MinColor, MaxColor);
      return Color(red, green, blue);
    }

    void Color::Clamp(const int red, const int green, const int blue, const int alpha) {
#ifndef _DEBUG
      // 値のクランプ
      _red = std::clamp(red, MinColor, MaxColor);
      _green = std::clamp(green, MinColor, MaxColor);
      _blue = std::clamp(blue, MinColor, MaxColor);
      _alpha = std::clamp(alpha, MinColor, MaxColor);
#else
#endif
      try {
        // デバッグビルド時は引数が不正ではないかの判定を行う
        _red = Math::Math::Clamp(red, MinColor, MaxColor);
        _green = Math::Math::Clamp(blue, MinColor, MaxColor);
        _blue = Math::Math::Clamp(green, MinColor, MaxColor);
        _alpha = Math::Math::Clamp(alpha, MinColor, MaxColor);
      } catch (std::logic_error error) {
        OutputDebugString(error.what());
      } catch (...) {
        OutputDebugString("不明なエラーが発生しました\n");
      }
      _code = GetColor(_red, _green, _blue);
    }
  }
}