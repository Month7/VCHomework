#if !defined(AFX_HELPDIALOG_H__1E9A4539_88D1_445F_B625_07EAFCDCC612__INCLUDED_)
#define AFX_HELPDIALOG_H__1E9A4539_88D1_445F_B625_07EAFCDCC612__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// HelpDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// HelpDialog dialog

class HelpDialog : public CDialog
{
// Construction
public:
	HelpDialog(CWnd* pParent = NULL);   // standard constructor
protected:
	RECT m_pRectLink;              //用于保存静态文本框的屏幕坐标
// Dialog Data
	//{{AFX_DATA(HelpDialog)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(HelpDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(HelpDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELPDIALOG_H__1E9A4539_88D1_445F_B625_07EAFCDCC612__INCLUDED_)
