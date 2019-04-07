#pragma once


// MainSpace dialog

class MainSpace : public CDialogEx
{
	DECLARE_DYNAMIC(MainSpace)

public:
	MainSpace(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MainSpace();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAttach();
	afx_msg void OnBnClickedButtonInvite();
	afx_msg void OnBnClickedButtonLeave();
	CString msgStringGroup;
	CString msgPrivateChat;
	CString UserPartner;
	CString contentGroupChat;
	CString contentPrivateChat;
	CString OnlineList;
	afx_msg void OnBnClickedButtonGroupsend();
	afx_msg void OnBnClickedButtonPrivatesend();
};
