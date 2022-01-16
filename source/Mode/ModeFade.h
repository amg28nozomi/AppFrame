/*****************************************************************//**
 * @file   ModeFade.h
 * @brief  ���[�h�x�[�X�̃T�u�N���X
 *         �V�[���J�ڎ��̃t�F�[�h�������s��
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#pragma once
#include "ModeBase.h"
/**
 * @brief �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief Data
   */
  namespace Data {
    class Color;
  }
  /**
   * @brief ���[�h�x�[�X
   */
  namespace Mode {
    /**
     * @class ModeFade
     * @brief �V�[���J�ڗp���[�h
     *        �V�[���J�ڎ��̃t�F�[�h�������s��
     */
    class ModeFade : public ModeBase {
    public:
      /**
       * @brief �R���X�g���N�^
       * @param app �A�v���P�[�V�����̎Q��
       * @param color �t�F�[�h�����Ŏg�p����RGB�l
       */
      ModeFade(Application::ApplicationBase& app, const Data::Color color);
      /**
       * @brief �f�X�g���N�^
       */
      ~ModeFade() override;
      /**
       * @brief  ����������
       * @return true
       */
      bool Init() override;
      /**
       * @brief  ��������
       * @return true
       */
      virtual bool Enter() override;
      /**
       * @brief  �X�V����
       * @return true
       */
      virtual bool Process() override;
      /**
       * @brief  �`�揈��
       * @return true
       */
      virtual bool Draw() const override;
      /**
       * @brief �W���J���[�̐ݒ�
       * @param color �ݒ肷��RGB�l
       */
      void SetColor(const Data::Color color);
    protected:
      int _width;  //!< �t�F�[�h�{�b�N�X�̉���
      int _height; //!< �t�F�[�h�{�b�N�X�̏c��
      Data::Color _basic; //!< �W���J���[�l
      Data::Color _color; //!< �t�F�[�h�����Ŏg�p����RGBA�l
    };
  } // namespace Mode
} // namespace AppFrame