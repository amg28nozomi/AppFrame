/*****************************************************************//**
 * @file   ServerBase.h
 * @brief  サーバの基底クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <filesystem>
#include <unordered_map>
#include <vector>
#ifdef _DEBUG
#include <stdexcept>
#endif

namespace AppFrame {

  namespace FileServer {
    class FileBase;
  }

  namespace Data {
    /**
     * @tparam T 連想配列の値に該当する型
     * @tparam I 登録処理で使用する型
     */
    template <typename T, typename I>
    /**
     * @class ServerBase
     * @brief サーバの基底クラス
     */
    class ServerBase {
    public:
#ifndef _DEBUG
      /**
       * @brief  コンストラクタ(Release)
       */
      ServerBase();
#else
      /**
       * @brief  コンストラクタ(Debug)
       * @param  flag ログ出力フラグ(デフォルトではfalse)
       */
      ServerBase(const bool flag = false);
#endif
      /**
       * @brief  デストラクタ
       */
      virtual ~ServerBase() = 0;
      /**
       * @brief  初期化
       */
      virtual bool Init();
      /**
       * @brief  解放処理
       * @return true:処理成功 false:問題発生
       */
      virtual bool Release() = 0;
      /**
       * @brief  登録処理用純粋仮想関数
       *         登録処理は派生クラス側で実装すること
       * @param  files ファイル情報
       * @param  value 登録する値
       * @return true:登録成功 false:登録失敗
       */
      virtual bool Register(std::string_view key, const I value) = 0;
      /**
       * @brief  ファイル情報の読み込み
       * @param  files ファイル情報
       * @return true:処理成功 false:問題発生
       */
      virtual bool LoadFiles(std::vector<FileServer::FileBase> files);
      /**
       * @brief  指定した値の取得
       * @param  key 値に紐づけられた文字列
       */
      virtual T Get(std::string_view key) const = 0;
    protected:
      std::unordered_map<std::string, T> _registry; //!< レジストリー
      /**
       * @brief  対象ファイルが存在するかの判定
       * @param  filePath 対象ファイルのパス
       * @return true:ファイルは存在する false:ファイルは存在しない
       * @throw  Debug:パスが有効ではない場合、logic_errorを返す
       */
      bool Exist(std::filesystem::path filePath) const;
      /**
       * @brief  ファイル拡張子が一致しているかの判定(Debug)
       * @param  filePath ファイルのパス
       * @param  extension 対応するファイル拡張子
       * @return true:一致 false:一致していない
       * @throw  一致していない場合、logic_errorを返す
       */
      bool HasExtension(std::filesystem::path filePath, std::string_view extension) const;
      /**
       * @brief  キーが使用可能かの判定
       * @param  key レジストリへの登録で使用する文字列
       * @return true:使用可能 false:すでに使用されている
       */
      bool UsedKey(std::string_view key) const;
      /**
       * @brief  対象データが有効かの判定
       * @param  file ファイルデータ
       * @param  extension ファイル拡張子(デフォルトは拡張子なし)
       * @return true:有効 false:有効ではない
       */
      bool IsTarget(FileServer::FileBase file, std::string_view extension = "") const;
      /**
       * @brief  キーの検索
       * @param  key 検索する文字列
       * @return true:登録済み false:未登録
       * @throw  Debug:既に使用されている場合、例外を発射する
       */
      bool KeySearch(std::string_view key);
#ifdef _DEBUG
      std::string _name; //!< サーバー名
      bool _debug;       //!< ログ出力フラグ
      /**
       * @brief  logic_errorの生成
       * @param  message 使用するエラー文
       * @return 指定した形式に変換したlogic_error
       */
      std::logic_error LogicError(std::string_view message) const;
      /**
       * @brief ログへの出力処理
       * @param message 出力する文字列
       */
      void DebugString(std::string_view message);
#endif
    };

  } // namespace Data
} // namespace AppFrame
