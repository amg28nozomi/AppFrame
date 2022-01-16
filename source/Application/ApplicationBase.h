/*****************************************************************//**
 * @file   ApplicationBase.h
 * @brief  アプリケーションのスーパークラス
 *         全てのアプリケーションはこのクラスを派生する
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <tuple>
#include <memory>
#include "../FileServer/FileServer.h"
#include "../Mode/ModeServer.h"
/**
 * @brief アプリケーションフレーム
 */
namespace AppFrame {
  constexpr auto WindowWidth = 1920;  //!< デフォルトの解像度情報
  constexpr auto WindowHeight = 1080; //!< デフォルトの解像度情報
  constexpr auto BitColor32 = 32;     //!< 32ビットカラー
  constexpr auto BitColor16 = 16;     //!< 16ビットカラー
  constexpr auto Frame60 = 60;        //!< 60フレーム
  namespace Mode {
    class ModeBase;
  } // namespace Mode
  /**
   * @brief アプリケーションベース
   */
  namespace Application {
    /**
     * @class ApplicationBase
     * @brief アプリケーションの基底クラス
     */
    class ApplicationBase {
    public:
      /**
       * @brief  アプリケーションの状態
       */
      enum class State {
        Play,   //!< 実行中
        Paused, //!< 一時停止
        Quit    //!< 終了
      };
      /**
       * @brief コンストラクタ
       * 
       */
      ApplicationBase();
      /**
       * @brief デストラクタ
       */
      virtual ~ApplicationBase();
      /**
       * @brief  アプリケーションの初期化
       * @return 初期化に成功した場合はtrue
       *         失敗した場合はfalseを返す
       */
      virtual bool Init();
      /**
       * @brief アプリケーションの解放
       */
      virtual void Release();
      /**
       * @brief  実行処理
       */
      virtual void Run();
      /**
       * @brief  終了処理
       */
      virtual void Terminate();
      /**
       * @brief  アプリケーションの参照を取得
       * @return アプリケーションの参照
       */
      static std::shared_ptr<ApplicationBase> GetInstance() {
        return _instance;
      }
      /**
       * @brief  インプットオペレーションの取得
       * @return インプットオペレーションの参照
       */
      class InputOperation& GetOperation() {
        return *_input;
      }
      /**
       * @brief  モードサーバの取得
       * @return モードサーバの参照
       */
      Mode::ModeServer& GetModeServer() {
        return *_modeServer;
      }
      /**
       * @brief  ファイルサーバの取得
       * @return ファイルサーバの参照
       */
      FileServer::FileServer& GetFileServer() {
        return *_fileServer;
      }
      /**
       * @brief  画面サイズの取得
       * @return 画面の縦幅と横幅を返す
       */
      inline const std::pair<int, int> GetWindowSize() {
        return std::make_pair(_width, _height);
      }
      /**
       * @brief  ウィンドウ情報の取得
       * @return ウィンドウサイズ・カラービット数を返す
       */
      inline const std::tuple<int, int, int> GetWidnowData() {
        return std::make_tuple(_width, _height, _colorBit);
      }
      /**
       * @brief  経過フレーム取得用の純粋仮想関数
       * @return 現在呼び出されているモードのフレームカウント
       */
      virtual const int GetFrameCount() const = 0;
      /**
       * @brief  ウィンドウ情報の設定
       * @param  width  解像度
       * @param  height 解像度
       * @param  bit    カラービット数を変更するかのフラグ
       *                true:32ビットカラー(デフォルト)  false:16ビットカラー
       */
      static void SetWindowSize(int width, int height, bool bit = true);
    protected:
      State _state{State::Paused};    //!< アプリケーションの状態
      static inline int _particleMax{0}; //!< 使用するパーティクル上限
      static inline int _width{0};    //!< ウィンドウサイズ(幅)
      static inline int _height{0};   //!< ウィンドウサイズ(高さ)
      static inline int _colorBit{0}; //!< カラービット数
      static inline bool _setInstance{false};   //!< 生成フラグ
      static inline bool _windowMode{false};    //!< ウィンドウモード
      //!< アプリケーションの実体
      static inline std::shared_ptr<ApplicationBase> _instance{nullptr};
      //!< ファイルサーバ
      std::unique_ptr<FileServer::FileServer> _fileServer{nullptr};
      //!< インプットオペレーション
      std::unique_ptr<InputOperation> _input{nullptr};
      //!< モードサーバ
      std::unique_ptr<Mode::ModeServer> _modeServer{nullptr};
      /**
       * @brief  入力処理
       * @return true:処理成功 false:処理失敗
       */
      virtual bool Input();
      /**
       * @brief  更新処理
       * @return true:処理成功 false:処理失敗
       */
      virtual bool Process();
      /**
       * @brief  描画処理
       * @return true:処理成功 false:処理失敗
       */
      virtual bool Draw();
      /**
       * @brief  Instanceの生成を行うかの判定
       * @return true:生成に移行 false:既に実体が定義されている
       */
      static bool SetInstance();
      /**
       * @brief  アプリケーションを終了するかの判定
       */
      virtual void IsQuit();
    };
  } // namespace Application
} // namespace AppFrame