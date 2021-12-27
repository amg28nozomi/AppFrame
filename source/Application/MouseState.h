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
    class MouseState : public InputBase {
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
       * @brief  ���W�̎擾
       * @return ���W
       */
      inline Math::Vector4 GetPosition() const {
        return _position;
      }

      inline Math::Vector4 GetMove() const {
        return _move;
      }
    private:
      Math::Vector4 _position{0,0}; //!< ���W
      Math::Vector4 _move{0,0};     //!< �ω���
    };
  } // namespace Application
} // namespace AppFrame

