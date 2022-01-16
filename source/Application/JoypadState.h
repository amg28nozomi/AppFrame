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
#include <DxLib.h>

namespace AppFrame {
  namespace Application {
    constexpr auto JoypadButtonNum = 16; //!< ボタン総数
    constexpr auto InputPress = true;    //!< 押下情報
    constexpr auto InputTrigger = false; //!< トリガ入力
    /**
     * @class JoypadState
     * @brief ジョイパッドの入力状態(XInput)
     */
    class JoypadState : public InputBase  {
    public:
      /**
       * @brief コンストラクタ
       */
      JoypadState();
      /**
       * @brief  入力状態の更新
       */
      void Process() override;
      /**
       * @brief  ボタン情報の取得(押下)
       * @param  key  対応するキー番号(0～15)
       *              DXライブラリのXINPUTボタン入力定義
       * @brief  type 取得する情報の種類
       *              InputPress:押下情報(デフォルト) InputTrigger:トリガ情報
       * @return true:入力有り false:入力無し
       */
      bool GetButton(const int key, const bool type = InputPress) const;
      /**
       * @brief  アナログスティックの入力状態を取得
       * @brief  stick 左右どちらのアナログスティックの入力を取得するか
       *               false:左スティック　true:右スティック
       * @return first:横軸の入力状態 second:縦軸の入力状態
       */
      std::pair<int, int> GetStick(const bool stick) const;
      /**
       * @brief  左右トリガーボタンの入力状態を取得
       * @return first:左トリガー second:右トリガー
       */
      inline std::pair<int, int> GetTrigger() const {
        return std::make_pair(_press.LeftTrigger, _press.RightTrigger);
      }
    private:
      int _id; //!< ジョイパッドの識別番号
      XINPUT_STATE _press;   //!< 入力情報(押下入力)
      XINPUT_STATE _trigger; //!< 入力情報(トリガ入力)
      /**
       * @brief  トリガ情報の生成
       * @param  press 対象キーの押下情報
       * @param  old   対象キーの押下情報(前フレーム)
       * @return 対象キーのトリガ情報
       */
      inline int Trigger(const int press, const int old) {
        return press ^ old & press;
      }
    };
  } // namespace Application
} // namespace AppFrame