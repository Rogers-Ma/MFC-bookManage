// bookDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "book.h"
#include "bookDlg.h"
#include "user.h"
#include "ManageDlg.h"
#include<string>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CbookDlg 对话框




CbookDlg::CbookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CbookDlg::IDD, pParent)
	, UserID("张三")
	, password("123456")
{


	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CbookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, UserID);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, password);
}

BEGIN_MESSAGE_MAP(CbookDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CbookDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CbookDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CbookDlg 消息处理程序

BOOL CbookDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CbookDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CbookDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CbookDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Login
void CbookDlg::OnBnClickedOk()
{

//UpdateData(TRUE): 表示写数据，将窗口控制变量写入内存（更新数据） 
//
//-------使用OnOk时将自动调用UpdateData(True) ，用以将窗口数据写入内存相应成员变量中；
//
//UpdateData(FALSE): 表示读数据，即显示窗口读取内存的数据以供实时显示  
//
//------使用OnInitDialog中，MFC调用UpdateData((FALSE)将内存成员数据显示到对应的窗口中

	UpdateData(true);
	UpdateData(false);
	
	UserList users;

	if(users.search(UserID.GetBuffer(),password.GetBuffer())){
		OnCancel();
		CManageDlg manageDlg;
		manageDlg.DoModal();
	}else{
		MessageBox("error");
	}
	
	

}

//cancel
void CbookDlg::OnBnClickedCancel()
{
	OnCancel();
}
