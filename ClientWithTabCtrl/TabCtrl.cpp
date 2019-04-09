// TabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ClientWithTabCtrl.h"
#include "TabCtrl.h"
#include "TabExtended.h"
#include "TabPrivate.h"
#include "TabGroupChat.h"
#include "TabLogin.h"

// TabCtrl

IMPLEMENT_DYNAMIC(TabCtrl, CTabCtrl)

TabCtrl::TabCtrl()
{
	tabWork[0] = new TabLogin;
	tabWork[1] = new TabGroupChat;
	tabWork[2] = new TabPrivate;
	tabWork[3] = new TabExtended;

	m_currentTab = 0;
}

TabCtrl::TabCtrl(SOCKET &sk)
{
	tabWork[0] = new TabLogin(sk);
	tabWork[1] = new TabGroupChat(sk);
	tabWork[2] = new TabPrivate(sk);
	tabWork[3] = new TabExtended(sk);
	m_currentTab = 0;
}

TabCtrl::~TabCtrl()
{
	for (int i = 0; i < 4; i++) delete tabWork[i];

}


void TabCtrl::Init()
{

	tabWork[0]->Create(IDD_TABLOGIN, this);
	tabWork[1]->Create(IDD_TAB_GROUPCHAT, this);
	tabWork[2]->Create(IDD_TAB_PRIVATE, this);
	tabWork[3]->Create(IDD_MORE, this);

	//tabWork[0]->ShowWindow(SW_HIDE);
	//tabWork[1]->ShowWindow(SW_HIDE);
	//tabWork[2]->ShowWindow(SW_HIDE);
	//tabWork[3]->ShowWindow(SW_HIDE);

	SetRectangle(0);
}

void TabCtrl::SetRectangle(int n)
{
	CRect tabRect, itemRect;

	int nX, nY, nXe, nYe;

	GetClientRect(&tabRect);

	GetItemRect(0, &itemRect);

	nX = itemRect.left;

	nY = itemRect.bottom + 1;

	nXe = tabRect.right - itemRect.left + 1;

	nYe = tabRect.bottom - nY + 1;
	for(int i=0;i<4;i++)
	tabWork[i]->SetWindowPos(&wndTop, nX, nY, nXe, nYe, SWP_HIDEWINDOW);

	tabWork[n]->SetWindowPos(&wndTop, nX, nY, nXe, nYe, SWP_SHOWWINDOW);

}

void TabCtrl::ShowTab(int n)
{
	tabWork[m_currentTab]->ShowWindow(SW_HIDE);
	m_currentTab = n;
	tabWork[m_currentTab]->ShowWindow(SW_SHOW);
	tabWork[m_currentTab]->SetFocus();
}


BEGIN_MESSAGE_MAP(TabCtrl, CTabCtrl)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// TabCtrl message handlers




void TabCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CTabCtrl::OnLButtonDown(nFlags, point);
	if (m_currentTab != GetCurFocus())
	{
		tabWork[m_currentTab]->ShowWindow(SW_HIDE);
		m_currentTab = GetCurFocus();
		tabWork[m_currentTab]->ShowWindow(SW_SHOW);
		tabWork[m_currentTab]->SetFocus();
	}
}
