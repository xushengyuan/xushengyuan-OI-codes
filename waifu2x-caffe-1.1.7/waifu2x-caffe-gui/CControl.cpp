#include <windows.h>
#include "CControl.h"


CControl::CControl(const UINT ID)
{
	ResourceID = ID;
}

CControl::CControl()
{
}

CControl::~CControl()
{
}

void CControl::RegisterFunc(HWND hWnd)
{
	hSub = GetDlgItem(hWnd, ResourceID);

	if(hSub == NULL)
		return;

	SetWindowLongPtr(hSub, GWLP_USERDATA, (LONG_PTR)this);

	OrgSubWnd = (WNDPROC)GetWindowLongPtr(hSub, GWLP_WNDPROC);
	SetWindowLongPtr(hSub, GWLP_WNDPROC, (LONG_PTR)DispatchSubProc);
}

int CControl::GetResourceID()
{
	return ResourceID;
}

void CControl::SetEventCallBack(const CustomEventFunc &func, const LPVOID lpData, const UINT uMsg)
{
	mEventMap[uMsg] = stEvent(func, lpData);
}

BOOL CControl::Register(LPCTSTR ClassName, const HINSTANCE hInstance)
{
	WNDCLASS winc;

	winc.style			= CS_HREDRAW | CS_VREDRAW;
	winc.cbClsExtra		= winc.cbWndExtra	= 0;
	winc.hInstance		= hInstance;
	winc.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName	= NULL;
	winc.lpfnWndProc 	= DispatchCustomProc;
	winc.hIcon			= NULL;
	winc.lpszClassName	= ClassName;

	return RegisterClass(&winc);
}

LRESULT CControl::SubProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	auto it = mEventMap.find(uMsg);
	if(it != mEventMap.end())
		return it->second.pfunc(hWnd, wParam, lParam, OrgSubWnd, it->second.lpData);
	else
		//�����ŏ������Ȃ����̂͌��̃v���V�[�W���ɂ���Ă��炤
		return CallWindowProc(OrgSubWnd, hWnd, uMsg, wParam, lParam);
}

// �_�C�A���O�v���V�[�W��(�`����) 
LRESULT CALLBACK CControl::DispatchSubProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// �_�C�A���O�� 32 �r�b�g�����Ɋi�[����Ă���  
	// this �|�C���^����肾��
	CControl *pcControl = (CControl *)GetWindowLongPtr(hWnd, GWLP_USERDATA); 
	if(pcControl == NULL)
	{
		// ���Ԃ񂱂������s����邱�Ƃ͂Ȃ�
		return NULL;
	}

	// �����o�֐��̃_�C�A���O�v���V�[�W�����Ăяo��
	return pcControl->SubProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK CControl::DispatchCustomProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
