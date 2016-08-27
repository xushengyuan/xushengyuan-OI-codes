#pragma once

#include <windows.h>


class CDialogBase
{
private:
	// �_�C�A���O�v���V�[�W��(����) 
	virtual INT_PTR DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

protected:
	HWND hDialog;

public:
	virtual ~CDialogBase(){};

	// �_�C�A���O���쐬���� 
	INT_PTR DoModal(HINSTANCE hInstance, int iDialogId, HWND hWndParent = NULL);

	HWND GetDialogHWND(void);

	// �_�C�A���O�v���V�[�W��(�`����)
	static INT_PTR CALLBACK DispatchDialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
