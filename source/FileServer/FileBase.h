/*****************************************************************//**
 * @file   FileBase.h
 * @brief  ファイルデータを保持するスーパークラス
 *
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <filesystem>

/** FileWorker用名前空間 */
namespace AppFrame {
  namespace FileServer {
    /**
     * @class FileBase
     * @brief ファイルデータ
     */
    class FileBase {
    public:
      /**
       * @brief 空データを生成
       */
      FileBase();
      /**
       * @brief ファイルデータの生成
       * @param filePath ファイルのパス
       */
      FileBase(std::filesystem::path filePath);
      /**
       * @brief ファイルデータの破棄
       */
      ~FileBase();
      /**
       * @brief パスの破棄
       */
      inline void Clear() {
        _path.clear();
      }
      /**
       * @brief  パスの取得
       * @return ファイルパスを返す
       */
      inline std::filesystem::path GetFilePath() const {
        return _path;
      }
      /**
       * @brief  ファイル名の取得
       * @return 拡張子を除いたファイル名を返す
       */
      inline std::string GetFileName() const {
        return _path.stem().string();
      }
    protected:
      std::filesystem::path _path; //!< ファイルパス
    };
  } // namespace FileServer
} // namespace AppFrame