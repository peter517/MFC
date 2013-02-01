// InfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "InfoDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg dialog


CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInfoDlg::IDD, pParent)
{

	//{{AFX_DATA_INIT(CInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

BOOL CInfoDlg::OnInitDialog()/*��ÿ��ѡ������͸�ֵ*/
{
  CDialog::OnInitDialog();

  m_tab.InsertItem(0,"��Ϸ����",0);
  m_tab.InsertItem(1,"�����Ϣ",1);

  return TRUE; 
}

void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfoDlg)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CInfoDlg)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg message handlers

void CInfoDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
 int nTab=m_tab.GetCurSel();/*��ȡ��ҶԶԻ����ѡ����ֵ��*/
 if(nTab==0)
 {
   GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);/*��ʾ��һ����̬�ı�*/
   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
 }
 else
 {
    GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);/*��ʾ�ڶ�����̬�ı�*/
    GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
 }
	*pResult = 0;
}
