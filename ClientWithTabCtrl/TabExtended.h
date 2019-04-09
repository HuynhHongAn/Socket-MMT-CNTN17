#pragma once

// TabExtended dialog

class TabExtended : public CDialogEx
{
	DECLARE_DYNAMIC(TabExtended)

public:
	TabExtended(CWnd* pParent = nullptr);   // standard constructor
	virtual ~TabExtended();
	TabExtended(SOCKET &sk) {
		sClient = sk;
	};

	SOCKET sClient;
	CString Command;


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MORE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonLogout();
};
