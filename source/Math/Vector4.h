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
      inline const auto GetVector2() const {
        return std::make_pair(_x, _y);
      }
      /**
       * @brief  3�����x�N�g���̎擾
       * @return xyz������Ԃ�
       */
      inline const auto GetVector3() const {
        return std::make_tuple(_x, _y, _z);
      }
      /**
       * @brief  4�����x�N�g���̎擾
       * @return xyzw����
       */
      inline const auto GetVector4() const {
        return std::make_tuple(_x, _y, _z, _w);
      }
      /**
       * @brief  x�����̎擾
       * @return x����
       */
      inline const float GetX() const {
        return _x;
      }
      /**
       * @brief  y�����̎擾
       * @return y����
       */
      inline const float GetY() const {
        return _y;
      }
      /**
       * @brief  z�����̎擾
       * @return z����
       */
      inline const float GetZ() const {
        return _z;
      }
      /**
       * @brief  w�����̎擾
       * @return w����
       */
      inline const float GetW() const {
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
      Vector4 operator - (const Vector4 vector);
      /**
       * @brief  �x�N�g���̃X�J���[�{
       * @param  scalar �X�J���[�l
       * @return �X�J���[�{����4�����x�N�g��
       */
      Vector4 operator * (const float scalar);
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