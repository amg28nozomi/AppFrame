/*****************************************************************//**
 * @file   ModeBase.h
 * @brief  ���[�h�̊��N���X
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once

namespace AppFrame {
  namespace App {
    /**
     * @class ApplicationBase
     * @brief �O���錾
     */
    class ApplicationBase;
  }
  namespace Mode {
    /**
     * @class ModeBase
     * @brief �V�[���̊��N���X
     */
    class ModeBase {
    public:
      /**
       * @brief ���[�h�̐���
       * @param app �A�v���P�[�V�����̎Q��
       */
      ModeBase(App::ApplicationBase& app);
      /**
       * @brief ���[�h�̍폜
       */
      ~ModeBase();
      /**
       * @brief  ���[�h�̏�����
       * @return true:���������� false:���������s
       */
      virtual bool Init() = 0;
      /**
       * @brief  ��������
       * @return true:�������� false:�������s
       */
      virtual bool Enter();
      /**
       * @brief  �o������
       * @return true:�������� false:���s
       */
      virtual bool Exit();
      /**
       * @brief  ���[�h�̍X�V
       * @return true:�X�V���� false:�X�V���s
       */
      virtual bool Process();
      /**
       * @brief  ���[�h�̕`��
       * @return true:�`�搬�� false:�`�掸�s
       */
      virtual bool Draw();
      /**
       * @brief  �A�v���P�[�V�����̎擾
       * @return �A�v���P�[�V�����̎Q��
       */
      inline App::ApplicationBase& GetApplication() const {
        return _app;
      }
    protected:
      App::ApplicationBase& _app; //!< �A�v���P�[�V�����̎Q��
    };
  } // namespace Mode
} // namespace AppFrame