/*****************************************************************//**
 * @file   InputBase.cpp
 * @brief  “ü—Íó‘Ô‚ÌŠî’êƒNƒ‰ƒX
 * 
 * @author —é–ØŠóŠC
 * @date   December 2021
 *********************************************************************/
#include "InputBase.h"

namespace AppFrame {
  namespace Application {

    template <typename T>
    InputBase<typename T>::InputBase() {
      _press = 0;
      _trigger = 0;
      ++_connection;
      _state = State::Active;
    }

    template <typename T>
    InputBase<typename T>::~InputBase() {
      --_connection;
    }
  } // Application
} // AppFrame