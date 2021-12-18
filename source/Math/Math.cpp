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
#include <charconv>
#include <stdexcept>
#include <typeinfo>
#include <vector>

namespace {
  constexpr auto Binary = 2;       // 2�i��
  constexpr auto Decimal = 10;     // 10�i��
  constexpr auto Hexadecimal = 16; // 16�i��
}

namespace AppFrame {
  namespace Math {
    // �f�t�H���g�ł�int�^�Afloat�^�Adouble�^�̂ݑΉ�
    std::vector<std::string> Math::_clampType = { "int", "float", "double" };

    template <typename T>
    T Math::Clamp(const T value, const T low, const T height) {
      auto id = typeid(value).name(); // �����̌^
      auto flag = false; // ����t���O
//      // �����̌^�͑S�Ĉ�v���Ă��邩�H
//      bool accord = (id == typeid(low) == typeid(height));
//      if (!accord) {
//#ifdef _DEBUG
//        throw std::invalid_argument("Math::Clamp:�����̌^���s���ł��B�^�͑S�ē��ꂵ�Ă�������");
//#endif
//        return value; // �^���s��
//      }
      for (auto type : _clampType) {
        // �Ώۂ̌^�͑Ή����Ă��邩�H
        if (id == type.data()) {
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

    std::string Math::ToBinary(int num) {
      std::string binary; // 2�i��
      while (num != 0) {
        // �]�肪�o�邩�H
        binary += (num % Binary == 0 ? "0" : "1");
        num /= Binary;
      }
      return binary;
    }

    std::string Math::ToHexadecimal(int num) {
      std::string hexadecimal; // 16�i��
      while (num != 0) {
        auto param = num % Hexadecimal; // �]��
        hexadecimal += ToRemainder16(param); // �]��𕶎���ɕϊ����A�����ɒǉ�
        num /= Hexadecimal;
      }
      return hexadecimal;
    }

    int Math::ToInteger(std::string_view num) {
      return 0;
    }

    std::string Math::ToRemainder16(const int remainder) {
#ifdef _DEBUG
      // �����͑Ώ۔͈͂Ɏ��܂��Ă��邩�H
      if (Hexadecimal <= remainder) {
        throw std::logic_error("Math::ToRemainder16:�����̒l���Ώ۔͈͊O�ł�\n");
      }
#endif
      // �s��΍��p
      auto num = std::clamp(remainder, 0, 15);
      // 10�ȏ�̏ꍇ�͂��ꂼ��Ή�����A���t�@�x�b�g
      // 10�����̏ꍇ�͕�����ɕϊ������l��Ԃ�
      switch (num) {
      case 15:
        return "F";
      case 14:
        return "E";
      case 13:
        return "D";
      case 12:
        return "C";
      case 11:
        return "B";
      case 10:
        return "A";
      default:
        return std::to_string(num);
      }
    }
  } // namespace Math
} // namespace AppFrame