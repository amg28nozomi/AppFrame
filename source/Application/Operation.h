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
       * @brief  実行状態の取得
       * @return 実行状態
       */
      const State OperationState() const {
        return _state;
      }
    private:
      ApplicationBase& _app; //!< アプリケーション
      State _state{}; //!< 状態
      std::vector<class JoypadState> _joypads; //!< 接続されているジョイパッド
      /**
       * @brief  入力デバイスが接続されているかの判定
       * @return true:接続あり　false:接続なし
       */
      const bool IsConnection() const;
      /**
       * @brief  ジョイパッドの再接続処理
       * @return true:再接続完了 false:接続無し
       */
      /*std::future<bool> ReConnect();*/
    };
  } // namespace Application
} // namespace AppFrame