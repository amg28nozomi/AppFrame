/*****************************************************************//**
 * @file   JoypadState.h
 * @brief  ジョイパッドの入力状態クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "InputBase.h"
#include <utility>

namespace AppFrame {
  namespace Application {
    /**
     * @class JoypadState
     * @brief ジョイパッドの入力状態(XInput)
     */
    class JoypadState : public InputBase {
    public:
      /**
       * @brief コンストラクタ
       * @param id パッドの識別子
       */
      JoypadState(const int id);
      /**
       * @brief  入力状態の更新
       */
      void Process() override;
      /**
       * @brief  識別番号の取得
       * @return 識別番号
       */
      inline const int GetId() const {
        return _id;
      }
      /**
       * @brief  押下情報の取得
       * @return 押下情報
       */
      inline const int GetPress() const {
        return _press;
      }
      /**
       * @brief  トリガ情報の取得
       * @return トリガ情報
       */
      inline const int GetTrigger() const {
        return _trigger;
      }
      /**
       * @brief  入力情報の取得
       * @return 押下情報 トリガ情報
       */
      inline const std::pair<int, int> GetInput() const {
        return std::make_pair(_press, _trigger);
      }
      /**
       * @brief  アナログスティックの入力状態の取得
       * @return X軸の入力状態 y軸の入力状態
       */
      inline const std::pair<int, int> GetLever() const {
        return std::make_pair(_leverX, _leverY);
      }
    private:
      int _id{0};      //!< 識別番号
      int _leverX{0};  //!< アナログスティックの入力情報(縦)
      int _leverY{0};  //!< アナログスティックの入力情報(横)
    };
  } // namespace Application
} // namespace AppFrame