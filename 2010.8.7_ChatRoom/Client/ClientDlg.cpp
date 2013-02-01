// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"

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
// CClientDlg dialog

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDlg)
	m_strShow = _T("");
	m_strMsg = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Control(pDX, IDC_EDIT1, m_Show);
	DDX_Text(pDX, IDC_EDIT1, m_strShow);
	DDX_Text(pDX, IDC_EDIT2, m_strMsg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_MESSAGE(WM_CLIENTMSG,OnClientMsg)//自定义的消息初始化
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
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

	WSADATA wsaData; //定义初始化对象
	
	WORD wVersionRequested = MAKEWORD(2,0); //确定版本
	WSAStartup(wVersionRequested,&wsaData); //初始化
	
	m_hSocket = socket(AF_INET,SOCK_STREAM,0); //初始化套接字 ：流套接字

	CString addr;
	
	addr.Format("115.156.202.209"); //定义要申请连接的服务器地址
	m_uPort = 8888; //定义端口
	m_addr.sin_family = AF_INET;//网络地址族
	m_addr.sin_addr.S_un.S_addr = inet_addr(addr.GetBuffer(0));//IP传值给结构地址
	m_addr.sin_port = htons(m_uPort); //传值端口
	
	WSAAsyncSelect(m_hSocket,//套接字
	           	  this->m_hWnd,//事件对象（对话框）           //将套接字和事件对象联系起来，并声明网络消息和事件
		          WM_CLIENTMSG,//消息
		          FD_CONNECT|FD_READ|FD_WRITE|FD_CLOSE);//事件
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClientDlg::OnPaint() 
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
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClientDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	WSAAsyncSelect(m_hSocket,this->m_hWnd,0,0);//取消异步选择模式
	WSACleanup();//清理Winsock
	
}

void CClientDlg::OnButton1() 
{
   UpdateData(TRUE);

   m_strShow += "\r\n";
   m_strShow += m_strMsg;

   send(m_hSocket,m_strMsg.GetBuffer(0),m_strMsg.GetLength(),0);//向服务器套接字发送数据

   m_strMsg.Empty();

   UpdateData(FALSE);

}

void CClientDlg::OnButton2() 
{
	connect(m_hSocket,(LPSOCKADDR)&m_addr,sizeof(m_addr));//申请连接，获取服务器套接字m_hSocket
}

long CClientDlg::OnClientMsg(WPARAM wParam,LPARAM lParam)//wParam代表套接字，lParam代表事件
{
  char buf[1024];
  int len;
  switch (lParam)//这里的都是要自动处理的
  {
  case FD_CONNECT :
		  m_strShow = "连接到服务器……";
		  UpdateData(FALSE);
		  return 0;
  case FD_READ :
	  len = recv(m_hSocket,buf,1024,0);//
	  buf[len] = NULL;   //这两个语句连一起的
	  m_strShow += "\r\n";//
	  m_strShow += buf;//这两个语句连一起的
	  UpdateData(FALSE);
  case FD_CLOSE :
	  return 0;
  case FD_WRITE :
	  return 0;
  default :
	  closesocket(m_hSocket);//关闭连接
	  return 0;
  }
}
