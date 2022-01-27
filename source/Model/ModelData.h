/*****************************************************************//**
 * @file   ModelData.h
 * @brief  ���f�������Ǘ�����f�[�^�N���X
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#pragma once
#include <utility>
#include <unordered_map>
/**
 * @brief �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief ���f���x�[�X
   */
  namespace Model {
    //// class ModelServer;
    //constexpr unsigned short MaxNumber = 65535;
    //constexpr auto AnimNull = -1; //!< �A�j���[�V�����ԍ��Y���Ȃ�
    ///**
    // * @class ModelData
    // * @brief ���f�����N���X
    // */
    //class ModelData {
    //  /**
    //   * @brief  ModelServer��friend�w��
    //   */
    //  friend class ModelServer;
    //public:
    //  /**
    //   * @brief �R���X�g���N�^
    //   * @param filePath �t�@�C���p�X
    //   */
    //  ModelData();

    //  bool Set(std::string_view path);
    //  /**
    //   * @brief ���f������S�폜����
    //   */
    //  void DeleteModel();
    //  /**
    //   * @brief �����������f���n���h���݂̂�S�폜����
    //   */
    //  void DeleteDuplicateHandles();
    //  /**
    //   * @brief  ���f���n���h���̎擾
    //   * @param  number �ʂ��ԍ�
    //   * @return first:�擾�ɐ��������ꍇ�̓��f���n���h����Ԃ� ���s�����ꍇ��-1��Ԃ�
    //   *         second:���ʔԍ�
    //   */
    //  std::pair<int, unsigned short> Handle(unsigned short number);
    //  /**
    //   * @brief  �w�肵���A�j���[�V�����ԍ����擾
    //   * @param  animName �A�j���[�V������
    //   * @return �擾�ɐ��������ꍇ�̓A�j���[�V�����ԍ���Ԃ�
    //   *         ���s�����ꍇ��-1��Ԃ�
    //   */
    //  int AnimIndex(std::string_view animName);
    //  /**
    //   * @brief  ���f���n���h�����i�[���ꂽ�A�z�z����擾����
    //   * @return �A�z�z��̎Q��
    //   */
    //  std::unordered_map<unsigned short, int>& GetHandles() {
    //    return _handles;
    //  }
    //  /**
    //   * @brief �A�j���[�V���������폜����
    //   */
    //  inline void AnimeClear() {
    //    _animes.clear(); // �A�j���[�V���������폜
    //  }
    //private:
    //  //!< �t�@�C���p�X
    //  std::string _filePath;
    //  //!< �ʂ��ԍ����L�[�Ƃ��ă��f���n���h�����Ǘ�����A�z�z��
    //  std::unordered_map<unsigned short, int> _handles;
    //  //!< �A�j���[�V���������L�[�Ƃ��ăA�j���[�V�����ԍ����Ǘ�����A�z�z��
    //  std::unordered_map<std::string, int> _animes;
    //};
  } // namespace Model
} // namespace AppFrame