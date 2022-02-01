/*****************************************************************//**
 * @file   Utility.cpp
 * @brief  �Z�p�����p�̕⏕�@�\�N���X�̒�`
 *
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#include "Utility.h"
#include "Matrix44.h"
#include "Vector4.h"

namespace AppFrame{
  namespace Math {

    Matrix44 Utility::ToWorldMatrix(const Vector4& position, Vector4 rotation, const Vector4& scale, const bool angle) {
      // rotation���f�O���[�l�̏ꍇ�̓��W�A���l�ɕϊ�����
      if (angle) {
        rotation = RotationToRadian(rotation);
      }
      // �P�ʍs��̎擾
      auto worldMatrix = Matrix44::Identity();
      worldMatrix.MulScaling(scale); // �X�P�[�����O
      worldMatrix.RotateZ(rotation.GetZ()); // Z����]
      worldMatrix.RotateY(rotation.GetY()); // Y����]
      worldMatrix.RotateX(rotation.GetX()); // X����]
      worldMatrix.MulTranslate(position); // ���s�ړ�
      return worldMatrix;
    }

    Vector4 Utility::RotationToRadian(const Vector4& rotation) {
      // �e�퐬���̎擾
      auto [x, y, z] = rotation.GetVector3();
      // �e���������W�A���ɕϊ�����
      x = DegreeToRadian(x);
      y = DegreeToRadian(y);
      z = DegreeToRadian(z);
      return Vector4(x, y, z);
    }
  } // namespace Math
} // namespace AppFrame