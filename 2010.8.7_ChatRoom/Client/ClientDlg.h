// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__A740689D_4382_4A1D_9FDD_8DB94CF9B9EB__INCLUDED_)
#define AFX_CLIENTDLG_H__A740689D_4382_4A1D_9FDD_8DB94CF9B9EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog
#define WM_CLIENTMSG (WM_USER+200)//�Զ������Ϣ +200

class CClientDlg : public CDialog
{
// Construction
public:
	CClientDlg(CWnd* pParent = NULL);	// standard constructor
	sockaddr_in m_addr;// ��ַ�ṹָ�� IP �˿� ʲô��
	SOCKET m_hSocket; // �׽��� send listen accept recv ��Ҫ�õĲ���
   
// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CEdit	m_Show;
	CString	m_strShow;
	CString	m_strMsg;
	UINT m_uPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();// ���±�д���ڹر�ʱ�ĺ���
	afx_msg void OnButton1();
	afx_msg void OnButton2();
    afx_msg long OnClientMsg(WPARAM wParam,LPARAM lParam); //�Զ�����Ϣ�ĺ���ӳ����
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__A740689D_4382_4A1D_9FDD_8DB94CF9B9EB__INCLUDED_)
