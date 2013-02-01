// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

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
// CServerDlg dialog

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerDlg)
	m_strShow = _T("");
	m_strMsg = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
	DDX_Control(pDX, IDC_EDIT1, m_Show);
	DDX_Text(pDX, IDC_EDIT1, m_strShow);
	DDX_Text(pDX, IDC_EDIT2, m_strMsg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_MESSAGE(WM_SERVERMSG,OnServerMsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
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

	WSADATA wsaData;

	WORD wVersionRequested = MAKEWORD(2,0);
	WSAStartup(wVersionRequested,&wsaData);

	m_hSocket = socket(AF_INET,SOCK_STREAM,0);

	m_saList.RemoveAll();//列表清空

	WSAAsyncSelect(m_hSocket,
		           this->m_hWnd,
				   WM_SERVERMSG,
				   FD_ACCEPT|FD_READ|FD_WRITE|FD_CLOSE);

   m_uPort = 8888;

   m_addr.sin_family = AF_INET;
   m_addr.sin_addr.S_un.S_addr = INADDR_ANY;
   m_addr.sin_port = htons(m_uPort);

   bind(m_hSocket,(LPSOCKADDR)&m_addr,sizeof(m_addr));//绑定套接字，和客户端无关

   listen(m_hSocket,3);//监听
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CServerDlg::OnPaint() 
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
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CServerDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	WSAAsyncSelect(m_hSocket,this->m_hWnd,0,0);
	WSACleanup();
	
}

void CServerDlg::OnButton1() 
{
	UpdateData(TRUE);

	m_strShow += _T("\r\n");
	m_strShow += m_strMsg;

	SOCKET s;
    
	s = m_saList.GetAt(m_saList.FindIndex(0));//获取套接字列表中的第一个套接字
	send(s,m_strMsg.GetBuffer(0),m_strMsg.GetLength(),0);//给它发送信息

	m_strMsg.Empty();

	UpdateData(FALSE);

	m_Show.LineScroll(m_Show.GetLineCount());//跟踪滚动条位置
	
}

long CServerDlg::OnServerMsg(WPARAM wParam,LPARAM lParam)
{
  SOCKET socket,s;
  char buf[1024];
  int len;
  switch (lParam)
  {
  case FD_ACCEPT :

	  socket = accept(m_hSocket,NULL,NULL);//接受连接请求并获取其套接字

	 /* if (m_saList.GetCount()!=0)
	  {

	  s = m_saList.GetAt(m_saList.FindIndex(0));	  

	  strcat(buf,"通话开始!");
	  send(s,buf,strlen(buf),0);

	  UpdateData(FALSE);

	  }*/

	//  m_strShow += "\r\n";
	  m_strShow += "对方发起谈话要求";

	  UpdateData(FALSE);

	  m_saList.AddHead(socket);//把该套接字加入套接字队列中

	//  buf[0]=NULL;

	  return 0;

  case FD_READ : //接受某一个套接字的信息，并传发其它每一个套接字，应该还有一个for循环的

    if (m_saList.GetCount()!=0)
	{
	  s = m_saList.GetAt(m_saList.FindIndex(0));

      if (s == wParam)
      {
		  len = recv(s,buf,1024,0);
		  buf[len] = NULL;
      }
	  else
	  {
          send(s,buf,strlen(buf),0);
	  }
	}

	m_strShow += "\r\n";
	m_strShow += buf;
    UpdateData(FALSE);
	return 0;
  case FD_WRITE :
	  return 0;
  case FD_CLOSE :
	  return 0;
  default:
	  m_strShow += "\r\n";
	  UpdateData(FALSE);
	  return 0;
  }
}

	  
