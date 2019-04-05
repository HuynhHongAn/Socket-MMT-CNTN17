#pragma once


// GroupChat dialog

class GroupChat : public CDialogEx
{
	DECLARE_DYNAMIC(GroupChat)

public:
	GroupChat(CWnd* pParent = nullptr);   // standard constructor
	virtual ~GroupChat();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
