/*****************************************************************//**
 * @file   Math.h
 * @brief  算術処理クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <string>
#include <vector>

namespace AppFrame {
  /** 算術処理用名前空間 */
  namespace Math {
    /**
     * @class Math
     * @brief 算術処理用クラス
     */
    class Math {
    public:
      /**
       * @brief  値のクランプ処理
       * @tparam T      引数の型
       *                int、float、double型ではない場合は処理を中断
       * @param  value  クランプする値
       * @param  low    下限
       * @param  height 上限
       * @return クランプした値
       *         条件を満たしていない場合はvalueを返す
       * @throw  std::logic_error std::invalid_argument
       */
      template <typename T>
      static T Clamp(const T value, const T low, const T height);
      /**
       * @brief  クランプ処理に対応している型の取得
       * @return 対応している型を文字列で保持するコンテナ
       */
      static inline auto GetClampType() {
        return _clampType;
      }
    private:
      static std::vector<std::string> _clampType; //!< Clampメソッドに対応している型
    };
  } // namespace Math
} // namespace AppFrame