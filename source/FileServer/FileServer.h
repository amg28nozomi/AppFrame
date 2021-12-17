/*****************************************************************//**
 * @file   FileServer.h
 * @brief  ファイルデータを管理するサーバクラス
 *
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <unordered_map>
#include "FileOutput.h"

/** FileWorker用名前空間 */
namespace AppFrame {
  namespace FileServer {
    class FileBase;
    /**
     * @class FileServer
     * @brief ファイルデータを管理するサーバ
     */
    class FileServer {
    private:
      /** 文字列をキーとしてファイルデータを管理する連想配列 */
      using FileBaseMap = std::unordered_map<std::string, FileBase>;
    public:
      /**
       * @brief  ファイルサーバの生成
       */
      FileServer();
      /**
       * @brief  ファイルサーバの破棄
       */
      ~FileServer();
      /**
       * @brief  サーバの初期化処理
       * @return 初期化フラグ
       */
      bool Init();
      /**
       * @brief  データの解放処理
       */
      void Release();
      /**
       * @brief  ファイル情報の読み取り処理
       * @param  jsonPath 読み取るJsonファイルのパス
       * @return 読み取り処理に成功した場合はtrueを返す
       */
      bool LoadFileMap(std::filesystem::path jsonPath);
      /**
       * @brief  ログ出力フラグの設定
       * @param  flag 出力フラグ
       * @param  logPath ログファイルを出力するディレクトリパス
       * @return 設定に成功した場合はtrue
       *         失敗した場合はfalseを返す
       */
      bool SetLogTextFlag(bool flag, std::filesystem::path logPath);
    private:
      FileBaseMap _fileMap; //!< ファイル情報を管理するコンテナ
      FileOutput _debugLog; //!< デバッグ用ファイル出力システム
      bool _debug;          //!< デバッグ出力用フラグ
      /**
       * @brief  ファイル情報の登録処理
       * @param  fileMap 登録を行うファイル情報
       * @return 登録処理が正常終了した場合はtrue
       *         失敗した場合はfalseを返す
       */
      bool LoadFileMap(FileBaseMap& fileMap);
      /**
       * @brief      識別子の判定を行う
       * @param path 判定ファイル
       * @return
       */
      bool FileCheck(const std::filesystem::path path);
#ifdef _DEBUG
      /**
       * @brief  ログ出力
       * @param  text 出力する文字列
       */
      void DebugStringLog(const std::string text);
#endif
    };
  } // namespace FileServer
} // namespace AppFrame