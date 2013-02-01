// TwoComputerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TwoComputer.h"
#include "TwoComputerDlg.h"
#include "time.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

//����һЩȫ�ֱ������������̵߳����ݽ���

CString str1,str2; //�����Գ�ȭ��ֵ
int num1,num2; //�������������

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTwoComputerDlg dialog

CTwoComputerDlg::CTwoComputerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTwoComputerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTwoComputerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTwoComputerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTwoComputerDlg)
	DDX_Control(pDX, IDC_LIST2, m_Computer_B);
	DDX_Control(pDX, IDC_LIST1, m_Computer_A);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTwoComputerDlg, CDialog)
	//{{AFX_MSG_MAP(CTwoComputerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTwoComputerDlg message handlers

BOOL CTwoComputerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	AfxBeginThread(ComputerAProc,  //���ƺ�����ַ
		           &m_Computer_A,  //���б�ؼ���
				   0,
				   0,
				   0,       //���������߳�
				   NULL);   //�����߳�
    
	AfxBeginThread(ComputerBProc,
	            	&m_Computer_B,
		            0,
		            0,
		            0,
				   NULL);



	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTwoComputerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTwoComputerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTwoComputerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


UINT ComputerAProc(LPVOID pParam)
{
  CListBox * a = (CListBox *)pParam;//��ȡ�б�ؼ�ָ��

  if (a==NULL||!a->IsKindOf(RUNTIME_CLASS(CListBox)))
     return -1;

  srand(time(NULL));
  
  CTwoComputerDlg * p = NULL;//��ʼ��һ���Ի������

  for ( int i=0;i<10;i++)
  {
        str1 = p->Create_SSC((rand()%3+1));//������ȭֵ

	    a->AddString(str1);//������ؼ���

		Sleep(2000); 

	  	int Result = p->Judge(str1,str2); //�Բ�ȭ��������ж�
	  
		if (Result==1)
		{
		  a->AddString("��Ӯ��!");
		  Sleep(1000);

          num1 = rand()%1000+1;
		  num2 = rand()*rand()%1000;
		  str1.Format("%d + %d = ?",num1,num2);//��һ��������

		  a->AddString(str1);
		  Sleep(1000);
		}

		else if(Result==0)
        a->AddString("ƽ��");

		else
		{
        a->AddString("������!");
		Sleep(2000);
		str1.Format("%d",num1+num2);
		a->AddString(str1);
		}
 
	    Sleep(2000);
	  
  }	 

     return 0;  
}

UINT ComputerBProc(LPVOID pParam)
{
	CListBox * b = (CListBox *)pParam;
	if (b==NULL||!b->IsKindOf(RUNTIME_CLASS(CListBox)))
		return -1;
	

  srand(time(NULL)*time(NULL));

  CTwoComputerDlg * p = NULL;
  for ( int i=0;i<10;i++)
  {
        str2 = p->Create_SSC((rand()%3+1));

	    b->AddString(str2);

		Sleep(2000);

	  	int Result = p->Judge(str1,str2);
	  
		if (Result==-1)
		{
			b->AddString("��Ӯ��!");
			Sleep(1000);
			num1 = rand()%1000+1;
			num2 = rand()*rand()%1000;
			str2.Format("%d + %d = ?",num1,num2);
			b->AddString(str2);
			Sleep(1000);
		}

		else if(Result==0)
        b->AddString("ƽ��");

		else
        {
			b->AddString("������!");
			Sleep(2000);
			str2.Format("%d",num1+num2);
            b->AddString(str2);
		}
	  
		Sleep(2000);
	  
  }	 
      return 0; 	
}

CString CTwoComputerDlg::Create_SSC(int random)
{
	CString str;
	
	switch(random)
	{
    case 1:
		str="ʯͷ";
		break;
	case 2:
        str="����";
		break;
	case 3:
		str="��";
		break;
	default:
		break;
	}
	return str;
}

int CTwoComputerDlg::Judge(CString str1, CString str2)
{
	
	if (str1==str2)
	{
		return 0;
	}

	else if ((str1=="ʯͷ"&&str2=="����")||(str1=="��"&&str2=="ʯͷ")||(str1=="����"&&str2=="��"))
	{
		return 1;
	}

	else
    return -1;
}
