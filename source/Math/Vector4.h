/*****************************************************************//**
 * @file   Vector4.h
 * @brief  四次元ベクトルクラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <tuple>

namespace AppFrame {
  namespace Math {
    /**
     * @class Vector4
     * @brief 四次元ベクトル
     */
    class Vector4 {
    public:
      /**
       * @brief 空ベクトルの生成
       */
      Vector4();
      /**
       * @brief ベクトルの生成
       * @param x x成分
       * @param y y成分
       * @param z z成分
       * @param w w成分(デフォルトでは1.0)
       */
      Vector4(float x, float y, float z, float w = 1.0);
      /**
       * @brief ベクトル同士の加算
       * @param vector ベクトル(加数)
       */
      void Add(const Vector4 vector);
      /**
       * @brief ベクトルの加算
       * @param x x成分
       * @param y y成分
       * @param z z成分
       */
      void Add(const float x, const float y, const float z);
      /**
       * @brief ベクトル同士の減算
       * @param vector ベクトル(減数)
       */
      void Sub(const Vector4 vector);
      /**
       * @brief ベクトルの減算
       * @param x x成分
       * @param y y成分
       * @param z z成分
       */
      void Sub(const float x, const float y, const float z);
      /**
       * @brief  2次元ベクトルの取得
       * @return xy成分を返す
       */
      inline const auto GetVector2() const {
        return std::make_pair(_x, _y);
      }
      /**
       * @brief  3次元ベクトルの取得
       * @return xyz成分を返す
       */
      inline const auto GetVector3() const {
        return std::make_tuple(_x, _y, _z);
      }
      /**
       * @brief  4次元ベクトルの取得
       * @return xyzw成分
       */
      inline const auto GetVector4() const {
        return std::make_tuple(_x, _y, _z, _w);
      }
      /**
       * @brief  x成分の取得
       * @return x成分
       */
      inline const float GetX() const {
        return _x;
      }
      /**
       * @brief  y成分の取得
       * @return y成分
       */
      inline const float GetY() const {
        return _y;
      }
      /**
       * @brief  z成分の取得
       * @return z成分
       */
      inline const float GetZ() const {
        return _z;
      }
      /**
       * @brief  w成分の取得
       * @return w成分
       */
      inline const float GetW() const {
        return _w;
      }
      /**
       * @brief  ベクトルの長さの取得
       * @return ベクトルの長さ
       */
      float Length() const;
      /**
       * @brief  ベクトルの正規化
       */
      void Normalize();
      /**
       * @brief  単位ベクトルの取得
       * @return 単位ベクトル
       */
      Vector4 Normalize() const;
      /**
       * @brief  ベクトル同士の内積
       * @param  vector ベクトル
       * @return 内積
       */
      float Dot(const Vector4 vecotr) const;
      /**
       * @brief  ベクトルの外積
       * @param  vector ベクトル
       * @return ベクトル
       */
      Vector4 Cross(const Vector4 vector) const;
      /**
       * @brief  指定した値をxyz成分に代入する
       * @param  value 値
       */
      void Fill(const float value);
      /**
       * @brief  ベクトル同士の加算
       * @param  vector ベクトル(加数)
       * @return 加算した4次元ベクトル
       */
      Vector4 operator + (const Vector4 vector);
      /**
       * @brief  ベクトル同士の減算
       * @param  vector ベクトル(減数)
       * @return 減算した4次元ベクトル
       */
      Vector4 operator - (const Vector4 vector);
      /**
       * @brief  ベクトルのスカラー倍
       * @param  scalar スカラー値
       * @return スカラー倍した4次元ベクトル
       */
      Vector4 operator * (const float scalar);
      /**
       * @brief  ベクトルのスカラー割り
       * @param  scalar スカラー値
       * @return スカラー割りした4次元ベクトル
       */
      Vector4 operator/(const float scalar);
    private:
      float _x; //!< x成分
      float _y; //!< y成分
      float _z; //!< z成分
      float _w; //!< w成分
    };
  } // namespace Math
} // namespace AppFrame