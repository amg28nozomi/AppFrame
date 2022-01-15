/*****************************************************************//**
 * @file   LoadJson.h
 * @brief  jsonファイルの読み取り処理クラス
 *
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <unordered_map>
#include <vector>
#include <filesystem>
#ifdef _DEBUG
#include <stdexcept>
#endif
#include <nlohmann/json.hpp>
#include "../Data/DivGraph.h"

namespace AppFrame {
  namespace FileServer {
    constexpr auto JSON = ".json"; //!< jsonファイルのフォーマット
    /**
     * @class LoadJson
     * @brief jsonファイルの読み取りを行う静的クラス
     */
    class LoadJson {
    public:
      /**
       * @brief  jsonファイルの読み取り処理(DivGraph用)
       * @param  jsonPath
       * @return DivGraph用のデータが格納された動的配列
       *         first:連想配列の登録に使用するキー pair:画像ファイル情報
       */
      //static std::vector<std::pair<std::string_view,
      //  std::filesystem::path>> LoadDivGraoh(std::filesystem::path jsonPath);
      /**
       * @brief  jsonファイルの読み取り処理
       * @param  jsonPath jsonファイルのパス
       * @return 取得したファイルデータを返す
       * @throw  std::logic_error
       */
      //static std::vector<std::pair<std::string, Data::DivGraph>> LoadJsonFile(std::filesystem::path jsonPath);
      /**
       * @brief  対象ファイルがjsonファイルかを判定する
       * @param  path 判定ファイルのパス
       * @return jsonファイルの場合はtrue
       *         そうではない場合はfalseを返す
       */
      static bool IsJson(const std::filesystem::path path);
    private:
      /**
       * @brief  jsonファイルの読み取り
       * @param  jsonFile 対象ファイルのパス
       * @return 読み取りに成功した場合は対象のjsonオブジェクトを返す
       *         読み取りに失敗した場合は空のオブジェクトを返す
       */
      //static nlohmann::json LoadJsonFile(std::filesystem::path jsonFile);
#ifdef _DEBUG
      /**
       * @brief  エラーメッセージの取得
       * @param  left  左辺値
       * @param  right 右辺値
       * @return 差分に応じたエラーメッセージを返す
       * @throw  std::logic_error
       */
      static std::string_view Differebce(const int key, const int path) noexcept;
      /**
       * @brief  std::logic_errorの取得
       * @param  message エラーに持たせる文字列
       * @return 設定したlogic_errorを返す
       */
      static std::logic_error GetLogicError(std::string message);
#endif
    };
  } // namespace FileServer
} // namespace AppFrame