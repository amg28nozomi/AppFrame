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
       * @brief  10進数値を2進数値に変換
       * @param  num 10進数値
       * @return 引数を2進数で表した文字列
       */
      static std::string ToBinary(int num);
      /**
       * @brief  10進数値を16進数値に変換
       * @param  num  10進数値
       * @param  flag true:文字列で取得(デフォルト) false:整数値で取得 
       * @return numを16進数に変換した値
       */
      static std::string ToHexadecimal(int num);
      /**
       * @brief  数字文字列をint型の数値に変換する
       * @param  num 数字文字列
       * @return 数値
       */
      static int ToInteger(std::string_view num);
      /**
       * @brief  クランプ処理に対応している型の取得
       * @return 対応している型を文字列で保持するコンテナ
       */
      static inline auto GetClampType() {
        return _clampType;
      }
    private:
      static std::vector<std::string> _clampType; //!< Clampメソッドに対応している型
      /**
       * @brief  余りを指定した16進数文字列に変換する
       * @param  remainder 剰余
       * @return 16進数文字列
       */
      static std::string ToRemainder16(const int remainder);
    };
  } // namespace Math
} // namespace AppFrame