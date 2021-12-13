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
  constexpr auto WINDOW_W = 1920; //!< デフォルトの解像度
  constexpr auto WINDOW_H = 1080; //!< デフォルトの解像度
  constexpr auto WINDOW_B = 32;   //!< デフォルトのカラービット数
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
       * @brief  画面サイズの取得
       * @return 画面の縦幅と横幅を返す
       */
      inline auto GetWindowSize() {
        return std::make_pair(std::get<0>(_window), std::get<1>(_window));
      }
      /**
       * @brief  ウィンドウ情報の取得
       * @return ウィンドウサイズ・カラービット数を返す
       */
      inline auto GetWidnowData() {
        return _window;
      }
    protected:
      static inline std::tuple<int, int, int> _window; //!< ウィンドウ情報
      static inline bool _isAdd = false; //!< 生成フラグ
      static inline std::shared_ptr<ApplicationBase> _instance; //!< 実態
    };
  }
} // namespace AppFrame

