/*****************************************************************//**
 * @file   InputBase.cpp
 * @brief  ���͏�Ԃ̊��N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "InputBase.h"

namespace AppFrame {
  namespace Application {
    template <typename T>
    InputBase <typename T>::InputBase() {
      ++_connection;
    }

    template <typename T>
    InputBase<typename T>::~InputBase() {
      --_connection;
    }

    template <typename T>
    T InputBase<typename T>::GetKey() const {
      return _press;
    }

    template <typename T>
    T InputBase<typename T>::GetTriggerKey() const {
      return _trigger;
    }
  } // Application
} // AppFrame