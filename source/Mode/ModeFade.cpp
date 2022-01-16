/*****************************************************************//**
 * @file   ModeFade.cpp
 * @brief  モードベースのサブクラスの定義
 *         シーン遷移時のフェード処理を行う
 * 
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#include "ModeFade.h"
#include <DxLib.h>
#include "../Application/ApplicationBase.h"
#include "../Data/Color.h"

namespace AppFrame{
  namespace Mode {

    ModeFade::ModeFade(Application::ApplicationBase& app, const Data::Color color) : ModeBase(app) {
      // カラー値の設定
      _basic = color;
      _color = _basic;
      // ウィンドウサイズの取得
      auto [width, height] = app.GetWindowSize();
      // ボックスサイズをウィンドウサイズと同じに設定
      _width = width;
      _height = height;
    }

    ModeFade::~ModeFade() {
    }

    bool ModeFade::Init() {
      _color = _basic;
      return true;
    }

    bool ModeFade::Enter() {
      return true;
    }

    bool ModeFade::Process() {
      return true;
    }

    bool ModeFade::Draw() const {
      // ブレンドモードの切り替え
      SetDrawBlendMode(DX_BLENDMODE_ALPHA, _color.GetAlpha());
      // フェード処理用のボックスを描画
      DrawBox(0, 0, _width, _height, _color.GetColorCode(), TRUE);
      // ブレンドモードをノーマルに戻す
      SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    void ModeFade::SetColor(const Data::Color color) {
      // 現在のRGB情報を変更する
      _basic = color;
    }
  } // namespace Mode
} // namespace AppFrame