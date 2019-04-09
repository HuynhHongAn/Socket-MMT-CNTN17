// TabPrivate.cpp : implementation file
//

#include "stdafx.h"
#include "ClientWithTabCtrl.h"
#include "TabPrivate.h"
#include "afxdialogex.h"


// TabPrivate dialog

IMPLEMENT_DYNAMIC(TabPrivate, CDialogEx)

TabPrivate::TabPrivate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_PRIVATE, pParent)
{

}

TabPrivate::~TabPrivate()
{
}

void TabPrivate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabPrivate, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_Invite, &TabPrivate::OnBnClickedButtonInvite)
	ON_BN_CLICKED(IDC_BUTTON_Leave, &TabPrivate::OnBnClickedButtonLeave)
	ON_BN_CLICKED(IDC_BUTTON_PrivateSEND, &TabPrivate::OnBnClickedButtonPrivatesend)
	ON_BN_CLICKED(IDC_BUTTON_Attach, &TabPrivate::OnBnClickedButtonAttach)
END_MESSAGE_MAP()


// TabPrivate message handlers


void TabPrivate::OnBnClickedButtonInvite()
{
	// TODO: Add your control notification handler code here
}


void TabPrivate::OnBnClickedButtonLeave()
{
	// TODO: Add your control notification handler code here
}


void TabPrivate::OnBnClickedButtonPrivatesend()
{
	// TODO: Add your control notification handler code here
}


void TabPrivate::OnBnClickedButtonAttach()
{
	// TODO: Add your control notification handler code here
}
