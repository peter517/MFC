// TwoComputerDlg.h : header file
//

#if !defined(AFX_TWOCOMPUTERDLG_H__C60D635A_872C_4F80_833D_73E0CEFA769B__INCLUDED_)
#define AFX_TWOCOMPUTERDLG_H__C60D635A_872C_4F80_833D_73E0CEFA769B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTwoComputerDlg dialog
UINT ComputerAProc(LPVOID pParam); //�������ƺ�������
UINT ComputerBProc(LPVOID pParam);

#include "afxmt.h"//����߳�ͬ��֧���ļ�������û����

class CTwoComputerDlg : public CDialog
{
// Construction
public:
	int Judge(CString str1,CString str2); //�жϲ�ȭ���
	CString Create_SSC(int random);// ���������ȭ��
	CCriticalSection section; //��ʼ���ٽ�����������û����
	CTwoComputerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTwoComputerDlg)
	enum { IDD = IDD_TWOCOMPUTER_DIALOG };
	CListBox	m_Computer_B;
	CListBox	m_Computer_A;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTwoComputerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTwoComputerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TWOCOMPUTERDLG_H__C60D635A_872C_4F80_833D_73E0CEFA769B__INCLUDED_)
