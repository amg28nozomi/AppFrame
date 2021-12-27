/*****************************************************************//**
 * @file   GravityBase.h
 * @brief  �d�͂̊��N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once

namespace AppFrame {
  namespace Math {
    constexpr auto DefaultAcceleration = -9.8f; //!< �f�t�H���g�̏d�͉����x
    /**
     * @class GravityBase
     * @brief �d�͂̊��N���X
     */
    class GravityBase {
    public:
      /**
       * @brief �R���X�g���N�^
       * @param acceleration �d�͉����x(�f�t�H���g��9.8f)
       */
      GravityBase(float acceleration = DefaultAcceleration);


      /**
       * @brief  �d�͉����x�̎擾
       * @return �d�͉����x
       */
      inline float Acceleration() const {
        return _acceleration;
      }
    protected:
      float _acceleration; //!< �d�͉����x
    };
  } // namespace Math
} // namespace AppFrame

