/*****************************************************************//**
 * @file   KeyboardState.h
 * @brief  �L�[�{�[�h�̓��͏�ԃN���X
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#pragma once
#include "InputBase.h"
#include <array>
#include <string>

/**
 * @brief �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief �A�v���P�[�V����
   */
  namespace Application {
    constexpr auto AllKeysNum = 256; //!< �擾�\�ȃL�[�̑���
    /**
     * @class KeyboardState
     * @brief �L�[�{�[�h�̓��͏��
     */
    class KeyboardState : public InputBase<std::array<char, AllKeysNum>> {
    public:
      /**
       * @brief �R���X�g���N�^
       */
      KeyboardState();
      ///**
      // * @brief �f�X�g���N�^
      // */
      //~KeyboardState() override;
      /**
       * @brief ���͏�Ԃ̍X�V
       */
      void Process() override;
      /**
       * @brief  �w�肵���L�[��������Ă��邩�̔���
       * @param  keyCode �L�[�R�[�h
       * @return 0:���͖��� 1:���͗L��
       */
      const int GetKey(const int keyCode) const;
    };
  } // namespace Application
} // namespace AppFrame

