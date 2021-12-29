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
#include <future>

namespace AppFrame {
  namespace Application {
    // デバイスタイプ(入力状態の取得で使用)
    constexpr auto DeviceKeyboard = 0; //!< キーボード
    constexpr auto DeviceMouse = 1;    //!< マウス
    constexpr auto DeviceJoypad = 2;   //!< ジョイパッド
    /**
     * @class Operation
     * @brief 入力処理
     */
    class Operation {
    public:
      /**
       * @brief 実行状態
       */
      enum class State {
        Active,   // 正常
        Paused,   // 一時停止
        NonActive // 接続なし
      };
      /**
       * @brief コンストラクタ
       * @param app アプリケーションの参照
       */
      Operation(class ApplicationBase& app);
      /**
       * @brief デストラクタ
       */
      ~Operation();
      /**
       * @brief 更新処理
       */
      void Process();
      /**
       * @brief  入力デバイスの追加
       * @param  device 入力デバイスの参照
       * @return true:追加成功 false:追加失敗
       */
      bool AddDevice(class InputBase& device);
      /**
       * @brief  指定したデバイスの取得
       * @param  type デバイスタイプ(0:キーボード  1:マウス  2:ジョイパッド)
       * @param  number ジョイパッド番号(デフォルトでは0)
       * @return 入力状態の参照
       * @throw  std::logic_error
       */
      InputBase& GetDevice(int type, int number = 0);
      /**
       * @brief  入力デバイスが接続されているかの判定
       * @return true:接続あり　false:接続なし
       */
      const bool IsConnection();
      /**
       * @brief  実行状態の取得
       * @return 実行状態
       */
      const State OperationState() const {
        return _state;
      }
    private:
      ApplicationBase& _app;     //!< アプリケーションの参照
      State _state{};            //!< 状態
      std::vector<InputBase> _devices; //!< 入力デバイス
      int _access{0}; //!< 接続数
      /**
       * @brief  ジョイパッドの再接続処理
       * @return true:再接続完了 false:接続無し
       */
      /*std::future<bool> ReConnect();*/
    };
  } // namespace Application
} // namespace AppFrame