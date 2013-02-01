// ServerDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__576A0A43_1087_4558_9DFB_214BE42C9969__INCLUDED_)
#define AFX_SERVERDLG_H__576A0A43_1087_4558_9DFB_214BE42C9969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h> //列表Clist的头文件

#define WM_SERVERMSG (WM_USER+100)

typedef CList<SOCKET,SOCKET&> SOCKET_ARRAY;//定义套接字列表类
/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

class CServerDlg : public CDialog
{
// Construction
public:
	CServerDlg(CWnd* pParent = NULL);	// standard constructor
    UINT m_uPort;
	sockaddr_in m_addr;
	SOCKET m_hSocket;

	SOCKET_ARRAY m_saList;//初始化套接字列表

// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
	CEdit	m_Show;
	CString	m_strShow;
	CString	m_strMsg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnButton1();
    afx_msg long OnServerMsg(WPARAM wParam,LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__576A0A43_1087_4558_9DFB_214BE42C9969__INCLUDED_)
