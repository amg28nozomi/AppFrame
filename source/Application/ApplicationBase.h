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
/** フレームワーク用名前空間 */
namespace AppFrame {
  constexpr auto WindowWidth = 1920;  //!< デフォルトの解像度情報
  constexpr auto WindowHeight = 1080; //!< デフォルトの解像度情報
  constexpr auto BitColor32 = 32;     //!< 32ビットカラー
  constexpr auto BitColor16 = 16;     //!< 16ビットカラー
  namespace FileServer {
    class FileServer;
  } // namespace FileServer
  /** Application用名前空間 */
  namespace App {
    /**
     * @class ApplicationBase
     * @brief アプリケーションの基底クラス
     */
    class ApplicationBase {
    public:
      /**
       * @brief コンストラクタ
       * 
       */
      ApplicationBase();
      /**
       * @brief デストラクタ
       */
      ~ApplicationBase();
      /**
       * @brief  アプリケーションの初期化
       * @return 初期化に成功した場合はtrue
       *         失敗した場合はfalseを返す
       */
      virtual bool Init();
      /**
       * @brief  画面サイズの取得
       * @return 画面の縦幅と横幅を返す
       */
      inline const auto GetWindowSize() {
        return std::make_pair(std::get<0>(_window), std::get<1>(_window));
      }
      /**
       * @brief  ウィンドウ情報の取得
       * @return ウィンドウサイズ・カラービット数を返す
       */
      inline const auto GetWidnowData() {
        return _window;
      }
      /**
       * @brief  ウィンドウ情報の設定
       * @param  width  解像度
       * @param  height 解像度
       * @param  bit    カラービット数を変更するかのフラグ
       *                true:32ビットカラー(デフォルト)  false:16ビットカラー
       */
      static void SetWindowSize(int width, int height, bool bit = true);
    protected:
      static inline std::tuple<int, int, int> _window; //!< ウィンドウ情報
      static inline bool _isAdd = false; //!< 生成フラグ
      static inline bool _windowMode;    //!< ウィンドウモード
      static inline std::shared_ptr<ApplicationBase> _instance = nullptr; //!< 実態
      std::unique_ptr<FileServer::FileServer> _fileServer;  //!
    };
  } // namespace App
} // namespace AppFrame