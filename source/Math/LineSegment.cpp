/*****************************************************************//**
 * @file   LineSegment.cpp
 * @brief  �����N���X�̒�`
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#include "LineSegment.h"
#include "Arithmetic.h"
#include "Vector4.h"
#include "Plane.h"

namespace AppFrame {
  namespace Math {

    LineSegment::LineSegment() : _start(), _end() {
    }

    LineSegment::LineSegment(Vector4 start, Vector4 end) : _start(start), _end(end){
    }

    float LineSegment::Length() const {
      // ������Ԃ�
      return (_end - _start).Length();
    }

    float LineSegment::LengthSquared() const {
      return (_end - _start).LengthSquared();
    }

    float LineSegment::MinDistSq(const Vector4& point) const {
      // �e��x�N�g��
      auto lineA = _end - _start; // �x�N�g���̒���
      auto LineB = lineA * -1.0f;
      auto sC = point - _start;
      auto endC = point - _end;
      // 
      if (Vector4::Dot(lineA, sC) < 0.0f) {
        return sC.LengthSquared(); // �����̓���Ԃ�
      }
      else if (Vector4::Dot(LineB, endC) < 0.0f) {
        return endC.LengthSquared();
      }
      auto scalar = Vector4::Dot(sC, lineA) / Vector4::Dot(lineA, lineA);
      auto p = lineA * scalar;
      return (sC - p).LengthSquared();
    }

    bool LineSegment::IntersectPlane(const Plane& plane) const {
      auto pNormal = plane.GetNormal();
      auto d = Vector4::Dot(Segment(), pNormal);
      // ���ʂƐ����͕��s��
      if (Arithmetic::NearZero(d)) {
        if (Arithmetic::NearZero(Vector4::Dot(_start, pNormal) - plane.GetDistance())) {
          return true; // �Փ�
        }
        return false; // �Փ˂��Ă��Ȃ�
      }
      auto numer = -Vector4::Dot(_start, pNormal) - plane.GetDistance();
      auto t = numer / d;
      // t�������̋��E���ɑ��݂��邩
      if (0.0f <= t && t <= 1.0f) {
        return true; // �Փ˂���
      }
      return false;  // �Փ˂��Ă��Ȃ�
    }

    //float LineSegment::MinDistSq(const LineSegment& line) const {
    //  // �����͏k�ނ��Ă��邩
    //  if (LengthSquared() < 0.0f) {
    //    // �Ώۂ̐����͏k�ނ��Ă��邩
    //    if (line.LengthSquared() < 0.0f) {
    //      // �_�Ɠ_�̋������Z�o����
    //      return (_start - line._start).LengthSquared();
    //    }
    //    // �����Ɠ_�̍ŒZ����(���)��Ԃ�
    //    return line.MinDistSq(_start);
    //  }
    //  // �Ώۂ̐������k�ނ��Ă��邩
    //  else if (line.LengthSquared() < 0.0f) {
    //    return MinDistSq(line._start);
    //  }
    //  // �������m�����s�ȏꍇ
    //  if (Vector4::IsParallel(_start, line._start)) {

    //  }
    //}
  }
}