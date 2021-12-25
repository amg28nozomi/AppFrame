/*****************************************************************//**
 * @file   SoundServer.cpp
 * @brief  ‰¹Œ¹‚ğŠÇ—‚·‚éƒT[ƒoƒNƒ‰ƒX‚Ì’è‹`
 * 
 * @author —é–ØŠóŠC
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
      // ƒtƒ@ƒCƒ‹‚Í‘¶İ‚·‚é‚©
      if (!fs::exists(path)) {
#ifdef _DEBUG
        throw std::logic_error("ƒpƒX‚ª•s³‚Å‚·");
#endif
        return false; // ‘¶İ‚µ‚È‚¢
      }
      // ƒL[‚ÍŠù‚É“o˜^‚³‚ê‚Ä‚¢‚é‚©
      if (_sounds.contains(key.data())) {
#ifdef _DEBUG
        throw std::logic_error("SoundServer:ƒL[‚ªd•¡‚µ‚Ä‚¢‚Ü‚·\n");
#endif
        return false;
      }
      // ƒTƒEƒ“ƒhƒnƒ“ƒhƒ‹‚Ìæ“¾
      auto handle = LoadSoundMem(path.string().c_str());
      if (handle == -1) {
        // “Ç‚İæ‚è¸”s
#ifdef _DEBUG
        throw std::logic_error("SoundServer:‰¹Œ¹ƒtƒ@ƒCƒ‹‚Ì“Ç‚İæ‚è‚É¸”s‚µ‚Ü‚µ‚½\n");
#endif
        return false;
      }
      _sounds.emplace(key.data(), handle);
      return true; // “o˜^¬Œ÷
    }

    bool SoundServer::LoadSoundFiles(std::vector<class SoundMem> soundFile) {
      if (soundFile.empty()) {
        return false; // —v‘f–³‚µ
      }
#ifdef _DEBUG
      int miss = 0; // “o˜^‚É¸”s‚µ‚½‰ñ”
#endif
      for (auto file : soundFile) {
        // “o˜^î•ñ
        auto key = file.GetKey();
        auto path = file.GetFilePath();
#ifndef _DEBUG
        AddSound(key, path);
      }
      return true;
    }
#else
        try {
          // “o˜^‚É¸”s‚µ‚½ê‡‚ÍƒJƒEƒ“ƒg‚ğ‘‰Á‚³‚¹‚é
          if (!AddSound(key, path)) {
            ++miss;
          }
        }
        catch (std::logic_error error) {
          OutputDebugString(error.what());
        }
      }
      if (miss) {
        throw std::logic_error("SoundServer:" + std::to_string(miss) + "‰ñ“o˜^ˆ—‚É¸”s‚µ‚Ü‚µ‚½");
      }
      return true; // ³íI—¹
    }
#endif

    const int SoundServer::GetSoundMem(std::string_view key) {
      // ƒL[‚ÌŒŸõ
      auto ite = _sounds.find(key.data());
      if (ite == _sounds.end()) {
        return -1; // –¢“o˜^
      }
      return ite->second; // æ“¾¬Œ÷
    }

  } // namespace Sound
} // nemaspace AppFrame