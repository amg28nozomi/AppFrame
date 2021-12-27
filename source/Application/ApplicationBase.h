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
  constexpr auto WindowWidth = 1920;  //!< �f�t�H���g�̉𑜓x���
  constexpr auto WindowHeight = 1080; //!< �f�t�H���g�̉𑜓x���
  constexpr auto BitColor32 = 32;     //!< 32�r�b�g�J���[
  constexpr auto BitColor16 = 16;     //!< 16�r�b�g�J���[
  namespace FileServer {
    class FileServer;
  } // namespace FileServer
  /** Application�p���O��� */
  namespace App {
    /**
     * @class ApplicationBase
     * @brief �A�v���P�[�V�����̊��N���X
     */
    class ApplicationBase {
    public:
      /**
       * @brief  �A�v���P�[�V�����̏��
       */
      enum class State {
        Play,   //!< ���s��
        Paused, //!< �ꎞ��~
        Quit    //!< �I��
      };
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
       * @brief  ���s����
       */
      virtual void Run();
      /**
       * @brief  ���͏���
       * @return true:�������� false:�������s
       * @throw
       */
      virtual bool Input();
      /**
       * @brief  �X�V����
       * @return true:�������� false:�������s
       */
      virtual bool Process();
      /**
       * @brief  �`�揈��
       * @return true:�������� false:�������s
       */
      virtual bool Draw();
      /**
       * @brief  ��ʃT�C�Y�̎擾
       * @return ��ʂ̏c���Ɖ�����Ԃ�
       */
      inline const auto GetWindowSize() {
        return std::make_pair(std::get<0>(_window), std::get<1>(_window));
      }
      /**
       * @brief  �E�B���h�E���̎擾
       * @return �E�B���h�E�T�C�Y�E�J���[�r�b�g����Ԃ�
       */
      inline const auto GetWidnowData() {
        return _window;
      }
      /**
       * @brief  �E�B���h�E���̐ݒ�
       * @param  width  �𑜓x
       * @param  height �𑜓x
       * @param  bit    �J���[�r�b�g����ύX���邩�̃t���O
       *                true:32�r�b�g�J���[(�f�t�H���g)  false:16�r�b�g�J���[
       */
      static void SetWindowSize(int width, int height, bool bit = true);
    protected:
      State _state{State::Play}; //!< �A�v���P�[�V�����̏��
      static inline std::tuple<int, int, int> _window; //!< �E�B���h�E���
      static inline bool _isAdd{false}; //!< �����t���O
      static inline bool _windowMode;    //!< �E�B���h�E���[�h
      static inline std::shared_ptr<ApplicationBase> _instance{ nullptr }; //!< ����
      std::unique_ptr<FileServer::FileServer> _fileServer;  //!< �t�@�C���T�[�o
    };
  } // namespace App
} // namespace AppFrame