/*****************************************************************//**
 * @file   Utility.h
 * @brief  �Z�p�����p�̕⏕�@�\�N���X
 *
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#pragma once
#include <numbers>
/**
 * @brief �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief �Z�p�����x�[�X
   */
  namespace Math {
    /**
     * @class Utility
     * @brief �Z�p�����p�̕⏕�@�\
     */
    class Utility {
    public:
      //!< �~����PI�̒萔
      static constexpr float _pi{static_cast<float>(std::numbers::pi)};
      //!< 
      static constexpr float _degrees180{180.0f};
      /**
       * @brief  �f�O���[�l�����W�A���l�ɕϊ�����
       * @param  degree �f�O���[�l
       * @return ���W�A���l
       */
      static inline float DegreeToRadian(float degree) {
        return degree * _pi / _degrees180;
      }
      /**
       * @brief  ���W�A���l���f�O���[�l�ɕϊ�����
       * @param  radian ���W�A���l
       * @return �f�O���[�l
       */
      static inline float RadianToDegree(float radian) {
        return radian * _degrees180 / _pi;
      }
    };
  } // namespace Math
} // namespace AppFrame