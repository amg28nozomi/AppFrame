/*****************************************************************//**
 * @file   Math.h
 * @brief  算術処理クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once

namespace AppFrame {
  /** 算術処理用名前空間 */
  namespace Math {
    
    class Math {
    public:
      /**
       * @brief  値のクランプ処理
       * @tparam T      値の型
       * @param  value  クランプする値
       * @param  low    下限
       * @param  height 上限
       * @return クランプした値を返す
       */
      template <typename T>
      static T Clamp(const T value, const T low, const T height);
    };
  } // namespace Math
} // namespace AppFrame