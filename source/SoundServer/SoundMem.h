/*****************************************************************//**
 * @file   SoundMem.h
 * @brief  音源ファイル情報クラス
 * 
 * @author 鈴木希海
 * @date   December 2021
 *********************************************************************/
#include <tuple>
#include "../FileServer/FileBase.h"
namespace AppFrame {
  namespace Sound {
    /**
     * @class SoundMem
     * @brief 音源ファイルクラス
     */
    class SoundMem : public FileServer::FileBase {
    public:
      /**
       * @brief 音源情報の生成
       * @param filePath 音源ファイルのパス
       */
      SoundMem(std::filesystem::path filePath, const int playType);
      /**
       * @brief  サウンドハンドルの取得
       * @return サウンドハンドル
       */
      inline const auto GetSoundHandle() const {
        return _soundHandle;
      }
      /**
       * @brief  再生タイプの取得
       * @return 再生タイプ
       */
      inline const auto GetPlayType() const {
        return _playType;
      }
      /**
       * @brief  音源情報の取得
       * @return サウンドハンドル 再生タイプ
       */
      inline const auto GetSoundData() const {
        return std::make_pair(_soundHandle, _playType);
      }
    private:
      int _soundHandle; //!< サウンドハンドル
      int _playType;    //!< 再生タイプ
    };
  } // namespace Sound
} // namespace AppFrame