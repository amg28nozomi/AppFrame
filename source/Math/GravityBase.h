/*****************************************************************//**
 * @file   GravityBase.h
 * @brief  重力の基底クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once

namespace AppFrame {
  namespace Math {
    constexpr auto DefaultAcceleration = -9.8f; //!< デフォルトの重力加速度
    /**
     * @class GravityBase
     * @brief 重力の基底クラス
     */
    class GravityBase {
    public:
      /**
       * @brief コンストラクタ
       * @param acceleration 重力加速度(デフォルトは9.8f)
       */
      GravityBase(float acceleration = DefaultAcceleration);


      /**
       * @brief  重力加速度の取得
       * @return 重力加速度
       */
      inline float Acceleration() const {
        return _acceleration;
      }
    protected:
      float _acceleration; //!< 重力加速度
    };
  } // namespace Math
} // namespace AppFrame

