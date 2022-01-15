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
       * @param id パッドの識別子
       */
      JoypadState(const int id = 0);
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
       * @brief  ボタン情報の取得(押下)
       * @param  key  対応するキー番号(0～15)
       *              DXライブラリのXINPUTボタン入力定義
       * @brief  type 取得する情報の種類
       *              InputPress:押下情報(デフォルト) InputTrigger:トリガ情報
       * @return true:入力有り false:入力無し
       */
      bool GetButton(const int key, const bool type = InputPress) const;
      /**
       * @brief  押下情報の取得
       * @return 押下情報
       */
      XINPUT_STATE GetPress() const {
        return _press;
      }
      /**
       * @brief  トリガ入力の取得
       * @return トリガ入力
       */
      XINPUT_STATE GetTrigger() const {
        return _trigger;
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