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
#include "../FileServer/FileServer.h"
#include "../Mode/ModeServer.h"
/**
 * @brief �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  constexpr auto WindowWidth = 1920;  //!< �f�t�H���g�̉𑜓x���
  constexpr auto WindowHeight = 1080; //!< �f�t�H���g�̉𑜓x���
  constexpr auto BitColor32 = 32;     //!< 32�r�b�g�J���[
  constexpr auto BitColor16 = 16;     //!< 16�r�b�g�J���[
  constexpr auto Frame60 = 60;        //!< 60�t���[��
  /**
   * @brief �A�v���P�[�V�����x�[�X
   */
  namespace Application {
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
      virtual ~ApplicationBase();
      /**
       * @brief  �A�v���P�[�V�����̏�����
       * @return �������ɐ��������ꍇ��true
       *         ���s�����ꍇ��false��Ԃ�
       */
      virtual bool Init();
      /**
       * @brief �A�v���P�[�V�����̉��
       */
      virtual void Release();
      /**
       * @brief  ���s����
       */
      virtual void Run();
      /**
       * @brief  �I������
       */
      virtual void Terminate();
      /**
       * @brief  �A�v���P�[�V�����̎Q�Ƃ��擾
       * @return �A�v���P�[�V�����̎Q��
       */
      static std::shared_ptr<ApplicationBase> GetInstance() {
        return _instance;
      }
      /**
       * @brief  �C���v�b�g�I�y���[�V�����̎擾
       * @return �C���v�b�g�I�y���[�V�����̎Q��
       */
      class InputOperation& GetOperation() {
        return *_input;
      }
      /**
       * @brief  ���[�h�T�[�o�̎擾
       * @return ���[�h�T�[�o�̎Q��
       */
      //Mode::ModeServer& GetModeServer() {
      //  return *_modeServer;
      //}
      /**
       * @brief  �t�@�C���T�[�o�̎擾
       * @return �t�@�C���T�[�o�̎Q��
       */
      FileServer::FileServer& GetFileServer() {
        return *_fileServer;
      }
      /**
       * @brief  ��ʃT�C�Y�̎擾
       * @return ��ʂ̏c���Ɖ�����Ԃ�
       */
      inline const std::pair<int, int> GetWindowSize() {
        return std::make_pair(_width, _height);
      }
      /**
       * @brief  �E�B���h�E���̎擾
       * @return �E�B���h�E�T�C�Y�E�J���[�r�b�g����Ԃ�
       */
      inline const std::tuple<int, int, int> GetWidnowData() {
        return std::make_tuple(_width, _height, _colorBit);
      }
      /**
       * @brief  �o�߃t���[���擾�p�̏������z�֐�
       * @return ���݌Ăяo����Ă��郂�[�h�̃t���[���J�E���g
       */
      virtual const int GetFrameCount() const = 0;
      /**
       * @brief  �E�B���h�E���̐ݒ�
       * @param  width  �𑜓x
       * @param  height �𑜓x
       * @param  bit    �J���[�r�b�g����ύX���邩�̃t���O
       *                true:32�r�b�g�J���[(�f�t�H���g)  false:16�r�b�g�J���[
       */
      static void SetWindowSize(int width, int height, bool bit = true);
    protected:
      State _state{State::Paused};    //!< �A�v���P�[�V�����̏��
      static inline int _particleMax{0}; //!< �g�p����p�[�e�B�N�����
      static inline int _width{0};    //!< �E�B���h�E�T�C�Y(��)
      static inline int _height{0};   //!< �E�B���h�E�T�C�Y(����)
      static inline int _colorBit{0}; //!< �J���[�r�b�g��
      static inline bool _setInstance{false};   //!< �����t���O
      static inline bool _windowMode{false};    //!< �E�B���h�E���[�h
      //!< �A�v���P�[�V�����̎���
      static inline std::shared_ptr<ApplicationBase> _instance{nullptr};
      //!< �t�@�C���T�[�o
      std::unique_ptr<FileServer::FileServer> _fileServer{nullptr};
      //!< �C���v�b�g�I�y���[�V����
      std::unique_ptr<InputOperation> _input{nullptr};
      //!< ���[�h�T�[�o
      //std::unique_ptr<Mode::ModeServer> _modeServer{nullptr};
      /**
       * @brief  ���͏���
       * @return true:�������� false:�������s
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
       * @brief  Instance�̐������s�����̔���
       * @return true:�����Ɉڍs false:���Ɏ��̂���`����Ă���
       */
      static bool SetInstance();
      /**
       * @brief  �A�v���P�[�V�������I�����邩�̔���
       * @return 
       */
      void IsQuit();
    };
  } // namespace Application
} // namespace AppFrame