/*****************************************************************//**
 * @file   JoypadState.h
 * @brief  ジョイパッドの入力状態クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <DxLib.h>
#include <tuple>

namespace AppFrame {
  namespace App {
    /**
     * @class JoypadState
     * @brief ジョイパッドの入力状態(XInput)
     */
    class JoypadState {
    public:
      /**
       * @brief コンストラクタ
       */
      JoypadState();
      /**
       * @brief デストラクタ
       */
      ~JoypadState();
      /**
       * @brief  入力状態の更新
       * @return 更新に成功した場合はtrue
       *         失敗した場合はfalseを返す
       */
      bool Process();
      /**
       * @brief  総接続数の取得
       * @return 総接続数
       */
      static inline const int ConnectJpypad() {
        return _connection;
      }
      /**
       * @brief  識別番号の取得
       * @return 識別番号
       */
      inline const auto GetId() const {
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
       * @return 押下情報とトリガ情報
       */
      inline const auto GetInput() const {
        return std::make_pair(_press, _trigger);
      }
      /**
       * @brief  アナログスティックの入力状態の取得
       * @return アナログスティックの押下情報
       */
      inline const auto GetLever() const {
        return _lever;
      }
    private:
      static int _connection;     //!< 総接続数
      int _id;                    //!< 識別番号
      int _press;                 //!< 押下情報
      int _trigger;               //!< トリガ情報
      std::pair<int, int> _lever; //!< アナログスティック
    };
  } // namespace App
} // namespace AppFrame