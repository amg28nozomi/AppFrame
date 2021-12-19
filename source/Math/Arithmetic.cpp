/*****************************************************************//**
 * @file   Arithmetic.cpp
 * @brief  �Z�p�����N���X
 *
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#include "Arithmetic.h"
#include <cmath>
#include <algorithm>
#include <charconv>
#include <stdexcept>
#include <vector>

namespace {
  constexpr auto Binary = 2;       // 2�i��
  constexpr auto Decimal = 10;     // 10�i��
  constexpr auto Hexadecimal = 16; // 16�i��
}

namespace AppFrame {
  namespace Math {

    int Arithmetic::Clamp(const int value, const int low, const int height) {
#ifndef _DEBUG
      // ����������𒴉߂��Ă��Ȃ����H
      if (height <= low) {
        return value; // ���̒l��Ԃ�
      }
#else
      if (height <= low) {
        throw std::logic_error("Arithmetic::Clamp:�����l������l�𒴉߁A�܂��͈�v���Ă��܂�\n");
        return value;
      }
      // �l�͔͈͓��Ɏ��܂��Ă��邩
      if (value < low) {
        throw std::logic_error("Arithmetic::�l�������������܂��� value:" + std::to_string(value) + " low:" + std::to_string(low));
      }
      else if (height < value) {
        throw std::logic_error("Arithmetic::�l������𒴉߂��܂��� value:" + std::to_string(value) + " height:" + std::to_string(height));
      }
#endif
      return std::clamp(value, low, height);
    }

    float Arithmetic::Clamp(const float value, const float low, const float height) {
#ifndef _DEBUG
      // ����������𒴉߂��Ă��Ȃ����H
      if (height <= low) {
        return value; // ���̒l��Ԃ�
      }
#else
      if (height <= low) {
        throw std::logic_error("Arithmetic::Clamp:�����l������l�𒴉߁A�܂��͈�v���Ă��܂�\n");
        return value;
      }
      // �l�͔͈͓��Ɏ��܂��Ă��邩
      if (value < low) {
        throw std::logic_error("Arithmetic::�l�������������܂��� value:" + std::to_string(value) + " low:" + std::to_string(low));
      }
      else if (height < value) {
        throw std::logic_error("Arithmetic::�l������𒴉߂��܂��� value:" + std::to_string(value) + " height:" + std::to_string(height));
      }
#endif
      return std::clamp(value, low, height);
    }

    std::string Arithmetic::ToBinary(int num) {
      std::string binary; // 2�i��
      while (num != 0) {
        // �]�肪�o�邩�H
        binary += (num % Binary == 0 ? "0" : "1");
        num /= Binary;
      }
      return binary;
    }

    std::string Arithmetic::ToHexadecimal(int num) {
      std::string hexadecimal; // 16�i��
      // �l��0�̏ꍇ�͏�����ύX
      if (num == 0) {
        return "00";
      }
      while (num != 0) {
        auto param = num % Hexadecimal;      // �]��
        hexadecimal += ToRemainder16(param); // ������ɕϊ������]��𖖔��ɒǉ�
        num /= Hexadecimal; // 16�Ŋ���(�[���؂�̂�)
      }
      // ����������1�����̏ꍇ�͐擪��0��ǉ�
      if (hexadecimal.size() == 1) {
        hexadecimal.insert(0, "0");
      }
      return hexadecimal;
    }

    int Arithmetic::ToInteger(std::string_view num) {
      return 0;
    }

    std::string Arithmetic::ToRemainder16(const int remainder) {
#ifdef _DEBUG
      // �����͑Ώ۔͈͂Ɏ��܂��Ă��邩�H
      if (Hexadecimal <= remainder) {
        throw std::logic_error("Arithmetic::ToRemainder16:�����̒l���Ώ۔͈͊O�ł�\n");
      }
#endif
      // �l��Ή��͈͓��ɏC��
      auto num = std::clamp(remainder, 0, 15);
      // 10�ȏ�̏ꍇ�͂��ꂼ��Ή�����A���t�@�x�b�g
      // 10�����̏ꍇ�͕�����ɕϊ������l��Ԃ�
      switch (num) {
      case 15:
        return "f";
      case 14:
        return "e";
      case 13:
        return "d";
      case 12:
        return "c";
      case 11:
        return "b";
      case 10:
        return "a";
      default:
        return std::to_string(num);
      }
    }
  } // namespace Math
} // namespace AppFrame