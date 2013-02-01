#if !defined(AFX_START_H__7E3AEA50_BBD3_4C41_A77B_042EA2E1A907__INCLUDED_)
#define AFX_START_H__7E3AEA50_BBD3_4C41_A77B_042EA2E1A907__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Start.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStart dialog

#include "Guess_Number.h"
#include "time.h"
#include "MyEdit.h"
//#include "SetDlg.h"
#define MAX 100

class CStart : public CDialog
{
// Construction
public:
	CStart(CWnd* pParent = NULL);   // standard constructor

	void Play();/*��Ϸ��ʼ*/
    CString   Judge(int Guess_Num);/*���������ֽ����ж�*/

    int m_Max;  /*Ҫ�µ���������*/
    int Target; /*Ŀ������*/
    int m_Min; /*Ҫ�µ���������*/
	int Person; /*�˲µ���*/
	int Computer; /*���Բµ���*/
// Dialog Data
	//{{AFX_DATA(CStart)
	enum { IDD = IDD_DIALOG1 }; /*ö��*/
	CMyEdit	m_ctrlEdit; /*������������������ֵĸ�ʽ��λ���ȵȣ���CMyEdit��������� Onchar ʲô��*/
	int		m_Person_Guess; /*�����������������*/
	CString	m_Info; /*�ڶԻ����²���ʾ��Ϸ��չ*/
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStart)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog(); 
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStart)
	afx_msg void OnButton1(); /*ȷ������*/
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor); /*�������Ի��������ɫ����*/
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/*void CStart::Set_Max()
{
  int Max;
  cout<<"�����뱻����ֵ������: ";
  cin>>Max;
  m_Max = Max;
}*/


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_START_H__7E3AEA50_BBD3_4C41_A77B_042EA2E1A907__INCLUDED_)
