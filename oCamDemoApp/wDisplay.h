///////////////////////////////////////////////////////////////////////////////////////
//
// wDisplay.h : header file
//
// 20070910 
//	Display���� �ٷ� ȭ�鿡 ����ϵ��� �����Ͽ���. (�������� OnPaint���� ����ϵ��� �Ͽ���. )
//
// ������ ������ ����. 
// SetTitle(CString str) or (char *) 
//		: Ÿ��Ʋ���� ������ �ٲ۴�
// void EnableRect(int Num, COLORREF Color = RGB(255,0,0))
//		: Num��° Rect �Է��� �޾Ƶ��δ�. 
// void GetRect(int Num, CRect *Rect);
//		: �簢���� �����´�. 
// void SetID(int ID)
//		: ID�� �����Ѵ�. ������ �޼����� �ö� � ������������ Ȯ���ϱ� ���Ͽ� ��� 
// void SetWinHandle(HWND hWnd)
//		: ������ �ڵ��� ������ ������ LMOUSEBUTTON_DOWN, MOVE, UP �޼����� ������. 
// Ȯ�� ��Ұ� �����ϵ��� ...
// �簢���� wDisplay���� �׸��� ������ �޼����� �˷��ش�. 
// ���� ��ġ�� ����ߴٰ� ������ ��¿� ���� ��ġ�� ��µȴ�. 
//
// 20100715
//	���ȭ���� �ִ� ����� ũ����� �ۿ� Ŀ���� �ʴ´�. 
//	�׷��� ����ͺ��� ū ��� ȭ���� ��� ȭ���� ũ���Ϸ��� �ϴ� �ٶ��� 
//	�������� �߻��Ѵ�. �̹����� ������. 
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WDISPLAY_H__5A853788_798B_4259_9073_179A9F572FD4__INCLUDED_)
#define AFX_WDISPLAY_H__5A853788_798B_4259_9073_179A9F572FD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "wImage.h"

class wDisplay : public CWnd
{
// Construction
public:
	wDisplay();

// Attributes
public:
	static int		Count;
	CDC				m_MemDC;
	LPBITMAPINFO	m_pBmpInfo;
	int				m_Width, m_Height;

// Operations
public:
	void Display(wImage& Img);
	void DrawRect(RECT Rect, COLORREF Color, int Num=-1);

	void SavePos(CWinApp* pApp, LPCTSTR Section="Display");
	void LoadPos(CWinApp* pApp, LPCTSTR Section="Display");
	void SavePos(char *File, LPCTSTR Section="Display");
	void LoadPos(char *File, LPCTSTR Section="Display");
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(wDisplay)
	public:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~wDisplay();

	// Generated message map functions
protected:
	//{{AFX_MSG(wDisplay)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WDISPLAY_H__5A853788_798B_4259_9073_179A9F572FD4__INCLUDED_)
