/*****************************************************************//**
 * @file   GravityBase.cpp
 * @brief  �d�͏������s���ÓI�N���X�̒�`
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "GravityBase.h"
#include "Matrix44.h"
#include "Vector4.h"

namespace AppFrame{
  namespace Math {

    Matrix44 GravityBase::GravityImparted(float speed, float mass) {
      // ���ʂ��}�C�i�X���ǂ����̔���
      if(mass <= 0.0f) {
        // �}�C�i�X�̏ꍇ�͎��ʂ�0�ɂ���
        mass = 0.0f;
      }
      // �����x�ɏd�͉����x�����Z����
      speed += (_acceleration * mass);
      // ���s�ړ��s��̍쐬
      return Matrix44::Translate(0.0f, speed, 0.0f);
    }
  }
}