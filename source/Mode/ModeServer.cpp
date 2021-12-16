/*****************************************************************//**
 * @file   ModeServer.cpp
 * @brief  
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "ModeServer.h"
#include <stdexcept>
#include <Windows.h>
#include "ModeBase.h"

namespace AppFrame {
  namespace Mode {

    ModeServer::ModeServer(std::string_view key, std::shared_ptr<ModeBase> mode) {
      // コンテナの初期化
      _registry.clear();
      _modes.clear();

    }

    bool ModeServer::Register(std::string_view key, std::shared_ptr<ModeBase> mode) {
      if (_registry.contains(key.data())) {
        _registry.erase(key.data());
      }
      // モードの登録
      _registry.emplace(key, mode);
      auto flag = false; // 初期化フラグ
      // モードの初期化
#ifndef _DEBUG
      flag = mode->Init();
#else
      try {
        flag = mode->Init();
      } catch (std::logic_error error) {
        // 初期化処理失敗
        OutputDebugString(error.what());
      }
#endif
      return flag;
    }

    bool ModeServer::Process() const {
      // モードはスタックされているか
      if (_modes.empty()) {
        return true; // 未登録
      }
#ifndef _DEBUG
      return _modes.back()->Process();
#else
      auto flag = true; // 処理フラグ
      try {
        flag = _modes.back()->Process();
      } catch (std::logic_error error) {
        OutputDebugString(error.what());
      }
      return flag;
#endif
    }

    bool ModeServer::Draw() const {
      auto flag = true; // 処理フラグ
      // スタックされているモードの描画
      for (auto&& mode : _modes) {
#ifndef _DEBUG
        // 描画処理は正常終了したか
        if (!mode->Draw()) {
          flag = false; // 問題発生
        }
#else
        try {
          if (!mode->Draw()) {
            flag = false; 
          }
        } catch (std::logic_error error) {
          // 例外が発生した場合はログに出力
          OutputDebugString(error.what());
        }
#endif
      }
      return flag;
    }
  } // namespace Mode
} // namespace AppFrame