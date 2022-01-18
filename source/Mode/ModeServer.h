/*****************************************************************//**
 * @file   ModeServer.h
 * @brief  �e�탂�[�h���Ǘ�����T�[�o�N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include "../Server/ServerTemplateUnordered.h"
#include <memory>
#include <list>

namespace AppFrame {
  namespace Mode {
    class ModeBase;
    /**
     * @class ModeServer
     * @brief ���[�h�̊Ǘ����s���T�[�o
     */
    class ModeServer : public Server::ServerTemplateUnordered<std::string, std::shared_ptr<ModeBase>> {
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
       * @param  mode �o�^���郂�[�h�̃V�F�A�[�h�|�C���^
       */
      void AddMode(std::string_view key, std::shared_ptr<ModeBase> mode);
      /**
       * @brief  �w�肵�����[�h�����X�g�̖����ɒǉ�����
       * @param  key �Ώۃ��[�h�ɕR�Â���ꂽ������
       * @return true:�ǉ����� false:�ǉ����s
       */
      bool PushBack(std::string_view key);
      /**
       * @brief  ���X�g�̖����ɓo�^����Ă��郂�[�h���폜����
       */
      void PopBuck();
      /**
       * @brief  ���[�h�̑J�ڏ���
       * @param  key �Ώۃ��[�h�ɕR�Â���ꂽ������
       * @return
       */
      bool TransionToMode(std::string_view key);
      /**
       * @brief  ���[�h�̍X�V
       * @return 
       */
      bool Process();
      /**
       * @brief  ���[�h�̕`��
       * @return 
       */
      bool Draw() const;
    private:
      std::list<std::shared_ptr<ModeBase>> _modes; //!< ���[�h�̃��X�g
      /**
       * @brief  ���[�h�̓o�^
       * @param  key  ���[�h�ɕR�Â��镶����
       * @param  mode �o�^���郂�[�h
       * @return 
       */
      bool Register(std::string key, std::shared_ptr<ModeBase> mode) override;
      /**
       * @brief  �f�[�^�x�[�X����w�肵�����[�h���擾����
       * @param  key �Ώۃ��[�h�ɕR�Â���ꂽ������
       * @return �w�肵�����[�h��Ԃ�
       *         �L�[���L���ł͂Ȃ��ꍇ�Anullptr��Ԃ�
       */
      std::shared_ptr<ModeBase> FetchMode(std::string_view key);
      /**
       * @brief  ���X�g�̖����̗v�f�̒��O�Ɏw�肵�����[�h��ǉ�����
       * @param  key �Ώۃ��[�h�ɕR�Â���ꂽ������
       */
      void InsertBeforeBack(std::string_view key);
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