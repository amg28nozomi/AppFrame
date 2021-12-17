/*****************************************************************//**
 * @file   Math.h
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
     * @class Math
     * @brief �Z�p�����p�N���X
     */
    class Math {
    public:
      /**
       * @brief  �l�̃N�����v����
       * @tparam T      �����̌^
       *                int�Afloat�Adouble�^�ł͂Ȃ��ꍇ�͏����𒆒f
       * @param  value  �N�����v����l
       * @param  low    ����
       * @param  height ���
       * @return �N�����v�����l
       *         �����𖞂����Ă��Ȃ��ꍇ��value��Ԃ�
       * @throw  std::logic_error std::invalid_argument
       */
      template <typename T>
      static T Clamp(const T value, const T low, const T height);
      /**
       * @brief  �N�����v�����ɑΉ����Ă���^�̎擾
       * @return �Ή����Ă���^�𕶎���ŕێ�����R���e�i
       */
      static inline auto GetClampType() {
        return _clampType;
      }
    private:
      static std::vector<std::string> _clampType; //!< Clamp���\�b�h�ɑΉ����Ă���^
    };
  } // namespace Math
} // namespace AppFrame