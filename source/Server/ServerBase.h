/*****************************************************************//**
 * @file   ServerBase.h
 * @brief  サーバの基底クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#ifdef _DEBUG
#include <stdexcept>
#include <Windows.h>
#endif
/**
 * @brief アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief サーバベース
   */
  namespace Server {
    /**
     * @class ServerBase
     * @brief サーバのテンプレート
     */
    template <typename T>
    class ServerBase {
    public:
      /**
       * @brief サーバの状態を表す列挙型クラス
       */
      enum class ServerState {
        Active, // 活動
        Paused, // 停止
        Error   // 異常
      };
      /**
       * @brief コンストラクタ
       */
      ServerBase();
      /**
       * @brief デストラクタ
       */
      virtual ~ServerBase() = default;
      /**
       * @brief  初期化
       * @return true:初期化成功 false:初期化失敗
       */
      virtual bool Init();
      /**
       * @brief  保持しているリソースの解放処理
       *         派生先で必ず再定義を行う
       * @return true:解放成功 false:問題発生
       */
      virtual bool Release() = 0;
    protected:
      ServerState _state; //!< 状態
      T _registry{};      //!< データベース
#ifdef _DEBUG
      std::string _name;  //!< サーバ名
      /**
       * @brief デバッグ処理で使用するサーバ名の設定
       * @param name サーバ名
       */
      void SetServerName(std::string_view name);
      /**
       * @brief  logic_errorの生成
       * @param  message 出力する文字列
       * @return logic_error
       */
      virtual std::logic_error LogicError(std::string_view message) const;
      /**
       * @brief デバッグ用メッセージの出力
       * @param message デバッグ用の文字列
       */
      virtual void DebugString(std::string_view message) const;
#endif
    };
    /**
     * @brief コンストラクタの定義
     */
    template <typename T>
    ServerBase<T>::ServerBase() {
      _state = ServerState::Active;
    }
    /**
     * @brief 初期化の定義
     */
    template <typename T>
    bool ServerBase<T>::Init() {
#ifndef _DEBUG
      // リソースの解放処理に成功したか
      if (!Release()) {
        _state = ServerState::Error;
        return false; // 失敗
      }
      return true;    //正常終了
#else
      bool flag;
      try {
        flag = Release(); // リソースの解放
      }
      catch (std::logic_error error) {
        // 例外をcatchした場合は、出力を行う
        DebugString(error.what());
      }
      // 解放に失敗した場合はエラー状態に遷移する
      if (!flag) {
        _state = ServerState::Error;
      }
      return flag;
#endif
    }

#ifdef _DEBUG
    template <typename T>
    void ServerBase<T>::SetServerName(std::string_view name) {
      _name = name.data(); // 引数の文字列をサーバ名として使用する
    }

    template <typename T>
    std::logic_error ServerBase<T>::LogicError(std::string_view message) const {
      std::string error = _name + ":" + message.data() + "\n";
      return std::logic_error(error);
    }

    template <typename T>
    void ServerBase<T>::DebugString(std::string_view message) const {
      // デバッグウィンドウに出力する
      OutputDebugString(message.data());
    }
#endif
  } // namespace Server
} // namespace AppFrame