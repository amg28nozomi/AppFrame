/*****************************************************************//**
 * @file   ModeServer.cpp
 * @brief  各種モードを管理するサーバクラスの定義
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include "ModeServer.h"
#include "ModeFadeIn.h"
#include "ModeFadeOut.h"

namespace {
  constexpr auto FadeIn = "FadeIn";   // フェードイン登録用のキー
  constexpr auto FadeOut = "FadeOut"; // フェードアウト登録用のキー
}

namespace AppFrame {
  namespace Mode {

    ModeServer::ModeServer(std::string_view key, std::shared_ptr<ModeBase> mode) :
     Server::ServerTemplateUnordered<std::string, std::shared_ptr<ModeBase>>(){
      // コンテナの初期化
      _registry.clear();
      _modes.clear();
#ifdef _DEBUG
      _name = "FileServer";
#endif
      // 各種モードの登録
      Register(FadeIn, std::make_shared<ModeFadeIn>(mode->GetApplication()));
      Register(FadeOut, std::make_shared<ModeFadeOut>(mode->GetApplication()));
      Register(key.data(), mode);
    }

    bool ModeServer::Release() {
      // 登録されている全シーンの解放を行う
      for (auto mode : _modes) {
        mode->Exit(); // 終了処理呼び出し
      }
      return false;
    }

    void ModeServer::AddMode(std::string_view key, std::shared_ptr<ModeBase> mode) {
      Register(key.data(), mode);
    }

    bool ModeServer::PushBack(std::string_view key) {
      // モードの取得
      auto mode = FetchMode(key.data());
      // モードの取得に成功したか
      if (mode == nullptr) {
#ifdef _DEBUG
        throw LogicError("対象キーが不正です");
#endif
        return false; // キーが不正
      }
      // リストの末尾に追加
      _modes.push_back(mode);
      return true;
    }

    void ModeServer::PopBuck() {
      // モードは登録されているか
      if (_modes.empty()) {
        return; // モードが未登録
      }
      // 末尾のモードを削除する
      _modes.back()->Exit();
      _modes.pop_back();
    }

    void ModeServer::InsertBeforeBack(std::string_view key) {
      auto mode = FetchMode(key.data());
      // 取得に成功したか
      if (mode == nullptr) {
        return;
      }
      _modes.insert(std::prev(_modes.end()), mode);
    }

    bool ModeServer::Process() {
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
          DebugString(error.what());
        }
#endif
      }
      return flag;
    }

    bool ModeServer::Register(std::string key, std::shared_ptr<ModeBase> mode) {
      // キーは登録しているか
      if (!UseKey(key)) {
        // 重複している場合は対象を削除
        _registry.erase(key);
      }
      mode->Init();
      _registry.emplace(key, mode);
      return true;
    }

    std::shared_ptr<ModeBase> ModeServer::FetchMode(std::string_view key) {
      // モードは登録されているか
      if (!_registry.contains(key.data())) {
        return nullptr; // 未登録
      }
      auto mode = _registry.at(key.data());
      mode->Enter(); // 入口処理を実行
      return mode;
    }

    bool ModeServer::TransionToMode(std::string_view key) {
      InsertBeforeBack(key);
      InsertBeforeBack(FadeIn);
      PushBack(FadeOut);
      return true;
    }
  } // namespace Mode
} // namespace AppFrame