/*****************************************************************//**
 * @file   Math.h
 * @brief  �Z�p�����N���X
 *
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "Math.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <typeinfo>
#include <vector>
#include <Windows.h>

namespace {
}

namespace AppFrame {
  namespace Math {
    // �f�t�H���g�ł�int�^�Afloat�^�Adouble�^�̂ݑΉ�
    std::vector<std::string> Math::_clampType = { "int", "float", "double" };

    template <typename T>
    T Math::Clamp(const T value, const T low, const T height) {
      const auto id = typeid(value); // �����̌^
      auto flag = false; // ����t���O
      // �����̌^�͑S�Ĉ�v���Ă��邩�H
      bool accord = (id == typeid(low) == typeid(height));
      if (!accord) {
#ifdef _DEBUG
        throw std::invalid_argument("Math::Clamp:�����̌^���s���ł��B�^�͑S�ē��ꂵ�Ă�������");
#endif
        return value; // �^���s��
      }
      for (auto type : _clampType) {
        // �Ώۂ̌^�͑Ή����Ă��邩�H
        if (id == type) {
          flag = true; // �^����v
          break;
        }
      }
#ifndef _DEBUG
      if (!flag) {
        return value; // �^���Ή����Ă��Ȃ�
      }
#else
      if (!flag) {
        throw std::invalid_argument("Math::Clamp:�����̌^���s���ł��B" + std::to_string(id) + "�^�͑Ή����Ă��܂���");
        return value;
      }
      // �l�͔͈͓��Ɏ��܂��Ă��邩
      if (value < low) {
        throw std::logic_error("�l�������������܂��� value:" + std::to_string(value) + " low:" + std::to_string(low));
      }
      else if (height < value) {
        throw std::logic_error("�l������𒴉߂��܂��� value:" + std::to_string(value) + " height:" + std::to_string(height));
      }
#endif
      return std::clamp(value, low, height);
    }
  } // namespace Math
} // namespace AppFrame