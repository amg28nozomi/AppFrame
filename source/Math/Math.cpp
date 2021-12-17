/*****************************************************************//**
 * @file   Math.h
 * @brief  算術処理クラス
 *
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "Math.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <typeinfo>
#include <vector>
#include <Windows.h>

namespace {
}

namespace AppFrame {
  namespace Math {
    // デフォルトではint型、float型、double型のみ対応
    std::vector<std::string> Math::_clampType = { "int", "float", "double" };

    template <typename T>
    T Math::Clamp(const T value, const T low, const T height) {
      const auto id = typeid(value); // 引数の型
      auto flag = false; // 判定フラグ
      // 引数の型は全て一致しているか？
      bool accord = (id == typeid(low) == typeid(height));
      if (!accord) {
#ifdef _DEBUG
        throw std::invalid_argument("Math::Clamp:引数の型が不正です。型は全て統一してください");
#endif
        return value; // 型が不正
      }
      for (auto type : _clampType) {
        // 対象の型は対応しているか？
        if (id == type) {
          flag = true; // 型が一致
          break;
        }
      }
#ifndef _DEBUG
      if (!flag) {
        return value; // 型が対応していない
      }
#else
      if (!flag) {
        throw std::invalid_argument("Math::Clamp:引数の型が不正です。" + std::to_string(id) + "型は対応していません");
        return value;
      }
      // 値は範囲内に収まっているか
      if (value < low) {
        throw std::logic_error("値が下限を下回りました value:" + std::to_string(value) + " low:" + std::to_string(low));
      }
      else if (height < value) {
        throw std::logic_error("値が上限を超過しました value:" + std::to_string(value) + " height:" + std::to_string(height));
      }
#endif
      return std::clamp(value, low, height);
    }
  } // namespace Math
} // namespace AppFrame