/*****************************************************************//**
 * @file   ModeServer.h
 * @brief  �e��V�[�����Ǘ�����T�[�o�N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <memory>
#include <unordered_map>
#include <list>

namespace AppFrame {
  namespace Mode {

    class ModeBase;
    /**
     * @class ModeServer
     * @brief ���[�h�̊Ǘ��E������s���T�[�o
     */
    class ModeServer {
    public:
      /**
       * @brief string�^�̕�����Ń��[�h�̃|�C���^���Ǘ�����A�z�z��
       */
      using ModeMap = std::unordered_map<std::string, std::shared_ptr<ModeBase>>;
      /**
       * @brief ���[�h�X�^�b�N�p�̃��X�g
       */
      using ModeList = std::list<std::shared_ptr<ModeBase>>;
      /**
       * @brief �R���X�g���N�^
       * @param key  �ŏ��ɓo�^����V�[���̃L�[
       * @param mode �ŏ��ɓo�^����V�[��
       */
      ModeServer(std::string_view key, std::shared_ptr<ModeBase> mode);
      /**
       * @brief ���[�h�̓o�^
       * @param key  �L�[�ƂȂ镶����
       * @param mode ���[�h
       * @return ture:�o�^���� false:�o�^���s
       */
      bool Register(std::string_view key, std::shared_ptr<ModeBase> mode);
      /**
       * @brief  �őO�ʂ̃��[�h�̂ݍX�V���s��
       * @return true:����I�� false:��蔭��
       */
      bool Process() const;
      /**
       * @brief  �X�^�b�N����Ă��郂�[�h�̕`�揈���Ăяo��
       * @return true:����I�� false:��蔭��
       */
      bool Draw() const;
    private:
      ModeMap _registry; //!< ���W�X�g���\
      ModeList _modes;   //!< �X�^�b�N
    };
  } // namespace Mode
} // namespace AppFrame