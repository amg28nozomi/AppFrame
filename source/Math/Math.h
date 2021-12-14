/*****************************************************************//**
 * @file   Math.h
 * @brief  �Z�p�����N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once

namespace AppFrame {
  /** �Z�p�����p���O��� */
  namespace Math {
    
    class Math {
    public:
      /**
       * @brief  �l�̃N�����v����
       * @tparam T      �l�̌^
       * @param  value  �N�����v����l
       * @param  low    ����
       * @param  height ���
       * @return �N�����v�����l��Ԃ�
       */
      template <typename T>
      static T Clamp(const T value, const T low, const T height);
    };
  } // namespace Math
} // namespace AppFrame