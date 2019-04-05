// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client2.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "ChatPrivate.h"
#include "GroupChat.h"

// MainDlg dialog

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MainDlg::~MainDlg()
{
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GroupChat, &MainDlg::OnBnClickedButtonGroupchat)
	ON_BN_CLICKED(IDC_BUTTON_PrivateChat, &MainDlg::OnBnClickedButtonPrivatechat)
END_MESSAGE_MAP()


// MainDlg message handlers


void MainDlg::OnBnClickedButtonGroupchat()
{
	GroupChat obj;
	obj.DoModal();
	// TODO: Add your control notification handler code here
}


void MainDlg::OnBnClickedButtonPrivatechat()
{
	ChatPrivate obj;
	obj.DoModal();
	// TODO: Add your control notification handler code here
}
