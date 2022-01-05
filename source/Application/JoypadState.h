/*****************************************************************//**
 * @file   JoypadState.h
 * @brief  ジョイパッドの入力状態クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "InputBase.h"
#include <array>
#include <utility>

namespace AppFrame {
  namespace Application {
    constexpr auto XInputMax = 22; //!< 扱う入力データの総数
    /**
     * @class JoypadState
     * @brief ジョイパッドの入力状態(XInput)
     */
    class JoypadState : public InputBase < std::array<int, XInputMax> > {
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
    private:
      int _id{0};      //!< 識別番号
      std::
      /**
       * @brief XInputの入力データをint型に変換する
       * @param press XInputの入力情報を格納する構造体
       */
      void ChangeData(XINPUT_STATE press);
    };
  } // namespace Application
} // namespace AppFrame