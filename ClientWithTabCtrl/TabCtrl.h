#pragma once


// TabCtrl

class TabCtrl : public CTabCtrl
{
	DECLARE_DYNAMIC(TabCtrl)

public:
	TabCtrl();
	TabCtrl(SOCKET &sk);
	virtual ~TabCtrl();
	CDialogEx *tabWork[4];
	int m_currentTab;
	void Init();
	void SetRectangle(int n);
	void ShowTab(int n);
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


