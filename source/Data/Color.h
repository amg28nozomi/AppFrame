/*****************************************************************//**
 * @file   Color.h
 * @brief  RGBAカラーモデルクラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <tuple>

namespace AppFrame {
  namespace Data {

    constexpr auto MaxColor = 255; //!< 色の上限
    constexpr auto MinColor = 0;   //!< 色の下限
    /**
     * @class Color
     * @brief RGBAカラー情報
     */
    class Color {
    public:
      /**
       * @brief RGBAカラー情報の設定
       */
      Color();
      /**
       * @brief RGBAカラー情報の生成
       * @param red   赤
       * @param green 緑
       * @param blue  愛
       * @param alpha 透過度
       */
      Color(const int red, const int green, const int blue, const int alpha);
      /**
       * @brief  各輝度の取得
       * @return RGB値
       */
      inline const auto GetLuminace() const {
        return std::make_tuple(_red, _green, _blue);
      }
      
      /**
       * @brief  RGBA値の取得
       * @return 
       */
      inline const auto GetRgba() const {
        return std::make_tuple(_red, _green, _blue, _alpha);
      }
      /**
       * @brief  輝度値(赤)の取得
       * @return 赤の輝度値
       */
      inline const int GetRed() const {
        return _red;
      }
      /**
       * @brief  輝度値(緑)の取得
       * @return 赤の輝度値
       */
      inline const int GetGreen() const {
        return _green;
      }
      /**
       * @brief  輝度値(青)の取得
       * @return 赤の輝度値
       */
      inline const int GetBlue() const {
        return _blue;
      }
      /**
       * @brief  アルファ値の取得
       * @return アルファ値
       */
      inline const int GetAlpha() const {
        return _alpha;
      }
      /**
       * @brief  カラーコードの取得
       * @return カラーコ―ド
       */
      inline const int GetColorCode() const {
        return _code;
      }
    private:
      int _red;   //!< 輝度値(赤)
      int _green; //!< 輝度値(緑)
      int _blue;  //!< 輝度値(青)
      int _alpha; //!< 透明度
      int _code;  //!< カラーコード
    };
  }
}

