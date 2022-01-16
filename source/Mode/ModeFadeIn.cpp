/*****************************************************************//**
 * @file   ModeFadeIn.cpp
 * @brief  モードフェードのサブクラス
 *         モード遷移時のフェードイン処理を行う
 *
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#include "ModeFadeIn.h"
#include "../Data/Color.h"

namespace AppFrame{
  namespace Mode {
    ModeFadeIn::ModeFadeIn(Application::ApplicationBase& app, Data::Color color) : ModeFade(app, color) {
    }

    bool ModeFadeIn::Enter() {
      // 各種パラメータの初期化
      _alpha = AlphaMax;
      _deltaAlpha = -AlphaDelta;
    }

    bool ModeFadeIn::Process() {
      // アルファ値の加算
      _alpha += _deltaAlpha;
      // フェードイン処理の終了判定
      if (IsFinish()) {
        return true;
      }
      return false;
    }

    bool ModeFadeIn::IsFinish() {
      // アルファ値は下限以下か
      return _alpha <= AlphaMin;
    }
  } // namespace Mode
} // namespace AppFrame