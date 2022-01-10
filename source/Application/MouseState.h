/*****************************************************************//**
 * @file   MouseState.h
 * @brief  �}�E�X�̓��͏�ԃN���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "InputBase.h"
#include "../Math/Vector4.h"

namespace AppFrame {
  namespace Application {
    /**
     * @class MouseState
     * @brief �}�E�X�̓��͏��
     */
    template <typename T>
    class MouseState : public InputBase <int> {
    public:
      /**
       * @brief  �R���X�g���N�^
       */
      MouseState();
      /**
       * @brief  ���͏�Ԃ̍X�V
       */
      void Process() override;
      /**
       * @brief  �������̎擾
       * @return �������
       */
      inline int GetKey() const {
        return _press;
      }
      /**
       * @brief  �g���K���̎擾
       * @return �g���K���
       */
      inline int GetTriggerKey() {
        return _trigger;
      }
      /**
       * @brief  ���W�̎擾
       * @return �J�[�\�����W
       */
      inline Math::Vector4 GetPosition() const {
        return _position;
      }
      /**
       * @brief  �ω��ʂ̎擾
       * @return �J�[�\���̕ω���
       */
      inline Math::Vector4 GetMove() const {
        return _move;
      }
    private:
      Math::Vector4 _position{0,0}; //!< ���W
      Math::Vector4 _move{0,0};     //!< �ω���
    };
  } // namespace Application
} // namespace AppFrame

