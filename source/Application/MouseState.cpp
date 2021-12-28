#include "MouseState.h"
#include <DxLib.h>

namespace AppFrame {
  namespace Application {

    MouseState::MouseState() : InputBase() {
      _type = Type::Mouse;
    }

    void MouseState::Process() {
      // 入力状態の更新
      auto old = _press;
      _press = GetMouseInput();
      Trigger(old);
      // 現在座標の取得
      int x, y;
      GetMousePoint(&x, &y);
      Math::Vector4 pos(x, y);
      // 変化量の算出
      _move = pos - _position;
      _position = pos;
    }
  } // namespace Application
} // namespace AppFrame