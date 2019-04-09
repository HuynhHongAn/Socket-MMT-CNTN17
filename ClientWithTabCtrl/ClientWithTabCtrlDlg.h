
// ClientWithTabCtrlDlg.h : header file
//

#pragma once
#include "TabCtrl.h"
#define PORT 25000
#define WM_SOCKET WM_USER+2

// CClientWithTabCtrlDlg dialog
class CClientWithTabCtrlDlg : public CDialogEx
{
// Construction
public:
	CClientWithTabCtrlDlg(CWnd* pParent = nullptr);	// standard constructor
	TabCtrl m_tab;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENTWITHTABCTRL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	LRESULT SockMsg(WPARAM wParam, LPARAM lParam);

	SOCKET sClient;
	CString Command;
	CString userName;
	CString passWord;
	sockaddr_in servAdd;
	int	buffLength;
	CString strResult[3];

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
