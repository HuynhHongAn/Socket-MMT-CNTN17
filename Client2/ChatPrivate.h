#pragma once


// ChatPrivate dialog

class ChatPrivate : public CDialogEx
{
	DECLARE_DYNAMIC(ChatPrivate)

public:
	ChatPrivate(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ChatPrivate();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
