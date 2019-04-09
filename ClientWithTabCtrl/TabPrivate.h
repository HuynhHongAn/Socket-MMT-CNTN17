#pragma once

// TabPrivate dialog

class TabPrivate : public CDialogEx
{
	DECLARE_DYNAMIC(TabPrivate)

public:
	TabPrivate(CWnd* pParent = nullptr);   // standard constructor
	virtual ~TabPrivate();

	TabPrivate(SOCKET &sk) {
		sClient = sk;
	};

	SOCKET sClient;
	CString Command;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_PRIVATE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonInvite();
	afx_msg void OnBnClickedButtonLeave();
	afx_msg void OnBnClickedButtonPrivatesend();
	afx_msg void OnBnClickedButtonAttach();
};
