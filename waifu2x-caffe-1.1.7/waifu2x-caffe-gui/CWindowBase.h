#pragma once

#include <windows.h>


class CWindowBase
{
private:
	// �_�C�A���O�v���V�[�W��(����)
	virtual LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

protected:
	HWND hWindow;
	DWORD dwStyle;

public:
	// ���z�f�X�g���N�^(�������Ȃ�)
	virtual ~CWindowBase();

	// �_�C�A���O���쐬
	// Adjust: �^�Ȃ�T�C�Y���N���C�A���g�̈�̂��̂Ƃ���
	// bSizeBox: �^�Ȃ�T�C�Y�ύX�ł���悤�ɂ���
	HWND InitWindow(HINSTANCE hInstance, UINT Width, UINT Height,
		BOOL Adjust, BOOL bSizeBox, LPCTSTR szClassName, LPCTSTR szWindowTitle);

	HWND InitWindow(HINSTANCE hInstance, UINT Width, UINT Height,
		BOOL Adjust, LPCTSTR szClassName, LPCTSTR szWindowTitle,
		UINT WindowClassStyle = CS_HREDRAW | CS_VREDRAW, DWORD WindowStyle = WS_OVERLAPPEDWINDOW);

	// �E�B���h�E��\��
	void ShowWindow(int nCmdShow);

	// ���C���E�B���h�E�̃n���h�����擾
	HWND GetWindowHandle(void);

	// ���b�Z�[�W���[�v
	void MessageLoop();

	// �߂�l:	�I�� 0
	//			���b�Z�[�W������ 1
	//			���b�Z�[�W�͂Ȃ����� 2
	int PeekLoop();


	// �_�C�A���O�v���V�[�W��(�`����)
	static LRESULT CALLBACK DispatchWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
