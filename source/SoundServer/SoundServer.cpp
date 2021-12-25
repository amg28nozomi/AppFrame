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
#include "../FileServer/LoadJson.h"

namespace AppFrame {
  namespace Sound {

    SoundServer::SoundMap SoundServer::_sounds;
    std::filesystem::path SoundServer::_directory;

    void SoundServer::Init() {
      _sounds.clear();
      _directory.clear();
    }

    bool SoundServer::AddSound(std::string_view key, std::filesystem::path path) {
      namespace fs = std::filesystem;
      // ファイルは存在するか
      if (!fs::exists(path)) {
#ifdef _DEBUG
        throw std::logic_error("パスが不正です");
#endif
        return false; // 存在しない
      }
      // キーは既に登録されているか
      if (_sounds.contains(key.data())) {
#ifdef _DEBUG
        throw std::logic_error("SoundServer:キーが重複しています\n");
#endif
        return false;
      }
      // サウンドハンドルの取得
      auto handle = LoadSoundMem(path.string().c_str());
      if (handle == -1) {
        // 読み取り失敗
#ifdef _DEBUG
        throw std::logic_error("SoundServer:音源ファイルの読み取りに失敗しました\n");
#endif
        return false;
      }
      _sounds.emplace(key.data(), handle);
      return true; // 登録成功
    }

    bool SoundServer::LoadSoundFiles(std::vector<class SoundMem> soundFile) {
      if (soundFile.empty()) {
        return false; // 要素無し
      }
#ifdef _DEBUG
      int miss = 0; // 登録に失敗した回数
#endif
      for (auto file : soundFile) {
        // 登録情報
        auto key = file.GetKey();
        auto path = file.GetFilePath();
#ifndef _DEBUG
        AddSound(key, path);
      }
      return true;
    }
#else
        try {
          // 登録に失敗した場合はカウントを増加させる
          if (!AddSound(key, path)) {
            ++miss;
          }
        }
        catch (std::logic_error error) {
          OutputDebugString(error.what());
        }
      }
      if (miss) {
        throw std::logic_error("SoundServer:" + std::to_string(miss) + "回登録処理に失敗しました");
      }
      return true; // 正常終了
    }
#endif

    const int SoundServer::GetSoundMem(std::string_view key) {
      // キーの検索
      auto ite = _sounds.find(key.data());
      if (ite == _sounds.end()) {
        return -1; // 未登録
      }
      return ite->second; // 取得成功
    }

  } // namespace Sound
} // nemaspace AppFrame