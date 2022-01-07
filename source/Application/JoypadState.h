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
    /**
     * @class JoypadState
     * @brief ジョイパッドの入力状態(XInput)
     */
    class JoypadState : public InputBase < XINPUT_STATE > {
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
    private:
      int _id; //!< ジョイパッドの識別番号
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