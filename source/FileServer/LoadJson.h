/*****************************************************************//**
 * @file   LoadJson.h
 * @brief  jsonファイルの読み取り処理クラス
 *
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <unordered_map>
#include <filesystem>

namespace AppFrame {
  namespace FileServer {
    class FileBase;
    class FileServer;
    constexpr auto JSON = ".json"; //!< jsonファイルのフォーマット
    /**
     * @class LoadJson
     * @brief jsonファイルの読み取りを行う静的クラス
     */
    class LoadJson {
    private:
      /**
       * @brief 文字列をキーとしてファイル情報を管理する連想配列
       */
      using FileBaseMap = std::unordered_map<std::string, FileBase>;
    public:
      /**
       * @brief  jsonファイルの読み取り処理
       * @param  jsonPath jsonファイルのパス
       * @return 取得したファイルデータを返す
       * @throw  std::logic_error
       */
      static FileBaseMap LoadJsonFile(std::filesystem::path jsonPath);
      /**
       * @brief  対象ファイルがjsonファイルかを判定する
       * @param  path 判定ファイルのパス
       * @return jsonファイルの場合はtrue
       *         そうではない場合はfalseを返す
       */
      static bool IsJson(const std::filesystem::path path);
    private:
#ifdef _DEBUG
      /**
       * @brief  エラーメッセージの取得
       * @param  left  左辺値
       * @param  right 右辺値
       * @return 差分に応じたエラーメッセージを返す
       * @throw  std::logic_error
       */
      static std::string_view Differebce(const int key, const int path) noexcept;
#endif
    };
  } // namespace FileServer
} // namespace AppFrame