
// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
#include "afxdialogex.h"
#include "MainSpace.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientDlg dialog



CClientDlg::CClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLIENT_DIALOG, pParent)
	, userName(_T(""))
	, passWord(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_editUserName, userName);
	DDX_Text(pDX, IDC_editPassWord, passWord);
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_SOCKET, SockMsg)
	ON_BN_CLICKED(IDC_BUTTONLOGIN, &CClientDlg::OnBnClickedButtonlogin)
	ON_BN_CLICKED(IDC_BUTTONSignUp, &CClientDlg::OnBnClickedButtonsignup)
END_MESSAGE_MAP()


// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientDlg::OnPaint()
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
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

char * CClientDlg::ConvertToChar(const CString & s)
{
	int nSize = s.GetLength();
	char *pAnsiString = new char[nSize + 1];
	memset(pAnsiString, 0, nSize + 1);
	wcstombs(pAnsiString, s, nSize + 1);
	return pAnsiString;
}

void CClientDlg::Split(CString src, CString des[2])
{
	int p1, p2;

	p1 = src.Find(_T("\r\n"), 0);
	des[0] = src.Mid(0, p1);

	p2 = src.Find(_T("\r\n"), p1 + 1);
	des[1] = src.Mid(p1 + 2, p2 - (p1 + 2));
}

void CClientDlg::mSend(CString Command)
{
	int Len = Command.GetLength();
	Len += Len;
	PBYTE sendBuff = new BYTE[1000];
	memset(sendBuff, 0, 1000);
	memcpy(sendBuff, (PBYTE)(LPCTSTR)Command, Len);
	send(sClient, (char*)&Len, sizeof(Len), 0);
	send(sClient, (char*)sendBuff, Len, 0);
	delete sendBuff;
}

int CClientDlg::mRecv(CString & Command)
{
	PBYTE buffer = new BYTE[1000];
	memset(buffer, 0, 1000);
	recv(sClient, (char*)&buffLength, sizeof(int), 0);
	recv(sClient, (char*)buffer, buffLength, 0);
	TCHAR* ttc = (TCHAR*)buffer;
	Command = ttc;

	if (Command.GetLength() == 0)
		return -1;
	return 0;
}

LRESULT CClientDlg::SockMsg(WPARAM wParam, LPARAM lParam)
{
	if (WSAGETSELECTERROR(lParam))
	{
		// Display the error and close the socket
		closesocket(wParam);
	}
	switch (WSAGETSELECTEVENT(lParam))
	{
	case FD_READ:
	{
		CString temp;
		if (mRecv(temp) < 0) {
			break;
		}
		MessageBox(temp);
		UpdateData(FALSE);
		Split(temp, strResult);
		int flag1 = _ttoi(strResult[0]);
		int flag2 = _ttoi(strResult[1]);
		switch (flag1)
		{
		case 1: // log in
		{
			if (flag2 == 1)
			{
				MessageBox(_T("Success\r\n"));
			}
			if (flag2 == 0)
			{
				MessageBox(_T("Username has been used\r\n"));
			}
			if (flag2 == 2)
			{
				MessageBox(_T("Wrong password\r\n"));
			}
			if (flag2 == 3)
			{
				MessageBox(_T("Wrong username\r\n"));
			}
			UpdateData(FALSE);
			break;
		}

		case 2:
		{
			if (flag2 == 0)
			{
				MessageBox(_T("Sign Up failed\r\nUsername has been used\r\n"));
			}
			if (flag2 == 1)
			{
				MessageBox(_T("Sign Up success!!"));

			}
			if (flag2 == 2)
			{
				MessageBox(_T("Sign Up failed\r\nUsername has already existed\r\n"));

			}

			break;
		}
		}
		break;
	}
	case FD_CLOSE:
	{
		closesocket(sClient);
		MessageBox(_T("Server close the connection\r\n"));
		UpdateData(FALSE);
		break;
	}

	}
	return 0;
}


//Catch the event when click  Button Login in first dialog
void CClientDlg::OnBnClickedButtonlogin()
{
	UpdateData(TRUE);

	sClient = socket(AF_INET, SOCK_STREAM, 0);
	hostent* host = NULL;
	if (sClient == INVALID_SOCKET)
	{
		MessageBox(_T("socket() failed"), _T("ERROR"), 0);
		return;
	}
	servAdd.sin_family = AF_INET;
	servAdd.sin_port = htons(PORT);
	CString IP("127.0.0.1");
	char* cIP = ConvertToChar(IP);

	servAdd.sin_addr.s_addr = inet_addr(cIP);

	CStringA cpy_IP(IP);

	if (servAdd.sin_addr.s_addr == INADDR_NONE)
	{
		host = (gethostbyname(cpy_IP));
		if (host == NULL)
		{
			MessageBox(_T("Khong the ket noi den server."), _T("ERROR"), 0);
		}
		CopyMemory(&servAdd.sin_addr, host->h_addr_list[0],
			host->h_length);
		return;
	}

	int err = connect(sClient, (struct sockaddr*)&servAdd, sizeof(servAdd));
	if (err == SOCKET_ERROR) {
		MessageBox(_T("Ket noi that bai"), _T("ERROR"), 0);
		return;
	}


	CString user, password;
	GetDlgItemText(IDC_editUserName, user);
	GetDlgItemText(IDC_editPassWord, password);
	if (!user.GetLength() || !password.GetLength())
	{
		MessageBox(_T("Username or password can not be blank"));
		return;
	}


	Command = "1\r\n";
	Command += user + '/' + password;
	Command += "\r\n";

	mSend(Command);



	WSAAsyncSelect(sClient, m_hWnd, WM_SOCKET, FD_READ | FD_CLOSE);
	UpdateData(FALSE);


}

// Catch the event when click Button SignUp in first dialog
void CClientDlg::OnBnClickedButtonsignup()
{
	UpdateData(TRUE);

	sClient = socket(AF_INET, SOCK_STREAM, 0);
	hostent* host = NULL;
	if (sClient == INVALID_SOCKET)
	{
		MessageBox(_T("socket() failed"), _T("ERROR"), 0);
		return;
	}
	servAdd.sin_family = AF_INET;
	servAdd.sin_port = htons(PORT);
	CString IP("127.0.0.1");
	char* cIP = ConvertToChar(IP);

	servAdd.sin_addr.s_addr = inet_addr(cIP);

	CStringA cpy_IP(IP);

	if (servAdd.sin_addr.s_addr == INADDR_NONE)
	{
		host = (gethostbyname(cpy_IP));
		if (host == NULL)
		{
			MessageBox(_T("Can not connect to server."), _T("ERROR"), 0);
		}
		CopyMemory(&servAdd.sin_addr, host->h_addr_list[0],
			host->h_length);
		return;
	}

	int err = connect(sClient, (struct sockaddr*)&servAdd, sizeof(servAdd));
	if (err == SOCKET_ERROR) {
		MessageBox(_T("Connect failed"), _T("ERROR"), 0);
		return;
	}


	CString user, password;
	GetDlgItemText(IDC_editUserName, user);
	GetDlgItemText(IDC_editPassWord, password);
	if (!user.GetLength() || !password.GetLength())
	{
		MessageBox(_T("Username or password can not be blank"));
		return;
	}


	Command = "2\r\n";
	Command += user + '/' + password;
	Command += "\r\n";

	mSend(Command);



	WSAAsyncSelect(sClient, m_hWnd, WM_SOCKET, FD_READ | FD_CLOSE);
	UpdateData(FALSE);
}
