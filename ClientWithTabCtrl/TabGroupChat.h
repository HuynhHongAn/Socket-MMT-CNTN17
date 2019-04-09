#pragma once

// TabGroupChat dialog

class TabGroupChat : public CDialogEx
{
	DECLARE_DYNAMIC(TabGroupChat)

public:
	TabGroupChat(CWnd* pParent = nullptr);   // standard constructor
	virtual ~TabGroupChat();

	TabGroupChat(SOCKET &sk) {
		sClient = sk;
	};

	SOCKET sClient;
	CString Command;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_GROUPCHAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonGroupsend();
};
