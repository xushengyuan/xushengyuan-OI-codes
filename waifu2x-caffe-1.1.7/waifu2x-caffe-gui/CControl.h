#pragma once

#include <windows.h>
#include <unordered_map>
#include "GUICommon.h"


// ����
// �C�x���g�n���h����SetWindowLong��GWL_USERDATA�������������ꍇ���������Ȃ�
class CControl
{
private:
	// �R�s�[�A����̋֎~
	CControl(const CControl&);
	CControl& operator =(const CControl&);

protected:
	struct stEvent
	{
		CustomEventFunc pfunc;
		LPVOID lpData;

		stEvent() : pfunc(nullptr), lpData(nullptr)
		{
		}

		stEvent(const CustomEventFunc &func, const LPVOID Data) : pfunc(func), lpData(Data)
		{
		}

		stEvent(const stEvent &st)
		{
			pfunc = st.pfunc;
			lpData = st.lpData;
		}
	};

	std::unordered_map<UINT, stEvent> mEventMap;

	HWND hSub;
	WNDPROC OrgSubWnd;
	int ResourceID;

	// �_�C�A���O�v���V�[�W��(����)
	virtual LRESULT SubProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	// �R���X�g���N�^(���\�[�XID���w��)
	CControl(const UINT ID);
	CControl();

	// ���z�f�X�g���N�^(�������Ȃ�)
	virtual ~CControl();

	// ��̃��b�Z�[�W�ɂ���̊֐������o�^�ł��Ȃ�.
	// ���łɂ������ꍇ�͏㏑�������.
	// lpData�͓o�^�����֐��ɗ^����D���Ȉ���.
	// �o�^�ł���֐��́A
	// BOOL Create(HWND hWnd, WPARAM wParam, LPARAM lParam, LPVOID lpData);
	// �̂悤�Ȋ֐�.
	// �߂�l��TRUE�ł�FALSE�ł��悢.
	void SetEventCallBack(const CustomEventFunc &func, const LPVOID lpData, const UINT uMsg);

	// �J�X�^���R���g���[����o�^
	BOOL Register(LPCTSTR ClassName, const HINSTANCE hInstance);

	// ���[�U�[���g���̂͂����܂�


	void RegisterFunc(HWND hWnd);

	int GetResourceID();

	// �_�C�A���O�v���V�[�W��(�`����)
	static LRESULT CALLBACK DispatchSubProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	// �J�X�^���R���g���[���v���V�[�W��
	static LRESULT CALLBACK DispatchCustomProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
