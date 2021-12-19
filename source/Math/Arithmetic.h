/*****************************************************************//**
 * @file   Arithmetic.h
 * @brief  �Z�p�����N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <string>
#include <vector>

namespace AppFrame {
  /** �Z�p�����p���O��� */
  namespace Math {
    /**
     * @class Arithmetic
     * @brief �Z�p�����p�N���X
     */
    class Arithmetic {
    public:
      /**
       * @brief  �����l�̃N�����v����
       * @param  value  �N�����v����l
       * @param  low    ����
       * @param  height ���
       * @return �N�����v�����l
       * @throw  std::logic_error std::invalid_argument
       */
      static int Clamp(const int value, const int low, const int height);
      /**
       * @brief  
       * @param  value  �P���x���������_����
       * @param  low    �N�����v����
       * @param  height �N�����v���
       * @return �N�����v�����l
       */
      static float Clamp(const float value, const float low, const float height);
      /**
       * @brief  10�i���l��2�i���l�ɕϊ�
       * @param  num 10�i���l
       * @return ������2�i���ŕ\����������
       */
      static std::string ToBinary(int num);
      /**
       * @brief  10�i���l��16�i���l�ɕϊ�
       * @param  num  10�i���l
       * @param  flag true:������Ŏ擾(�f�t�H���g) false:�����l�Ŏ擾 
       * @return num��16�i���ɕϊ������l
       */
      static std::string ToHexadecimal(int num);
      /**
       * @brief  �����������int�^�̐��l�ɕϊ�����
       * @param  num ����������
       * @return ���l
       */
      static int ToInteger(std::string_view num);
      /**
       * @brief  �N�����v�����ɑΉ����Ă���^�̎擾
       * @return �Ή����Ă���^�𕶎���ŕێ�����R���e�i
       */
      static inline auto GetClampType() {
        return _clampType;
      }
    private:
      static std::vector<std::string> _clampType; //!< Clamp���\�b�h�ɑΉ����Ă���^
      /**
       * @brief  �]����w�肵��16�i��������ɕϊ�����
       * @param  remainder ��]
       * @return 16�i��������
       */
      static std::string ToRemainder16(const int remainder);
    };
  } // namespace Math
} // namespace AppFrame