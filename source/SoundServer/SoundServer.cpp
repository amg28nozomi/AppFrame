/*****************************************************************//**
 * @file   SoundServer.cpp
 * @brief  音源を管理するサーバクラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "SoundServer.h"
#include <DxLib.h>
#include "SoundMem.h"

namespace AppFrame {
  namespace Sound {

    SoundServer::SoundServer() : Server::ServerTemplateUnordered<std::string, int>() {
#ifdef _DEBUG
      _name = "SoundServer";
#endif
    }

    bool SoundServer::Release() {
      if (_registry.empty()) {
        return true; // データが空
      }
      // サウンドハンドルの全開放を行う
      for (auto [key, handle] : _registry) {
        // サウンドハンドルの解放を行う
        DeleteSoundMem(handle);
      }
      _registry.clear(); // レジストリを解放する
      return true; // 正常終了
    }

    bool SoundServer::AddSound(std::string_view key, const std::filesystem::path soundFile) {
      // キーは未使用か
      if (!SoundServer::UsedKey(key.data())) {
        return false; // キーが重複している
      }
      // 音源情報の読み取り
      auto handle = LoadSoundMem(soundFile.string().data());
      // サウンドハンドルの取得に成功したか
      if (handle == -1) {
        return false; // 読み取り失敗
      }
      // レジストリに登録
      _registry.emplace(key.data(), handle);
    }

    int SoundServer::GetSoundMem(std::string_view key) const {
      if (!UsedKey(key.data())) {
        return -1; // キーが有効ではない
      }
      // サウンドハンドルを返す
      return _registry.at(key.data());
    }
  } // namespace Sound
} // nemaspace AppFrame