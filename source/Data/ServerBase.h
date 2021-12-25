/*****************************************************************//**
 * @file   ServerBase.h
 * @brief  サーバの基底クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
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
      /**
       * @brief  コンストラクタ
       */
      ServerBase();
      /**
       * @brief  デストラクタ
       */
      virtual ~ServerBase() = 0;
      /**
       * @brief  登録処理
       * @param  files ファイル情報
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
       * @brief  キーの検索
       * @param  key 検索する文字列
       * @return true:登録済み false:未登録
       */
      bool KeySearch(std::string_view key);
#ifdef _DEBUG
      std::string _name; //!< サーバー名
      /**
       * @brief  logic_errorの生成
       * @param  message 使用するエラー文
       * @return 指定した形式に変換したlogic_error
       */
      std::logic_error LogicError(std::string_view message);
      /**
       * @brief ログへの出力処理
       * @param message 出力する文字列
       */
      void DebugString(std::string_view message);
#endif
    };

  } // namespace Data
} // namespace AppFrame
