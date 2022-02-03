/*****************************************************************//**
 * @file   SoundComponent.h
 * @brief  サウンドコンポーネントクラス
 * 
 * @author 鈴木希海
 * @date   February 2022
 *********************************************************************/
#pragma once
#include <string_view>

/**
 * @brief フレームワーク
 */
namespace AppFrame {
  namespace Application {
    class ApplicationBase;
  } // namespace Application
  namespace Sound {
    /**
     * @class SoundComponent
     * @brief サウンドコンポーネント
     */
    class SoundComponent {
    public:
      /**
       * @brief コンストラクタ
       * @param app アプリケーションの参照
       */
      SoundComponent(Application::ApplicationBase& app);
      /**
       * @brief  サウンドのバックグラウンド再生
       * @param  key サウンドに紐づけられた文字列
       * @return true:再生成功 false:再生失敗
       */
      bool PlayBackGround(std::string_view key) const;
      /**
       * @brief  サウンドのループ再生
       * @param  key サウンドに紐づけられた文字列
       * @return true:再生成功 false:再生失敗
       */
      bool PlayLoop(std::string_view key) const;
      /**
       * @brief  指定した音声の再生を停止する
       * @param  key サウンドに紐づけられた文字列
       * @return true:停止成功 false:キーが不正
       */
      bool StopSound(std::string_view key) const;
      /**
       * @brief  ミュートフラグの設定
       * @param  flag セットするフラグ
       */
      inline void SetMute(const bool flag) {
        _mute = flag;
      }
    private:
      Application::ApplicationBase& _app; //!< アプリケーションの参照
      bool _mute{false}; //!< ミュートフラグ
      /**
       * @brief  サウンドの再生
       * @param  key サウンドに紐づけられた文字列
       * @param  type 再生タイプ
       * @return true:再生成功 false:再生失敗
       */
      bool Play(std::string_view key, const int type) const;
      /**
       * @brief  サウンドハンドルの取得
       * @return 取得したサウンドハンドルを返す
       *         取得に失敗した場合は-1を返す
       */
      const int SoundHandle(std::string_view key) const;
    };
  } // namespace Sound;
} // namespace Gyro