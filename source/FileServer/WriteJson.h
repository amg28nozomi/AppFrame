/*****************************************************************//**
 * @file   WriteJson.h
 * @brief  json�t�@�C���̏������ݏ����N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <filesystem>

namespace AppFrame {
  namespace FileServer {
    /**
     * @class WriteJson
     * @brief json�t�@�C���̏������ݏ����N���X
     */
    class WriteJson {
    public:
    private:
      static std::filesystem::path _path; //!< �������s���f�B���N�g��
      /**
       * @brief  json�t�@�C���̐���
       * @param  jsonName json�t�@�C���̖��O
       * @return ��������json�t�@�C���̃p�X
       * @throw  logic_error
       */
      static std::filesystem::path AddJson(std::filesystem::path jsonName);
    };
  } // namespace FileServer
} // namespace AppFrame

