/*****************************************************************//**
 * @file   SoundServer.h
 * @brief  音源を管理するサーバクラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <filesystem>
#include <unordered_map>

namespace AppFrame {
  namespace Sound {
    /**
     * @class SoundServer
     * @brief 音源を管理するサウンドサーバ
     */
    class SoundServer {
    private:
    public:
      /**
       * @brief サウンドサーバの生成
       */
      SoundServer();
      /**
       * @brief  初期化
       * @return true:初期化成功 false:初期化失敗
       * @throw  std::logic_error
       */
      bool Init();
    private:
      std::filesystem::path _directory; // ディレクトリ
    };
  } // namespace Sound
} // namespace AppFrame