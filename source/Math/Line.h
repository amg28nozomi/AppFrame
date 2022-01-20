/*****************************************************************//**
 * @file   Line.h
 * @brief  �����N���X
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#pragma once
#include <utility>
#include "Vector4.h"

namespace AppFrame {
  namespace Math {
    /**
     * @class Line
     * @brief �����x�N�g��
     */
    class Line {
    public:
      /**
       * @brief ��̃R���X�g���N�^
       */
      Line();
      /**
       * @brief �R���X�g���N�^
       */
      Line(Vector4 first, Vector4 end);
      /**
       * @brief  �x�N�g���̎擾
       * @return first:��[ second:�I�[
       */
      std::pair<Vector4, Vector4> GetVector() const {
        return std::make_pair(_start, _end);
      }
      /**
       * @brief  ��[�x�N�g���̎擾
       * @return ��[�x�N�g��
       */
      Vector4 GetStart() const {
        return _start;
      }
      /**
       * @brief  �I�[�x�N�g���̎擾
       * @return �I�[�x�N�g��
       */
      Vector4 GetEnd() const {
        return _end;
      }
    private:
      Vector4 _start; //!< ��[�x�N�g��
      Vector4 _end;   //!< �I�[�x�N�g��
    };
  } // namespace Math
} // namespace AppFrame