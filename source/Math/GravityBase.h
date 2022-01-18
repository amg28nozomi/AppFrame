/*****************************************************************//**
 * @file   GravityBase.h
 * @brief  重力処理を行う静的クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
/**
 * @brief アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief マスベース
   */
  namespace Math {
    class Matrix44; //!< 前方宣言
    constexpr auto DefaultAcceleration = -9.8f; //!< デフォルトの重力加速度
    /**
     * @class GravityBase
     * @brief 重力の基底クラス
     */
    class GravityBase {
    public:
      /**
       * @brief  重力加速度を表す平行移動行列を取得する
       * @param  speed 対象の加速度
       * @param  mass  対象の質量
       * @return 加速度を表す平行移動行列を返す
       */
      static Matrix44 GravityImparted(float speed, float mass);
      /**
       * @brief  重力加速度の取得
       * @return 重力加速度
       */
      static inline float Acceleration() {
        return _acceleration;
      }
    protected:
      static inline float _acceleration{DefaultAcceleration}; //!< 重力加速度
    };
  } // namespace Math
} // namespace AppFrame

