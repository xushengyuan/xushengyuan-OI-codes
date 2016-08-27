#define _CRT_SECURE_NO_WARNINGS
#include "MainDialog.h"
#include <glog/logging.h>
#include "CDialog.h"
#include "CControl.h"
#include "../common/waifu2x.h"

#pragma comment(lib, "winmm.lib")


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	Waifu2x::init_liblary(__argc, __argv);

	// �Ǘ��Ҍ����ŋN�����Ă��t�@�C���̃h���b�v���󂯕t����悤�ɂ���
	ChangeWindowMessageFilter(WM_DROPFILES, MSGFLT_ADD);
	ChangeWindowMessageFilter(WM_COPYDATA, MSGFLT_ADD);
	ChangeWindowMessageFilter(0x0049, MSGFLT_ADD);

	// Caffe�̃G���[�łȂ����O��ۑ����Ȃ��悤�ɂ���
	google::SetLogDestination(google::INFO, "");
	google::SetLogDestination(google::WARNING, "");

	// Caffe�̃G���[���O���uerror_log_�`�v�ɏo��
	google::SetLogDestination(google::ERROR, "error_log_");
	google::SetLogDestination(google::FATAL, "error_log_");

	// CDialog�N���X�Ń_�C�A���O���쐬����
	CDialog cDialog;
	CDialog cDialog2;
	// IDC_EDIT�̃T�u�N���X
	CControl cControlInput(IDC_EDIT_INPUT);
	CControl cControlOutput(IDC_EDIT_OUTPUT);
	CControl cControlScaleRatio(IDC_EDIT_SCALE_RATIO);
	CControl cControlScaleWidth(IDC_EDIT_SCALE_WIDTH);
	CControl cControlScaleHeight(IDC_EDIT_SCALE_HEIGHT);

	// �o�^����֐����܂Ƃ߂�ꂽ�N���X
	// �O���[�o���֐����g���΃N���X�ɂ܂Ƃ߂�K�v�͂Ȃ������̕��@���𗧂��Ƃ�����͂�
	DialogEvent cDialogEvent;

	// �N���X�̊֐���o�^����ꍇ

	// IDC_EDIT��WM_DROPFILES�������Ă����Ƃ��Ɏ��s����֐��̓o�^
	cControlInput.SetEventCallBack(SetClassCustomFunc(DialogEvent::DropInput, &cDialogEvent), NULL, WM_DROPFILES);
	cControlOutput.SetEventCallBack(SetClassCustomFunc(DialogEvent::DropOutput, &cDialogEvent), NULL, WM_DROPFILES);

	cControlScaleRatio.SetEventCallBack(SetClassCustomFunc(DialogEvent::TextInput, &cDialogEvent), NULL, WM_CHAR);
	cControlScaleWidth.SetEventCallBack(SetClassCustomFunc(DialogEvent::TextInput, &cDialogEvent), NULL, WM_CHAR);
	cControlScaleHeight.SetEventCallBack(SetClassCustomFunc(DialogEvent::TextInput, &cDialogEvent), NULL, WM_CHAR);

	// �R���g���[���̃T�u�N���X��o�^
	cDialog.AddControl(&cControlInput);
	cDialog.AddControl(&cControlOutput);
	cDialog.AddControl(&cControlScaleRatio);
	cDialog.AddControl(&cControlScaleWidth);
	cDialog.AddControl(&cControlScaleHeight);

	// �e�R���g���[���̃C�x���g�Ŏ��s����֐��̓o�^
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::Exec, &cDialogEvent), NULL, IDC_BUTTON_EXEC);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::Cancel, &cDialogEvent), NULL, IDC_BUTTON_CANCEL);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::InputRef, &cDialogEvent), NULL, IDC_BUTTON_INPUT_REF);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::OutputRef, &cDialogEvent), NULL, IDC_BUTTON_OUTPUT_REF);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::ClearOutputDir, &cDialogEvent), NULL, IDC_BUTTON_CLEAR_OUTPUT_DIR);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::AppSetting, &cDialogEvent), NULL, IDC_BUTTON_APP_SETTING);

	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::OnModeChange, &cDialogEvent), NULL, IDC_RADIO_MODE_NOISE);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::OnModeChange, &cDialogEvent), NULL, IDC_RADIO_MODE_SCALE);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::OnModeChange, &cDialogEvent), NULL, IDC_RADIO_MODE_NOISE_SCALE);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::OnModeChange, &cDialogEvent), NULL, IDC_RADIO_AUTO_SCALE);

	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::UpdateAddString, &cDialogEvent), NULL, IDC_RADIONOISE_LEVEL0);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::UpdateAddString, &cDialogEvent), NULL, IDC_RADIONOISE_LEVEL1);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::UpdateAddString, &cDialogEvent), NULL, IDC_RADIONOISE_LEVEL2);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::UpdateAddString, &cDialogEvent), NULL, IDC_RADIONOISE_LEVEL3);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::UpdateAddString, &cDialogEvent), NULL, IDC_COMBO_MODEL);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::UpdateAddString, &cDialogEvent), NULL, IDC_CHECK_TTA);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::UpdateAddString, &cDialogEvent), NULL, IDC_COMBO_OUTPUT_DEPTH);

	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::ScaleRadio, &cDialogEvent), NULL, IDC_RADIO_SCALE_RATIO);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::ScaleRadio, &cDialogEvent), NULL, IDC_RADIO_SCALE_WIDTH);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::ScaleRadio, &cDialogEvent), NULL, IDC_RADIO_SCALE_HEIGHT);

	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::CheckCUDNN, &cDialogEvent), NULL, IDC_BUTTON_CHECK_CUDNN);

	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::LangChange, &cDialogEvent), NULL, IDC_COMBO_LANG);
	cDialog.SetCommandCallBack(SetClassFunc(DialogEvent::OutExtChange, &cDialogEvent), NULL, IDC_COMBO_OUT_EXT);

	// �_�C�A���O�̃C�x���g�Ŏ��s����֐��̓o�^
	cDialog.SetEventCallBack(SetClassFunc(DialogEvent::Create, &cDialogEvent), NULL, WM_INITDIALOG);
	cDialog.SetEventCallBack(SetClassFunc(DialogEvent::OnDialogEnd, &cDialogEvent), NULL, WM_CLOSE);
	cDialog.SetEventCallBack(SetClassFunc(DialogEvent::OnFaildCreateDir, &cDialogEvent), NULL, WM_FAILD_CREATE_DIR);
	cDialog.SetEventCallBack(SetClassFunc(DialogEvent::OnWaifu2xError, &cDialogEvent), NULL, WM_ON_WAIFU2X_ERROR);
	cDialog.SetEventCallBack(SetClassFunc(DialogEvent::OnWaifu2xNoOverwrite, &cDialogEvent), NULL, WM_ON_WAIFU2X_NO_OVERWRITE);
	cDialog.SetEventCallBack(SetClassFunc(DialogEvent::WaitThreadExit, &cDialogEvent), NULL, WM_END_THREAD);
	cDialog.SetEventCallBack(SetClassFunc(DialogEvent::Timer, &cDialogEvent), NULL, WM_TIMER);

	// �_�C�A���O��\��
	cDialog.DoModal(hInstance, IDD_DIALOG);

	Waifu2x::quit_liblary();

	return 0;
}
