/*****************************************************************//**
 * @file   ApplicationBase.h
 * @brief  �A�v���P�[�V�����̃X�[�p�[�N���X
 *         �S�ẴA�v���P�[�V�����͂��̃N���X��h������
 * 
 * @author ��؊�C
 * @date   December 2021
 *********************************************************************/
#pragma once
#include <tuple>
#include <memory>

/** �t���[�����[�N�p���O��� */
namespace AppFrame {
  constexpr auto WINDOW_W = 1920; //!< �f�t�H���g�̉𑜓x
  constexpr auto WINDOW_H = 1080; //!< �f�t�H���g�̉𑜓x
  constexpr auto COLOR_BIT_32 = 32;  //!< �f�t�H���g�̃J���[�r�b�g��
  constexpr auto COLOR_BIT_16 = 16;  //!<
  /** Application�p���O��� */
  namespace App {
    /**
     * @class ApplicationBase
     * @brief �A�v���P�[�V�����̊��N���X
     */
    class ApplicationBase {
    public:
      /**
       * @brief �R���X�g���N�^
       * 
       */
      ApplicationBase();
      /**
       * @brief �f�X�g���N�^
       */
      ~ApplicationBase();
      /**
       * @brief  �A�v���P�[�V�����̏�����
       * @return �������ɐ��������ꍇ��true
       *         ���s�����ꍇ��false��Ԃ�
       */
      virtual bool Init();
      /**
       * @brief  ��ʃT�C�Y�̎擾
       * @return ��ʂ̏c���Ɖ�����Ԃ�
       */
      inline auto GetWindowSize() {
        return std::make_pair(std::get<0>(_window), std::get<1>(_window));
      }
      /**
       * @brief  �E�B���h�E���̎擾
       * @return �E�B���h�E�T�C�Y�E�J���[�r�b�g����Ԃ�
       */
      inline auto GetWidnowData() {
        return _window;
      }
      /**
       * @brief  �E�B���h�E���̐ݒ�
       * @param  width  �𑜓x
       * @param  height �𑜓x
       * @param  bit    �J���[�r�b�g����ύX���邩�̃t���O
       *                true()
       */
      static void SetWindowSize(int width, int height, bool bit = true);
    protected:
      static inline std::tuple<int, int, int> _window; //!< �E�B���h�E���
      static inline bool _isAdd = false; //!< �����t���O
      static inline bool _windowMode;    //!< �E�B���h�E���[�h
      static inline std::shared_ptr<ApplicationBase> _instance; //!< ����
    };
  }
} // namespace AppFrame

