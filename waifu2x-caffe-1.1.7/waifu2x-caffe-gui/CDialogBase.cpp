#include <windows.h>
#include "CDialogBase.h"


// �_�C�A���O���쐬����
INT_PTR CDialogBase::DoModal(HINSTANCE hInstance, int iDialogId, HWND hWndParent)
{ 
	return DialogBoxParam(hInstance, MAKEINTRESOURCE(iDialogId), hWndParent, &DispatchDialogProc, (LPARAM)this);
}

HWND CDialogBase::GetDialogHWND(void)
{
	return hDialog;
}

// �_�C�A���O�v���V�[�W��(�`����) 
INT_PTR CALLBACK CDialogBase::DispatchDialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// �_�C�A���O�� 32 �r�b�g�����Ɋi�[����Ă���  
	// this �|�C���^����肾��
	CDialogBase *pcDialog = (CDialogBase *)GetWindowLongPtr(hWnd, GWLP_USERDATA); 
	if(pcDialog == NULL) 
	{
		if(uMsg == WM_INITDIALOG || uMsg == WM_CREATE) 
		{ 
			// ���O�� DialogBoxParam() ���Ă΂�Ă�ꍇ
			// this �|�C���^���_�C�A���O�̃��[�U�[�̈�ɓ����
			pcDialog = (CDialogBase*)lParam;

			SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pcDialog);
			pcDialog->hDialog = hWnd;

			return pcDialog->DialogProc(hWnd, uMsg, wParam, lParam);
		}

		return FALSE; 
	}

	// �����o�֐��̃_�C�A���O�v���V�[�W�����Ăяo�� 
	return pcDialog->DialogProc(hWnd, uMsg, wParam, lParam);
} 
