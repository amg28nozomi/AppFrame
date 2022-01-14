/*****************************************************************//**
 * @file   ModeServer.h
 * @brief  �e��V�[�����Ǘ�����T�[�o�N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "../Server/ServerTemplateUnordered.h"
#include <memory>
#include <list>
#include "ModeBase.h"

namespace AppFrame {
  namespace Mode {
    /**
     * @class ModeServer
     * @brief ���[�h�̊Ǘ����s���T�[�o
     */
    class ModeServer : public Server::ServerTemplateUnordered<std::string, std::shared_ptr<Mode::ModeBase>> {
    public:
      /**
       * @brief �R���X�g���N�^
       * @param key  �o�^�Ɏg�p���镶����
       * @param mode �ŏ��ɓo�^����V�[���̃|�C���^
       */
      ModeServer(std::string_view key, std::shared_ptr<ModeBase> mode);
      /**
       * @brief  ���[�h�̉��
       * @return true:�J������ false:������s
       */
      bool Release() override;
      /**
       * @brief  �f�[�^�x�[�X�Ƀ��[�h��o�^����
       * @param  key �o�^�Ɏg�p���镶����
       * @param  mode �o�^���郂�[�h
       * @return true:�o�^���� false:�o�^���s
       */
      bool AddMode(std::string_view key, std::shared_ptr<ModeBase> mode);
      /**
       * @brief  ���[�h�̍X�V
       * @return 
       */
      bool Process() const;
      /**
       * @brief  ���[�h�̕`��
       * @return 
       */
      bool Draw() const;
    private:
      std::list<std::shared_ptr<Mode::ModeBase>> _list; //!< ���[�h�̃X�^�b�N
    };

    /**
     * @class ModeServer
     * @brief ���[�h�̊Ǘ��E������s���T�[�o
     */
    //class ModeServer {
    //public:
    //  /**
    //   * @brief string�^�̕�����Ń��[�h�̃|�C���^���Ǘ�����A�z�z��
    //   */
    //  using ModeMap = std::unordered_map<std::string, std::shared_ptr<ModeBase>>;
    //  /**
    //   * @brief ���[�h�X�^�b�N�p�̃��X�g
    //   */
    //  using ModeList = std::list<std::shared_ptr<ModeBase>>;
    //  /**
    //   * @brief �R���X�g���N�^
    //   * @param key  �ŏ��ɓo�^����V�[���̃L�[
    //   * @param mode �ŏ��ɓo�^����V�[��
    //   */
    //  ModeServer(std::string_view key, std::shared_ptr<ModeBase> mode);
    //  /**
    //   * @brief ���[�h�̓o�^
    //   * @param key  �L�[�ƂȂ镶����
    //   * @param mode ���[�h
    //   * @return ture:�o�^���� false:�o�^���s
    //   */
    //  bool Register(std::string_view key, std::shared_ptr<ModeBase> mode);
    //  /**
    //   * @brief  �őO�ʂ̃��[�h�̂ݍX�V���s��
    //   * @return true:����I�� false:��蔭��
    //   */
    //  bool Process() const;
    //  /**
    //   * @brief  �X�^�b�N����Ă��郂�[�h�̕`�揈���Ăяo��
    //   * @return true:����I�� false:��蔭��
    //   */
    //  bool Draw() const;
    //private:
    //  ModeMap _registry; //!< ���W�X�g���\
    //  ModeList _modes;   //!< �X�^�b�N
    //};
  } // namespace Mode
} // namespace AppFrame