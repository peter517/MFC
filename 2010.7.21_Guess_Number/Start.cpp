// Start.cpp : implementation file
//

#include "stdafx.h"
#include "Start.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStart dialog��

/*û�г�ʼ��������*/


CStart::CStart(CWnd* pParent /*=NULL*/)/*���캯������ʼ��*/
	: CDialog(CStart::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStart)
      
   	  m_Person_Guess = 0; 
	  m_Max = Set_To_Start_Max; /*���޸����������洫���Ĳ�����ʼ��*/
      m_Min = Set_To_Start_Min; /*ͬ��*/
	  Person = 0;
      Computer = 0;
	  m_Info = _T("");/*CString���͵ĳ�ʼ��*/
	//}}AFX_DATA_INIT

}

BOOL CStart::OnInitDialog()
{
     CDialog::OnInitDialog();

     srand(time(NULL));
     Target = rand()%m_Max + 1;/*�������һ��Ŀ����*/

     int Long_Num=1;
     int Buffer=Set_To_Start_Max;
     while(Buffer/10!=0)
	 {
      	Long_Num++; 
        Buffer=Buffer/10;
	 }

     m_ctrlEdit.SetLimitText(Long_Num);/*��������������ֵ�λ��*/

	 CString str1,str;

	 str.Format("������Ҫ�µ����ַ�Χ:%d--%d",m_Min,m_Max);
	 
	/* MessageBox(str,"��ʾ",MB_ICONASTERISK|MB_OK|MB_RIGHT);*/

	 m_Info = str;/*�Ի����·���ʾstr����Ϣ*/
	 UpdateData(FALSE);

     return TRUE;
}

void CStart::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStart)
	DDX_Control(pDX, IDC_EDIT1, m_ctrlEdit);
	DDX_Text(pDX, IDC_EDIT1, m_Person_Guess);
	DDX_Text(pDX, IDC_STATIC1, m_Info);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStart, CDialog)
	//{{AFX_MSG_MAP(CStart)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStart message handlers
CString  CStart::Judge(int Guess_Num)
{

 CString str1,str;

 if(Person==Target||Computer==Target)
 {

   if(Computer==Target)
   {

    MessageBox("�����������֣�����ʤ��!","��ʾ",MB_ICONWARNING|MB_OK);
    str.Format("�����������֣�����ʤ��!");

   }

   else
    MessageBox("�����������֣����Ի�ʤ!","��ʾ",MB_ICONWARNING|MB_OK);

    str.Format("�����������֣����Ի�ʤ!");
  //if(MessageBox("�Ƿ����Ҫ����?","��ʾ",MB_ICONASTERISK|MB_YESNO)==IDYES)
  //CStart::OnButton1();
  //else
	CDialog::OnOK(); 

    return str;
 }

 else if(Guess_Num>Target) 
 {
	 m_Max = Guess_Num;/*�ı�������ֵ������*/

     str.Format(" Ҫ�µ����ַ�Χ:%d--%d",m_Min,m_Max);

     MessageBox(str,"��ʾ",MB_ICONASTERISK|MB_OK|MB_RIGHT);

	 return str;
 }

 else if(Guess_Num<Target)
 {
     m_Min = Guess_Num;/*�ı�������ֵ������*/

     str.Format(" Ҫ�µ����ַ�Χ:%d--%d",m_Min,m_Max);

	 MessageBox(str,"��ʾ",MB_ICONASTERISK|MB_OK|MB_RIGHT);

	 return str;
 }
     return str;
}

void CStart::OnButton1() 
{
	CString str;
     
	UpdateData(TRUE);/*��ȡ�༭���������*/
    Person = m_Person_Guess;

if((Person>=m_Max)||(Person<=m_Min))
    MessageBox("�밴��Ϸ��������!","��ʾ",MB_ICONWARNING|MB_OK|MB_RIGHT);  
else
{ 
	m_Info=Judge(Person);

    if(Person!=Target)
	{

    Computer = m_Min+rand()%(m_Max-m_Min-1)+1;/*�ӿ����ѡ��*/

	str.Format("���Բµ����� %d",Computer);
    MessageBox(str,"��ʾ",MB_ICONASTERISK|MB_OK);

	m_Info=Judge(Computer);

	UpdateData(FALSE);/*���¶Ի���������ı�����*/

	}
} 

}

HBRUSH CStart::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
    if(pWnd->GetDlgCtrlID()==IDC_STATIC1)/*��ID��ΪIDC_STATIC1���ı��������ɫ����*/
	   pDC->SetTextColor(RGB(255,0,0));
	
	return hbr;
}

