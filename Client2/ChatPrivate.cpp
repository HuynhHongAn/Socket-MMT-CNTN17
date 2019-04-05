// ChatPrivate.cpp : implementation file
//

#include "stdafx.h"
#include "Client2.h"
#include "ChatPrivate.h"
#include "afxdialogex.h"


// ChatPrivate dialog

IMPLEMENT_DYNAMIC(ChatPrivate, CDialogEx)

ChatPrivate::ChatPrivate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

ChatPrivate::~ChatPrivate()
{
}

void ChatPrivate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ChatPrivate, CDialogEx)
END_MESSAGE_MAP()


// ChatPrivate message handlers
