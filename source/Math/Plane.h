/*****************************************************************//**
 * @file   Plane.h
 * @brief  平面クラス
 * 
 * @author 鈴木希海
 * @date   February 2022
 *********************************************************************/
#pragma once
/**
 * @brief アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief 算術ベース
   */
  namespace Math {
    class Vector4; //!< 前方宣言
    /**
     * @class Plane
     * @brief 平面クラス
     */
    class Plane {
    public:
      /**
       * @brief コンストラクタ
       * @param a 点A
       * @param b 点B
       * @param c 点C
       */
      Plane(const Vector4& a, const Vector4& b, const Vector4& c);
      /**
       * @brief  
       * @param  point
       * @return 
       */
      float SignedDist(const Vector4& point) const;
    private:
      Vector4 _normal;  //!< 法線
      float _mDistance; //!<最短距離
    };
  } // namespace Math
} // namespace AppFrame