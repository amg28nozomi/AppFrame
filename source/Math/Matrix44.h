/*****************************************************************//**
 * @file   Matrix44.h
 * @brief  4*4�s��N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <array>

namespace AppFrame {
  namespace Math {
    constexpr auto MaxRow = 4;    //!< �s�̏��
    constexpr auto MaxColumn = 4; //!< ��̏��
    /**
     * @class Matrix4x4
     * @brief 4*4�s��N���X
     */
    class Matrix44 {
    private:
      /** float�^��4*4�s���\��2�����z�� */
      using MatrixArray = std::array<std::array<float, MaxColumn>, MaxRow>;
    public:
      /**
       * @brief ��̍s��𐶐�
       */
      Matrix44();
      /**
       * @brief �s��̃R�s�[
       * @param values 
       */
      Matrix44(const MatrixArray values);
      /**
       * @brief �s��̍폜
       */
      ~Matrix44() = default;
      /**
       * @brief  �s��̍Đݒ�
       * @param  matrix �s��N���X�̎Q��
       * @return �����������s���Ԃ�
       */
      static void Reset(MatrixArray& matrix);
      /**
       * @brief  �P�ʍs��̍쐬
       * @return �P�ʍs��
       */
      static Matrix44 Identyty();
      /**
       * @brief  ���s�ړ��s��̎擾
       * @param  x x�������x�N�g��
       * @param  y y�������x�N�g��
       * @param  z z�����s�x�N�g��
       * @return ���s�ړ��s��
       */
      static Matrix44 Translate(float x, float y, float z);
      /**
       * @brief  �g��k���s��̎擾
       * @param  x
       * @param  y
       * @param  z
       * @return �g��k���s��
       */
      static Matrix44 Scaling(float x, float y, float z);
      /**
       * @brief  ��]�s��(x��)
       * @param  angle 
       */
      void RotateX(float angle);
      /**
       * @brief  ��]�s��(y��)
       * @param  angle
       */
      void RotateY(float angle);
      /**
       * @brief  ��]�s��(z��)
       * @param  angle
       */
      void RotateZ(float angle);
    private:
      MatrixArray _rowColumn; //!< �s��
    };
  } // namespace Math
} // namespace AppFrame