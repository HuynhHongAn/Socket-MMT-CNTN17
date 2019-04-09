// TabGroupChat.cpp : implementation file
//

#include "stdafx.h"
#include "ClientWithTabCtrl.h"
#include "TabGroupChat.h"
#include "afxdialogex.h"


// TabGroupChat dialog

IMPLEMENT_DYNAMIC(TabGroupChat, CDialogEx)

TabGroupChat::TabGroupChat(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_GROUPCHAT, pParent)
{

}

TabGroupChat::~TabGroupChat()
{
}

void TabGroupChat::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabGroupChat, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GroupSEND, &TabGroupChat::OnBnClickedButtonGroupsend)
END_MESSAGE_MAP()


// TabGroupChat message handlers


void TabGroupChat::OnBnClickedButtonGroupsend()
{
	// TODO: Add your control notification handler code here
}
