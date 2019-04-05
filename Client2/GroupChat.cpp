// GroupChat.cpp : implementation file
//

#include "stdafx.h"
#include "Client2.h"
#include "GroupChat.h"
#include "afxdialogex.h"


// GroupChat dialog

IMPLEMENT_DYNAMIC(GroupChat, CDialogEx)

GroupChat::GroupChat(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

GroupChat::~GroupChat()
{
}

void GroupChat::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GroupChat, CDialogEx)
END_MESSAGE_MAP()


// GroupChat message handlers
