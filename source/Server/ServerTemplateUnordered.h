/*****************************************************************//**
 * @file   ServerTemplateUnordered.h
 * @brief  �T�[�o�p�e���v���[�g�N���X(unordered_map)
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#pragma once
#include "ServerBase.h"
#include <unordered_map>
/**
 * @brief �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief �T�[�o�x�[�X
   */
  namespace Server {
    /**
     * @class  ServerTemplateUnordered
     * @brief  �A�z�z��ɑΉ������T�[�o�e���v���[�g
     * @tparam Key �A�z�z��̃L�[�Ƃ��Ďg�p����^
     * @tparam Value �A�z�z��̒l�Ƃ��Ďg�p����^
     */
    template <typename Key, typename Value>
    class ServerTemplateUnordered : public ServerBase<std::unordered_map<Key, Value>> {
    public:
      /**
       * @brief �R���X�g���N�^
       */
      ServerTemplateUnordered();
      /**
       * @brief  ���\�[�X�̉��
       * @return true:������� false:��蔭��
       */
      virtual bool Release() override;
      /**
       * @brief  �f�t�H���g�̓o�^����
       * @param  key �o�^���ɕR�Â���L�[���
       * @param  value �o�^�p�f�[�^
       * @return true:�o�^���� false:�o�^���s
       */
      virtual bool Register(Key key, Value value);
    protected:
      /**
       * @brief  �ΏۃL�[�����g�p���̔���
       * @param  key ����Ώ�
       * @return true:�o�^�\ false:�g�p�ς�
       */
      bool UsedKey(Key key) const;


    };

    template <typename Key, typename Value>
    ServerTemplateUnordered<Key, Value>::ServerTemplateUnordered() {
    }

    template <typename Key, typename Value>
    bool ServerTemplateUnordered<Key, Value>::Release() {
      using UnorderedServer = ServerBase<std::unordered_map<Key, Value>>;
      // �f�t�H���g�ł͑S�v�f�̉���݂̂��s��
      UnorderedServer::_registry.clear();
      return true;
    }

    template <typename Key, typename Value>
    bool ServerTemplateUnordered<Key, Value>::Register(Key key, Value value) {
      using UnorderedServer = ServerBase<std::unordered_map<Key, Value>>;
      // �L�[�͓o�^�\���H
      if (!UsedKey(key)) {
        return false; // �o�^�ς�
      }
      // �o�^
      UnorderedServer::_registry.emplace(key, value);
      return true;    // �o�^����
    }

    template <typename Key, typename Value>
    bool ServerTemplateUnordered<Key, Value>::UsedKey(Key key) const {
      using UnorderedServer = ServerBase<std::unordered_map<Key, Value>>;
      // �L�[�͖��o�^��
      if (!UnorderedServer::_registry.contains(key)) {
#ifdef _DEBUG
        throw UnorderedServer::LogicError("�L�[���d�����Ă��܂�");
#endif
        return false; // �L�[���d�����Ă���
      }
      return true;    // �g�p�\
    }
  } // namespace Server
} // namespace AppFrame

