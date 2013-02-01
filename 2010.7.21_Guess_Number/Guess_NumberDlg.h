// Guess_NumberDlg.h : header file
//

#if !defined(AFX_GUESS_NUMBERDLG_H__C309904B_C915_4E9C_88B2_A5EAD462DB39__INCLUDED_)
#define AFX_GUESS_NUMBERDLG_H__C309904B_C915_4E9C_88B2_A5EAD462DB39__INCLUDED_

	// Added by ClassView
#include "Start.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGuess_NumberDlg dialog

#include "windows.h"

#include "BKListBox.h"
#include "InfoDlg.h"                    /*��Щͷ�ļ��Ǳ�������ģ�һ��Botton��Ӧһ����һ��ͷ�ļ�*/
#include "SetDlg.h"	

class CGuess_NumberDlg : public CDialog
{
// Construction
public:
	//CStart * m_InputDlg;
	CSetDlg * m_Set;/*ָ����Ϸ���öԻ���*/
	CInfoDlg * m_Info;/*ָ����Ϸ���ܶԻ���*/
	CStart * m_start;/*ָ����Ϸ��ʼ�Ի���*/
	CGuess_NumberDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGuess_NumberDlg)
	enum { IDD = IDD_GUESS_NUMBER_DIALOG };
	CBKListBox	m_list;/*���ñ����ģ�û�ɹ�*/
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGuess_NumberDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);/*����Ի���ʱҪ���е����ݽ���*/	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGuess_NumberDlg)
	virtual BOOL OnInitDialog();/*�Ի����ʼ��*/
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);/*������Ͻǹرհ�ťʱ�Ŀ��ƺ���*/
	afx_msg void OnPaint();/*�����ã����öԻ������*/
	afx_msg HCURSOR OnQueryDragIcon();/*�ǵ�����϶���CWnd�Ĵ����ϵ�ʱ��ϵͳ�Զ��������������ȷ����ʾʲô�����϶�ͼ��*/
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUESS_NUMBERDLG_H__C309904B_C915_4E9C_88B2_A5EAD462DB39__INCLUDED_)
