#include "MouseState.h"
#include <DxLib.h>

namespace AppFrame {
  namespace Application {

    template <typename T>
    MouseState<T>::MouseState() {
      _type = Type::Mouse;
      _press = 0;
      _trigger = 0;
    }

    template <typename T>
    void MouseState<T>::Process() {
      // ���͏�Ԃ̍X�V
      auto old = _press;
      _press = GetMouseInput();
      _trigger = _press ^ old & _press;
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