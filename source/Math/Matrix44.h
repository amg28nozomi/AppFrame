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
     * @brief �s��N���X
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
    private:
      MatrixArray _rowColumn; //!< �s��
    };
  } // namespace Math
} // namespace AppFrame