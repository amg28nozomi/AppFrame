/*****************************************************************//**
 * @file   Math.h
 * @brief  �Z�p�����N���X
 *
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "Math.h"
#include <string>
#include <cmath>
#include <algorithm>
#include <Windows.h>

namespace AppFrame {
  namespace Math {

    template <typename T>
    T Math::Clamp(const T value, const T low, const T height) {
      std::string message;
#ifdef _DEBUG
      // �l�͔͈͓��Ɏ��܂��Ă��邩
      if (value < low) {
        message = "�l�������������܂��� value:" + std::to_string(value) +  " low:" + std::to_string(low);
      }
      else if (height < value) {
        message = "�l������𒴉߂��܂��� value:" + std::to_string(value) + " height:" + std::to_string(height);
      }
      if (!message.empty()) {
        // ���O�ւ̏o��
        message.append("\n");
        OutputDebugString(message.data());
      }
#endif
      return std::clamp(value, low, height);
    }
  } // namespace AppFrame
} // namespace Math