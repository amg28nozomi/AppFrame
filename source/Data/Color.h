/*****************************************************************//**
 * @file   Color.h
 * @brief  RGBA�J���[���f���N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <tuple>

namespace AppFrame {
  namespace Data {

    constexpr auto MaxColor = 255; //!< �F�̏��
    constexpr auto MinColor = 0;   //!< �F�̉���
    /**
     * @class Color
     * @brief RGBA�J���[���
     */
    class Color {
    public:
      /**
       * @brief RGBA�J���[���̐ݒ�
       */
      Color();
      /**
       * @brief RGBA�J���[���̐���
       * @param red   ��
       * @param green ��
       * @param blue  ��
       * @param alpha ���ߓx
       */
      Color(const int red, const int green, const int blue, const int alpha);
      /**
       * @brief  �e�P�x�̎擾
       * @return RGB�l
       */
      inline const auto GetLuminace() const {
        return std::make_tuple(_red, _green, _blue);
      }
      
      /**
       * @brief  RGBA�l�̎擾
       * @return 
       */
      inline const auto GetRgba() const {
        return std::make_tuple(_red, _green, _blue, _alpha);
      }
      /**
       * @brief  �P�x�l(��)�̎擾
       * @return �Ԃ̋P�x�l
       */
      inline const int GetRed() const {
        return _red;
      }
      /**
       * @brief  �P�x�l(��)�̎擾
       * @return �Ԃ̋P�x�l
       */
      inline const int GetGreen() const {
        return _green;
      }
      /**
       * @brief  �P�x�l(��)�̎擾
       * @return �Ԃ̋P�x�l
       */
      inline const int GetBlue() const {
        return _blue;
      }
      /**
       * @brief  �A���t�@�l�̎擾
       * @return �A���t�@�l
       */
      inline const int GetAlpha() const {
        return _alpha;
      }
      /**
       * @brief  �J���[�R�[�h�̎擾
       * @return �J���[�R�\�h
       */
      inline const int GetColorCode() const {
        return _code;
      }
    private:
      int _red;   //!< �P�x�l(��)
      int _green; //!< �P�x�l(��)
      int _blue;  //!< �P�x�l(��)
      int _alpha; //!< �����x
      int _code;  //!< �J���[�R�[�h
    };
  }
}

