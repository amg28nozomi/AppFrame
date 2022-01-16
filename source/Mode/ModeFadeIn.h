/*****************************************************************//**
 * @file   ModeFadeIn.h
 * @brief  ���[�h�t�F�[�h�̃T�u�N���X
 *         ���[�h�J�ڎ��̃t�F�[�h�C���������s��
 * 
 * @author ��؊�C
 * @date   January 2022
 *********************************************************************/
#pragma once
#include "ModeFade.h"
/**
 * @brief �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief ���[�h�x�[�X
   */
  namespace Mode {
    /**
     * @class ModeFadeIn
     * @brief �t�F�[�h�C������
     */
    class ModeFadeIn : public ModeFade {
    public:
      /**
       * @brief �R���X�g���N�^
       * @param app   �A�v���P�[�V�����̎Q��
       * @param color �t�F�[�h�����Ŏg�p����RGB�l
       */
      ModeFadeIn(Application::ApplicationBase& app, Data::Color color);
      /**
       * @brief  ��������
       * @return treu
       */
      bool Enter() override;
      /**
       * @brief  �X�V����
       * @return true
       */
      bool Process() override;
    private:
      /**
       * @brief  �t�F�[�h�����̏I������
       * @return true:�������� false:�����p��
       */
      bool IsFinish() override;
    };
  } // namespace Mode
} // namespace AppFrame

