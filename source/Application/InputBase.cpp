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

    InputBase::InputBase() {
      ++_connection;
    }

    InputBase::~InputBase() {
      --_connection;
    }
  } // Application
} // AppFrame