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
      /**
       * @brief サウンドハンドルを
       */
      using SoundMap = std::unordered_map<std::string, int>;
    public:
      /**
       * @brief  初期化
       *         サウンドサーバを使用する場合は必ず初期化すること
       * @return true:初期化成功 false:初期化失敗
       * @throw  std::logic_error
       */
      static void Init();
      /**
       * @brief  音源情報の登録
       * @param  key   登録用文字列
       * @param  path  音源ファイルのパス
       * @return true:登録成功 false:登録失敗
       */
      static bool AddSound(std::string_view key, std::filesystem::path path);
      /**
       * @brief  音源ファイル情報の読み取り・登録処理
       * @param  soundFile 音源情報の動的配列
       * @return true:登録成功 false:問題発生
       */
      static bool LoadSoundFiles(std::vector<class SoundMem> soundFile);
      /**
       * @brief  指定したサウンドハンドルの取得
       * @param  key キー(文字列)
       * @return 取得に成功した場合はサウンドハンドルを返す
       *         失敗した場合は-1を返す
       */
      static const int GetSoundMem(std::string_view key);
    private:
      static std::filesystem::path _directory; // ディレクトリ
      static SoundMap _sounds; //!< サウンド情報
    };
  } // namespace Sound
} // namespace AppFrame