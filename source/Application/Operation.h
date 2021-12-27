/*****************************************************************//**
 * @file   Operation.h
 * @brief  ���͏����N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <string>
#include <vector>

namespace AppFrame {
  namespace Application {
    /**
     * @class Operation
     * @brief ���͏���
     */
    class Operation {
    public:
      /**
       * @brief �R���X�g���N�^
       */
      Operation();
      /**
       * @brief �f�X�g���N�^
       */
      ~Operation();
      /**
       * @brief �X�V����
       */
      void Process();
    private:
      std::vector<class JoypadState> _joypads;
    };
  } // namespace Application
} // namespace AppFrame