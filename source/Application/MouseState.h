/*****************************************************************//**
 * @file   MouseState.h
 * @brief  マウスの入力状態クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "InputBase.h"
#include "../Math/Vector4.h"

namespace AppFrame {
  namespace Application {
    /**
     * @class MouseState
     * @brief マウスの入力状態
     */
    class MouseState : public InputBase {
    public:
      /**
       * @brief  コンストラクタ
       */
      MouseState();
      /**
       * @brief  入力状態の更新
       */
      void Process() override;
      /**
       * @brief  座標の取得
       * @return 座標
       */
      inline Math::Vector4 GetPosition() const {
        return _position;
      }

      inline Math::Vector4 GetMove() const {
        return _move;
      }
    private:
      Math::Vector4 _position{0,0}; //!< 座標
      Math::Vector4 _move{0,0};     //!< 変化量
    };
  } // namespace Application
} // namespace AppFrame

