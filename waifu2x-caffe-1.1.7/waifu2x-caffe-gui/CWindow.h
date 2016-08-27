#pragma once

#include <windows.h>
#include <vector>
#include <unordered_map>
#include "CWindowBase.h"
#include "GUICommon.h"


// ����
// �C�x���g�n���h����SetWindowLong��GWL_USERDATA�������������ꍇ���������Ȃ�
class CWindow: public CWindowBase
{
private:
	struct stEvent
	{
		EventFunc pfunc;
		LPVOID lpData;

		stEvent() : pfunc(nullptr), lpData(nullptr)
		{
		}

		stEvent(const EventFunc &func, const LPVOID Data) : pfunc(func), lpData(Data)
		{
		}

		stEvent(const stEvent &st)
		{
			pfunc = st.pfunc;
			lpData = st.lpData;
		}
	};
	std::unordered_map<UINT, stEvent> mEvent;

	// �R�s�[�A����̋֎~
	CWindow(const CWindow&);
	CWindow& operator =(const CWindow&);

	// �_�C�A���O�v���V�[�W���i�����j
	LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	// ��̃��b�Z�[�W�ɂ���̊֐������o�^�ł��Ȃ�.
	// ���łɂ������ꍇ�͏㏑�������.
	// lpData�͓o�^�����֐��ɗ^����D���Ȉ���.
	// �o�^�ł���֐��́A
	// BOOL Create(HWND hWnd, WPARAM wParam, LPARAM lParam, LPVOID lpData);
	// �̂悤�Ȋ֐�.
	// �߂�l��TRUE�ł�FALSE�ł��悢.
	void SetEventCallBack(EventFunc pfunc, LPVOID lpData, UINT uMsg);

	// �E�B���h�E�T�C�Y�ύX
	void SetWindowSize(int nWidth, int nHeight, BOOL Adjust);

	// �E�B���h�E����ʒ��S�ֈړ�
	void MoveWindowCenter();

	// �R���X�g���N�^(�������Ȃ�)
	CWindow();
};
