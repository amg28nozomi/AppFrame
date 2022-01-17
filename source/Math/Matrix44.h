/*****************************************************************//**
 * @file   Matrix44.h
 * @brief  4*4sñNX
 * 
 * @author éØóC
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <array>

namespace AppFrame {
  namespace Math {
    constexpr auto MaxRow = 4;    //!< sÌãÀ
    constexpr auto MaxColumn = 4; //!< ñÌãÀ
    /**
     * @class Matrix4x4
     * @brief 4*4sñNX
     */
    class Matrix44 {
    private:
      /** float^Ì4*4sñð\·2³zñ */
      using MatrixArray = std::array<std::array<float, MaxColumn>, MaxRow>;
    public:
      /**
       * @brief óÌsñð¶¬
       */
      Matrix44();
      /**
       * @brief sñÌRs[
       * @param values 
       */
      Matrix44(const MatrixArray values);
      /**
       * @brief sñÌí
       */
      ~Matrix44() = default;
      /**
       * @brief  sñÌÄÝè
       * @param  matrix sñNXÌQÆ
       * @return ú»µ½sñðÔ·
       */
      static void Reset(MatrixArray& matrix);
      /**
       * @brief  PÊsñÌì¬
       * @return PÊsñ
       */
      static Matrix44 Identyty();
      /**
       * @brief  ½sÚ®sñÌæ¾
       * @param  x x²ûüxNg
       * @param  y y²ûüxNg
       * @param  z z²½sxNg
       * @return ½sÚ®sñ
       */
      static Matrix44 Translate(float x, float y, float z);
      /**
       * @brief  gåk¬sñÌæ¾
       * @param  x
       * @param  y
       * @param  z
       * @return gåk¬sñ
       */
      static Matrix44 Scaling(float x, float y, float z);
      /**
       * @brief  ñ]sñ(x²)
       * @param  angle 
       */
      void RotateX(float angle);
      /**
       * @brief  ñ]sñ(y²)
       * @param  angle
       */
      void RotateY(float angle);
      /**
       * @brief  ñ]sñ(z²)
       * @param  angle
       */
      void RotateZ(float angle);
    private:
      MatrixArray _rowColumn; //!< sñ
    };
  } // namespace Math
} // namespace AppFrame