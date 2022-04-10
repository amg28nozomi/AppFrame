/*****************************************************************//**
 * @file   FileServer.h
 * @brief  ファイルデータを管理するサーバクラス
 *
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "../Server/ServerTemplateUnordered.h"
#include <filesystem>
#include "FileOutput.h"
#include "FileBase.h"

/** FileWorker用名前空間 */
namespace AppFrame {
  /**
   * @brief アプリケーションベース
   */
  namespace Application {
    class ApplicationBase; //!< アプリケーション
  } // namespace Application
  /**
   * @brief ファイルサーバ
   */
  namespace FileServer {
    class LoadJson; //!< 前方宣言
    /**
     * @class FileServer
     * @brief ファイル管理用サーバ
     */
    class FileServer : public Server::ServerTemplateUnordered<std::string, std::filesystem::path> {
    public:
      /**
       * @brief コンストラクタ
       */
      FileServer(Application::ApplicationBase& app);
      /**
       * @brief  初期化
       * @return true:初期化成功 false:初期化失敗
       */
      bool Init() override;
      /**
       * @brief  jsonファイルの読み取り
       * @param  jsonFile jsonファイルのパス
       * @return true:読み取り実行 false:問題発生
       */
      bool LoadJsonFile(std::string_view jsonFile) const;
      /**
       * @brief  対象ファイル形式の指定(Instance後、一度のみ設定可能)
       * @param  extensions ファイル拡張子(文字列)を格納した動的配列
       */
      bool SetExtension(std::vector<std::string> extensions);
    protected:
      std::unique_ptr<LoadJson> _loadJson;  //!< jsonファイルの読み取り
      std::vector<std::string> _extensions; //!< 対応ファイル形式
      bool _setExtension{false}; //!< 対象ファイル形式を指定したかの判定
      /**
       * @brief  対象ファイルが登録対象かの判定
       * @param  filePath 対象ファイルのパス
       * @param  extension 登録可能なファイル形式
       * @return true:登録対象 false:非登録対象
       */
      bool IsTarget(std::filesystem::path filePath, std::string_view extension = "") const;
      /**
       * @brief  ファイル形式が一致しているかの判定
       * @param  filePath 対象ファイルのパス
       * @return true:一致 false:対象ではない
       */
      bool HasExtension(std::filesystem::path filePath, std::string_view extension = "") const;
      /**
       * @brief  対象パスが存在するかの判定
       * @param  filePath 対象ファイルのパス
       * @return true:有効 false:パスが不正
       */
      bool Exist(std::filesystem::path filePath) const;
    };
  } // namespace FileServer
} // namespace AppFrame