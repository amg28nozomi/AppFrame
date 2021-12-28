#include "MouseState.h"
#include <DxLib.h>

namespace AppFrame {
  namespace Application {

    MouseState::MouseState() : InputBase() {
      _type = Type::Mouse;
    }

    void MouseState::Process() {
      // ���͏�Ԃ̍X�V
      auto old = _press;
      _press = GetMouseInput();
      Trigger(old);
      // ���ݍ��W�̎擾
      int x, y;
      GetMousePoint(&x, &y);
      Math::Vector4 pos(x, y);
      // �ω��ʂ̎Z�o
      _move = pos - _position;
      _position = pos;
    }
  } // namespace Application
} // namespace AppFrame