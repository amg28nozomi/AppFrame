/*****************************************************************//**
 * @file   Math.h
 * @brief  算術処理クラス
 *
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "Math.h"
#include <string>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <Windows.h>

namespace AppFrame {
  namespace Math {

    template <typename T>
    T Math::Clamp(const T value, const T low, const T height) {
      std::string message;
#ifdef _DEBUG
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
  } // namespace AppFrame
} // namespace Math