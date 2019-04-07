// MainSpace.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "MainSpace.h"
#include "afxdialogex.h"



// MainSpace dialog

IMPLEMENT_DYNAMIC(MainSpace, CDialogEx)

MainSpace::MainSpace(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, msgStringGroup(_T(""))
	, msgPrivateChat(_T(""))
	, UserPartner(_T(""))
	, contentGroupChat(_T(""))
	, contentPrivateChat(_T(""))
{

}

MainSpace::~MainSpace()
{

}

void MainSpace::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, msgStringGroup);
	DDX_Text(pDX, IDC_editMessage, msgPrivateChat);
	DDX_Text(pDX, IDC_EDIT2, UserPartner);
	DDX_Text(pDX, IDC_ContentGroupChat, contentGroupChat);
	DDX_Text(pDX, IDC_ContentPrivateChat, contentPrivateChat);
}


BEGIN_MESSAGE_MAP(MainSpace, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_Attach, &MainSpace::OnBnClickedButtonAttach)
	ON_BN_CLICKED(IDC_BUTTON_Invite, &MainSpace::OnBnClickedButtonInvite)
	ON_BN_CLICKED(IDC_BUTTON_Leave, &MainSpace::OnBnClickedButtonLeave)
	ON_BN_CLICKED(IDC_BUTTON_GroupSEND, &MainSpace::OnBnClickedButtonGroupsend)
	ON_BN_CLICKED(IDC_BUTTON_PrivateSEND, &MainSpace::OnBnClickedButtonPrivatesend)
	ON_BN_CLICKED(IDC_BUTTON_Logout, &MainSpace::OnBnClickedButtonLogout)
END_MESSAGE_MAP()


// MainSpace message handlers

// Catch the event when click Button Attach in second dialog
void MainSpace::OnBnClickedButtonAttach()
{

}

// Catch the event when click Button Invite in second dialog
void MainSpace::OnBnClickedButtonInvite()
{

}

// Catch the event when click Button Leave in second dialog
void MainSpace::OnBnClickedButtonLeave()
{

}

// Catch the event when click Button Send in Group chat
void MainSpace::OnBnClickedButtonGroupsend()
{

}

// Catch the event when click Button Send in Private chat
void MainSpace::OnBnClickedButtonPrivatesend()
{

}


void MainSpace::OnBnClickedButtonLogout()
{
	// TODO: Add your control notification handler code here
}
