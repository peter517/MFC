// SetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SetDlg.h"
#include "Guess_Number.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetDlg dialog


CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDlg::IDD, pParent)
{
	//m_hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//{{AFX_DATA_INIT(CSetDlg)
	m_IconStyle = 1; /*Ĭ��ѡ�ڶ�����ѡ��*/
	m_Set_To_Start_Min = Set_To_Start_Min; /*��ȡ�м�ֵ(ȫ�ֱ���) stdAfx.cpp���涨�壬stdAfx.h��������*/
	m_Set_To_Start_Max = Set_To_Start_Max; /*��ȡ�м�ֵ(ȫ�ֱ���)*/
	//}}AFX_DATA_INIT
}

BOOL CSetDlg::OnInitDialog()
{
  CDialog::OnInitDialog();

 m_SetMax.SetRange(1,1000);
 m_SetMax.SetPos(100);
 m_SetMin.SetRange(1,1000);
 m_SetMin.SetPos(1);

  return TRUE; 
}

void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetDlg)
	DDX_Control(pDX, IDC_SPIN2, m_SetMax);
	DDX_Control(pDX, IDC_SPIN1, m_SetMin);
	DDX_Radio(pDX, IDC_RADIO1, m_IconStyle);
	DDX_Text(pDX, IDC_EDIT1, m_Set_To_Start_Min);
	DDX_Text(pDX, IDC_EDIT2, m_Set_To_Start_Max);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialog)
	//{{AFX_MSG_MAP(CSetDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetDlg message handlers

void CSetDlg::OnButton1() 
{
    UpdateData(TRUE);  // ��ȡ�û�����
	
	if (m_IconStyle == 0)  
		; 
	else if (m_IconStyle == 1)
		;
	else 
		;
    if(m_Set_To_Start_Max>m_Set_To_Start_Min)
	{
    Set_To_Start_Max=m_Set_To_Start_Max;
	Set_To_Start_Min=m_Set_To_Start_Min;
    
	CDialog::OnOK(); /*�رնԻ���*/
	}
	else
	{
    MessageBox("�������Ҫ�µ����ֵ����ޱ�����Ҫ������������!","��ʾ",MB_ICONWARNING|MB_OK);
	}
}
