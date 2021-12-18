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
#include <charconv>
#include <stdexcept>
#include <typeinfo>
#include <vector>

namespace {
  constexpr auto Binary = 2;       // 2進数
  constexpr auto Decimal = 10;     // 10進数
  constexpr auto Hexadecimal = 16; // 16進数
}

namespace AppFrame {
  namespace Math {
    // デフォルトではint型、float型、double型のみ対応
    std::vector<std::string> Math::_clampType = { "int", "float", "double" };

    template <typename T>
    T Math::Clamp(const T value, const T low, const T height) {
      auto id = typeid(value).name(); // 引数の型
      auto flag = false; // 判定フラグ
//      // 引数の型は全て一致しているか？
//      bool accord = (id == typeid(low) == typeid(height));
//      if (!accord) {
//#ifdef _DEBUG
//        throw std::invalid_argument("Math::Clamp:引数の型が不正です。型は全て統一してください");
//#endif
//        return value; // 型が不正
//      }
      for (auto type : _clampType) {
        // 対象の型は対応しているか？
        if (id == type.data()) {
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

    std::string Math::ToBinary(int num) {
      std::string binary; // 2進数
      while (num != 0) {
        // 余りが出るか？
        binary += (num % Binary == 0 ? "0" : "1");
        num /= Binary;
      }
      return binary;
    }

    std::string Math::ToHexadecimal(int num) {
      std::string hexadecimal; // 16進数
      while (num != 0) {
        auto param = num % Hexadecimal; // 余剰
        hexadecimal += ToRemainder16(param); // 余剰を文字列に変換し、末尾に追加
        num /= Hexadecimal;
      }
      return hexadecimal;
    }

    int Math::ToInteger(std::string_view num) {
      return 0;
    }

    std::string Math::ToRemainder16(const int remainder) {
#ifdef _DEBUG
      // 引数は対象範囲に収まっているか？
      if (Hexadecimal <= remainder) {
        throw std::logic_error("Math::ToRemainder16:引数の値が対象範囲外です\n");
      }
#endif
      // 不具合対策用
      auto num = std::clamp(remainder, 0, 15);
      // 10以上の場合はそれぞれ対応するアルファベット
      // 10未満の場合は文字列に変換した値を返す
      switch (num) {
      case 15:
        return "F";
      case 14:
        return "E";
      case 13:
        return "D";
      case 12:
        return "C";
      case 11:
        return "B";
      case 10:
        return "A";
      default:
        return std::to_string(num);
      }
    }
  } // namespace Math
} // namespace AppFrame