#pragma once
#define PORT 25000
#define WM_SOCKET WM_USER+2

// TabLogin dialog

class TabLogin : public CDialogEx
{
	DECLARE_DYNAMIC(TabLogin)
public:
	TabLogin(CWnd* pParent = nullptr);   // standard constructor
	virtual ~TabLogin();
	TabLogin(SOCKET &sk) {
		sClient = sk;
	};
	sockaddr_in servAdd;

	SOCKET sClient;
	CString Command;
	int	buffLength;
	CString strResult[3];

	LRESULT SockMsg(WPARAM wParam, LPARAM lParam);

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TABLOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonlogin();
	afx_msg void OnBnClickedButtonsignup();
	CString StringIP;
};
