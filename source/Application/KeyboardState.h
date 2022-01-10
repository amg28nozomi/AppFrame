/*****************************************************************//**
 * @file   KeyboardState.h
 * @brief  キーボードの入力状態クラス
 * 
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#pragma once
#include "InputBase.h"
#include <array>
#include <string>

/**
 * @brief アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief アプリケーション
   */
  namespace Application {
    constexpr auto AllKeysNum = 256; //!< 取得可能なキーの総数
    /**
     * @class KeyboardState
     * @brief キーボードの入力状態
     */
    class KeyboardState : public InputBase<std::array<char, AllKeysNum>> {
    public:
      /**
       * @brief コンストラクタ
       */
      KeyboardState();
      ///**
      // * @brief デストラクタ
      // */
      //~KeyboardState() override;
      /**
       * @brief 入力状態の更新
       */
      void Process() override;
      /**
       * @brief  指定したキーが押されているかの判定
       * @param  keyCode キーコード
       * @return 0:入力無し 1:入力有り
       */
      const int GetKey(const int keyCode) const;
    };
  } // namespace Application
} // namespace AppFrame

