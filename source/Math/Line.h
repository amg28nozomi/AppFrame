/*****************************************************************//**
 * @file   Line.h
 * @brief  線分クラス
 * 
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#pragma once
#include <utility>
#include "Vector4.h"

namespace AppFrame {
  namespace Math {
    /**
     * @class Line
     * @brief 線分ベクトル
     */
    class Line {
    public:
      /**
       * @brief 空のコンストラクタ
       */
      Line();
      /**
       * @brief コンストラクタ
       */
      Line(Vector4 first, Vector4 end);
      /**
       * @brief  ベクトルの取得
       * @return first:先端 second:終端
       */
      std::pair<Vector4, Vector4> GetVector() const {
        return std::make_pair(_start, _end);
      }
      /**
       * @brief  先端ベクトルの取得
       * @return 先端ベクトル
       */
      Vector4 GetStart() const {
        return _start;
      }
      /**
       * @brief  終端ベクトルの取得
       * @return 終端ベクトル
       */
      Vector4 GetEnd() const {
        return _end;
      }
    private:
      Vector4 _start; //!< 先端ベクトル
      Vector4 _end;   //!< 終端ベクトル
    };
  } // namespace Math
} // namespace AppFrame