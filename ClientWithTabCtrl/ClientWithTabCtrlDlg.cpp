
// ClientWithTabCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClientWithTabCtrl.h"
#include "ClientWithTabCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientWithTabCtrlDlg dialog



CClientWithTabCtrlDlg::CClientWithTabCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLIENTWITHTABCTRL_DIALOG, pParent)
	, userName(_T(""))
	, passWord(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientWithTabCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

LRESULT CClientWithTabCtrlDlg::SockMsg(WPARAM wParam, LPARAM lParam)
{
	// Do nothing
	return 0;
}

BEGIN_MESSAGE_MAP(CClientWithTabCtrlDlg, CDialogEx)

	ON_MESSAGE(WM_SOCKET, SockMsg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

END_MESSAGE_MAP()


// CClientWithTabCtrlDlg message handlers

BOOL CClientWithTabCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_tab.InsertItem(0, _T("LOGIN"));

	m_tab.InsertItem(1, _T("CHAT GROUP"));
	m_tab.InsertItem(2, _T("CHAT PRIVATE"));

	m_tab.InsertItem(3, _T("EXTENDED"));
	//GetDlgItem(m_table.GetItem())->EnableWindow(FALSE);

	m_tab.Init();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientWithTabCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClientWithTabCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

