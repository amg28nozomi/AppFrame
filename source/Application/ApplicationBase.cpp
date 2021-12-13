/*****************************************************************//**
 * @file   ApplicationBase.cpp
 * @brief  アプリケーションのスーパークラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "ApplicationBase.h"

namespace AppFrame {
  namespace App {
    
    ApplicationBase::ApplicationBase() {
      // ウィンドウ情報の設定
      auto&& [width, height, bit] = _window;
      width = WINDOW_W;
      height = WINDOW_H;
      bit = WINDOW_B;
      // 生成フラグの登録
      if (!_instance) {
#ifdef _DEBUG

#endif
      }

    }

    ApplicationBase::~ApplicationBase() {

    }
  } // namespace App
} // namespace AppFrame
