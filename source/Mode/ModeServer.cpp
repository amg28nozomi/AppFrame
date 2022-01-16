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

    ModeServer::ModeServer(std::string_view key, std::shared_ptr<ModeBase> mode) :
     Server::ServerTemplateUnordered<std::string, std::shared_ptr<ModeBase>>(){
      // コンテナの初期化
      _registry.clear();
      _list.clear();
#ifdef _DEBUG
      _name = "FileServer";
#endif
    }

    bool ModeServer::Release() {
      // 登録されている全シーンの解放を行う
      for (auto mode : _list) {
        mode->Exit(); // 終了処理呼び出し
      }
      return false;
    }

    void ModeServer::AddMode(std::string_view key, std::shared_ptr<ModeBase> mode) {
      // キーが重複しているか
      if (!UsedKey(key.data())) {
        // 重複している場合は既に登録されているモードを削除
        _registry.erase(key.data());
      }
      // モードの登録
      _registry.emplace(key.data(), mode);
#ifndef _DEBUG
      // モードの初期化
      mode->Init();
#else
      try {
        mode->Init();
      } catch (std::logic_error error) {
        // 初期化で問題発生
        DebugString(error.what());
      }
#endif
    }

    bool ModeServer::Process() const {
      // モードはスタックされているか
      if (_list.empty()) {
        return true; // 未登録
      }
#ifndef _DEBUG
      return _list.back()->Process();
#else
      auto flag = true; // 処理フラグ
      try {
        flag = _list.back()->Process();
      } catch (std::logic_error error) {
        OutputDebugString(error.what());
      }
      return flag;
#endif
    }

    bool ModeServer::Draw() const {
      auto flag = true; // 処理フラグ
      // スタックされているモードの描画
      for (auto&& mode : _list) {
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
          DebugString(error.what());
        }
#endif
      }
      return flag;
    }
  } // namespace Mode
} // namespace AppFrame