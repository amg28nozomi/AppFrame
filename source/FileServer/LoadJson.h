/*****************************************************************//**
 * @file   LoadJson.h
 * @brief  json�t�@�C���̓ǂݎ�菈���N���X
 *
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <unordered_map>
#include <filesystem>

namespace AppFrame {
  namespace FileServer {
    class FileBase;
    class FileServer;
    constexpr auto JSON = ".json"; //!< json�t�@�C���̃t�H�[�}�b�g
    /**
     * @class LoadJson
     * @brief json�t�@�C���̓ǂݎ����s���ÓI�N���X
     */
    class LoadJson {
    private:
      /**
       * @brief ��������L�[�Ƃ��ăt�@�C�������Ǘ�����A�z�z��
       */
      using FileBaseMap = std::unordered_map<std::string, FileBase>;
    public:
      /**
       * @brief  json�t�@�C���̓ǂݎ�菈��
       * @param  jsonPath json�t�@�C���̃p�X
       * @return �擾�����t�@�C���f�[�^��Ԃ�
       * @throw  std::logic_error
       */
      static FileBaseMap LoadJsonFile(std::filesystem::path jsonPath);
      /**
       * @brief  �Ώۃt�@�C����json�t�@�C�����𔻒肷��
       * @param  path ����t�@�C���̃p�X
       * @return json�t�@�C���̏ꍇ��true
       *         �����ł͂Ȃ��ꍇ��false��Ԃ�
       */
      static bool IsJson(const std::filesystem::path path);
    private:
#ifdef _DEBUG
      /**
       * @brief  �G���[���b�Z�[�W�̎擾
       * @param  left  ���Ӓl
       * @param  right �E�Ӓl
       * @return �����ɉ������G���[���b�Z�[�W��Ԃ�
       * @throw  std::logic_error
       */
      static std::string_view Differebce(const int key, const int path) noexcept;
#endif
    };
  } // namespace FileServer
} // namespace AppFrame