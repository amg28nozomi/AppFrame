/*****************************************************************//**
 * @file   Utility.h
 * @brief  算術処理用の補助機能クラス
 *
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#pragma once
#include <numbers>
/**
 * @brief アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief 算術処理ベース
   */
  namespace Math {
    /**
     * @class Utility
     * @brief 算術処理用の補助機能
     */
    class Utility {
    public:
      //!< 円周率PIの定数
      static constexpr float _pi{static_cast<float>(std::numbers::pi)};
      //!< 
      static constexpr float _degrees180{180.0f};
      /**
       * @brief  デグリー値をラジアン値に変換する
       * @param  degree デグリー値
       * @return ラジアン値
       */
      static inline float DegreeToRadian(float degree) {
        return degree * _pi / _degrees180;
      }
      /**
       * @brief  ラジアン値をデグリー値に変換する
       * @param  radian ラジアン値
       * @return デグリー値
       */
      static inline float RadianToDegree(float radian) {
        return radian * _degrees180 / _pi;
      }
    };
  } // namespace Math
} // namespace AppFrame