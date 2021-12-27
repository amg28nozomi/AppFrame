/*****************************************************************//**
 * @file   Operation.h
 * @brief  入力処理クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <string>
#include <vector>

namespace AppFrame {
  namespace Application {
    /**
     * @class Operation
     * @brief 入力処理
     */
    class Operation {
    public:
      /**
       * @brief コンストラクタ
       */
      Operation();
      /**
       * @brief デストラクタ
       */
      ~Operation();
      /**
       * @brief 更新処理
       */
      void Process();
    private:
      std::vector<class JoypadState> _joypads;
    };
  } // namespace Application
} // namespace AppFrame