/*****************************************************************//**
 * @file   Vector4.h
 * @brief  �l�����x�N�g���N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <tuple>

namespace AppFrame {
  namespace Math {
    /**
     * @class Vector4
     * @brief �l�����x�N�g��
     */
    class Vector4 {
    public:
      /**
       * @brief ��x�N�g���̐���
       */
      Vector4();
      /**
       * @brief �x�N�g���̐���
       * @param x x����
       * @param y y����
       * @param z z����
       * @param w w����(�f�t�H���g�ł�1.0)
       */
      Vector4(float x, float y, float z, float w = 1.0);
      /**
       * @brief �x�N�g�����m�̉��Z
       * @param vector �x�N�g��(����)
       */
      void Add(const Vector4 vector);
      /**
       * @brief �x�N�g���̉��Z
       * @param x x����
       * @param y y����
       * @param z z����
       */
      void Add(const float x, const float y, const float z);
      /**
       * @brief �x�N�g�����m�̌��Z
       * @param vector �x�N�g��(����)
       */
      void Sub(const Vector4 vector);
      /**
       * @brief �x�N�g���̌��Z
       * @param x x����
       * @param y y����
       * @param z z����
       */
      void Sub(const float x, const float y, const float z);
      /**
       * @brief  2�����x�N�g���̎擾
       * @return xy������Ԃ�
       */
      const auto GetVector2() {
        return std::make_pair(_x, _y);
      }
      /**
       * @brief  3�����x�N�g���̎擾
       * @return xyz������Ԃ�
       */
      const auto GetVector3() {
        return std::make_tuple(_x, _y, _z);
      }
      /**
       * @brief  4�����x�N�g���̎擾
       * @return 
       */
      const auto GetVector4() {
        return std::make_tuple(_x, _y, _z, _w);
      }
      /**
       * @brief  x�����̎擾
       * @return x����
       */
      const float GetX() {
        return _x;
      }
      /**
       * @brief  y�����̎擾
       * @return y����
       */
      const float GetY() {
        return _y;
      }
      /**
       * @brief  z�����̎擾
       * @return z����
       */
      const float GetZ() {
        return _z;
      }
      /**
       * @brief  w�����̎擾
       * @return w����
       */
      const float GetW() {
        return _w;
      }
      /**
       * @brief  �x�N�g���̒����̎擾
       * @return �x�N�g���̒���
       */
      float Length() const;
      /**
       * @brief  �x�N�g���̐��K��
       */
      void Normalize();
      /**
       * @brief  �P�ʃx�N�g���̎擾
       * @return �P�ʃx�N�g��
       */
      Vector4 Normalize() const;
      /**
       * @brief  �x�N�g�����m�̓���
       * @param  vector �x�N�g��
       * @return ����
       */
      float Dot(const Vector4 vecotr) const;
      /**
       * @brief  �x�N�g���̊O��
       * @param  vector �x�N�g��
       * @return �x�N�g��
       */
      Vector4 Cross(const Vector4 vector) const;
      /**
       * @brief  �w�肵���l��xyz�����ɑ������
       * @param  value �l
       */
      void Fill(const float value);
      /**
       * @brief  �x�N�g�����m�̉��Z
       * @param  vector �x�N�g��(����)
       * @return ���Z����4�����x�N�g��
       */
      Vector4 operator + (const Vector4 vector);
      /**
       * @brief  �x�N�g�����m�̌��Z
       * @param  vector �x�N�g��(����)
       * @return ���Z����4�����x�N�g��
       */
      Vector4 operator - (const Vector4 vector) {
        auto x = _x - vector._x;
        auto y = _y - vector._y;
        auto z = _z - vector._z;
        return Vector4(x, y, z);
      }
      /**
       * @brief  �x�N�g���̃X�J���[�{
       * @param  scalar �X�J���[�l
       * @return �X�J���[�{����4�����x�N�g��
       */
      Vector4 operator * (const float scalar) {
        auto x = _x * scalar;
        auto y = _y * scalar;
        auto z = _z * scalar;
        return Vector4(x, y, z);
      }
      /**
       * @brief  �x�N�g���̃X�J���[����
       * @param  scalar �X�J���[�l
       * @return �X�J���[���肵��4�����x�N�g��
       */
      Vector4 operator/(const float scalar);
    private:
      float _x; //!< x����
      float _y; //!< y����
      float _z; //!< z����
      float _w; //!< w����
    };
  } // namespace Math
} // namespace AppFrame