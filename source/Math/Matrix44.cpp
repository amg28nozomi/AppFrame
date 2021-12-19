/*****************************************************************//**
 * @file   Matrix44.cpp
 * @brief  4*4�s��N���X�̒�`
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "Matrix44.h"

namespace AppFrame {
  namespace Math {

    Matrix44::Matrix44() {
      Reset(_rowColumn);
    }

    Matrix44::Matrix44(const MatrixArray values) {
      _rowColumn = values;
    }

    void Matrix44::Reset(MatrixArray& matrix) {
      for (auto&& values : matrix) {
        values.fill(0.0);
      }
    }

  } // namespace Math
} // namespace AppFrame