// TabLogin.cpp : implementation file
//

#include "stdafx.h"
#include "ClientWithTabCtrl.h"
#include "TabLogin.h"
#include "afxdialogex.h"
#include "General.h"

// TabLogin dialog

IMPLEMENT_DYNAMIC(TabLogin, CDialogEx)

TabLogin::TabLogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TABLOGIN, pParent)
	, StringIP(_T("127.0.0.1"))
{

}

TabLogin::~TabLogin()
{

}

void TabLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, StringIP);
}

LRESULT TabLogin::SockMsg(WPARAM wParam, LPARAM lParam)
{
	if (WSAGETSELECTERROR(lParam))
	{
		closesocket(wParam);
	}
	switch (WSAGETSELECTEVENT(lParam))
	{
	case FD_READ:
	{
		CString temp;
		if (mRecv(sClient, buffLength,temp) < 0) {
			break;
		}
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
				GetDlgItem(IDC_BUTTONLOGIN)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTONSignUp)->EnableWindow(FALSE);
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

BEGIN_MESSAGE_MAP(TabLogin, CDialogEx)
	ON_MESSAGE(WM_SOCKET, SockMsg)
	ON_BN_CLICKED(IDC_BUTTONLOGIN, &TabLogin::OnBnClickedButtonlogin)
	ON_BN_CLICKED(IDC_BUTTONSignUp, &TabLogin::OnBnClickedButtonsignup)
END_MESSAGE_MAP()


// TabLogin message handlers


void TabLogin::OnBnClickedButtonlogin()
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
	//CString IP("127.0.0.1");
	char* cIP = ConvertToChar(StringIP);

	servAdd.sin_addr.s_addr = inet_addr(cIP);

	CStringA cpy_IP(StringIP);

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


	Command = "1\r\n";
	Command += user + '/' + password;
	Command += "\r\n";

	mSend(sClient,Command);



	WSAAsyncSelect(sClient, m_hWnd, WM_SOCKET, FD_READ | FD_CLOSE);
	UpdateData(FALSE);

}


void TabLogin::OnBnClickedButtonsignup()
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
	char* cIP = ConvertToChar(StringIP);

	servAdd.sin_addr.s_addr = inet_addr(cIP);

	CStringA cpy_IP(StringIP);

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

	mSend(sClient,Command);



	WSAAsyncSelect(sClient, m_hWnd, WM_SOCKET, FD_READ | FD_CLOSE);
	UpdateData(FALSE);
}
