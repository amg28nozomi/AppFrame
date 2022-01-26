/*****************************************************************//**
 * @file   ModelData.cpp
 * @brief  モデル情報クラスの定義
 * 
 * @author 鈴木希海
 * @date   January 2022
 *********************************************************************/
#include "ModelData.h"
#include <DxLib.h>
#include <Windows.h>

namespace {
  constexpr short Begine = 0;
  constexpr unsigned short MaxNumber = 65535;
}

namespace AppFrame {
  namespace Model {

    ModelData::ModelData() {
      // 各種データの初期化
      _filePath.clear();
      _handles.clear();
      _animes.clear();
    }


    bool ModelData::Set(std::string_view path) {
      _filePath = path.data();
      
    }

    void ModelData::DeleteModel() {
      for (auto [number, handle] : _handles) {
        MV1DeleteModel(handle); // モデルハンドルを削除する
      }
      _handles.clear(); // コンテナを解放
      _animes.clear();  // アニメーション情報を削除
    }

    void ModelData::DeleteDuplicateHandles() {
      // オリジナルのモデルハンドル
      auto original = _handles.at(Begine);
      // 複製されたモデルハンドルを削除する
      std::erase_if(_handles, [original](int handle) {
        if (original != handle) {
          MV1DeleteModel(handle); // モデルハンドルを削除する
          return true;
        }
        return false;
        });
    }

    std::pair<int, unsigned short> ModelData::Handle(unsigned short number) {
      // 対象の通し番号は登録されているか
      if (_handles.contains(number)) {
        return std::make_pair(_handles.at(number), number); // モデルハンドルを返す
      }
      // 未登録の場合はオリジナルのハンドルを複製
      auto handle = DxLib::MV1DuplicateModel(_handles.at(Begine));
      // 複製に成功したか
      if (handle == -1) {
#ifdef _DEBUG
        // ハンドルが未登録の場合
        if (!_handles.size()) {
          OutputDebugString("ハンドルの複製に失敗しました。対象ハンドルはNULLです\n");
        }
#endif
        return std::make_pair(-1, MaxNumber); // 複製失敗
      }
      // 通し番号をキーとして、複製したモデルハンドルを登録する
      _handles.emplace(number, handle);
      return std::make_pair(handle, number);
    }

    int ModelData::AnimIndex(std::string_view animName) {
      // アニメーションは登録されているか
      if (!_animes.contains(animName.data())) {
        return AnimNull; // キーが未登録
      }
      // アニメーション番号を返す
      return _animes.at(animName.data());
    }
  } // namespace Model
} // namespace 