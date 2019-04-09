// TabExtended.cpp : implementation file
//

#include "stdafx.h"
#include "ClientWithTabCtrl.h"
#include "TabExtended.h"
#include "afxdialogex.h"


// TabExtended dialog

IMPLEMENT_DYNAMIC(TabExtended, CDialogEx)

TabExtended::TabExtended(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MORE, pParent)
{

}

TabExtended::~TabExtended()
{
}

void TabExtended::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabExtended, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_Logout, &TabExtended::OnBnClickedButtonLogout)
END_MESSAGE_MAP()


// TabExtended message handlers


void TabExtended::OnBnClickedButtonLogout()
{
	// TODO: Add your control notification handler code here
}
