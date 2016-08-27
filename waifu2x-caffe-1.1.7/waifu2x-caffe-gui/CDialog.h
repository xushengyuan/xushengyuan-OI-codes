#pragma once

#include <windows.h>
#include <vector>
#include <unordered_map>
#include "CDialogBase.h"
#include "GUICommon.h"

class CControl;


// ����
// �C�x���g�n���h����SetWindowLong��GWL_USERDATA�������������ꍇ���������Ȃ�
class CDialog: public CDialogBase
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

	struct stCommand
	{
		EventFunc pfunc;
		LPVOID lpData;

		stCommand() : pfunc(nullptr), lpData(nullptr)
		{
		}

		stCommand(const EventFunc &func, const LPVOID Data) : pfunc(func), lpData(Data)
		{
		}

		stCommand(const stCommand &st)
		{
			pfunc = st.pfunc;
			lpData = st.lpData;
		}
	};

	std::vector<CControl*> vControl;
	std::unordered_map<UINT, stEvent> mEventMap;
	std::unordered_map<UINT, stCommand> mCommandMap;

	EventFunc mInitFunc;
	LPVOID mInitData;

	// �R�s�[�A����̋֎~
	CDialog(const CDialog&);
	CDialog& operator =(const CDialog&);

	// �_�C�A���O�v���V�[�W��
	INT_PTR DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void CommandCallBack(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void SetControl(HWND hWnd);

public:
	// ��̃��b�Z�[�W�ɂ���̊֐������o�^�ł��Ȃ�.
	// ���łɂ������ꍇ�͏㏑�������.
	// WM_COMMAND��o�^�����ꍇ�ASetCommandCallBack�͎g���Ȃ��Ȃ�.
	// lpData�͓o�^�����֐��ɗ^����D���Ȉ���.
	// �o�^�ł���֐��́A
	// BOOL Create(HWND hWnd, WPARAM wParam, LPARAM lParam, LPVOID lpData);
	// �̂悤�Ȋ֐�.
	// �_�C�A���O�ł�TRUE��Ԃ�����.
	void SetEventCallBack(const EventFunc &func, const LPVOID lpData, const UINT uMsg);

	// �{�^���������ꂽ�Ƃ��Ȃǂ̂���
	// lpData�͓o�^�����֐��ɗ^����D���Ȉ���
	void SetCommandCallBack(const EventFunc &func, const LPVOID lpData, const UINT ResourceID);

	// �{�^���Ȃǂ̃T�u�N���X������R���g���[����ǉ�����
	void AddControl(CControl *pfunc);

	// �R���X�g���N�^(�������Ȃ�)
	CDialog();
};
