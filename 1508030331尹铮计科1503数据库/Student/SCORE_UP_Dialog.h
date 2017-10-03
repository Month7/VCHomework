#if !defined(AFX_SCORE_UP_DIALOG_H__B656772A_BF84_447A_8F87_C78389DCA617__INCLUDED_)
#define AFX_SCORE_UP_DIALOG_H__B656772A_BF84_447A_8F87_C78389DCA617__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SCORE_UP_Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SCORE_UP_Dialog dialog

class SCORE_UP_Dialog : public CDialog
{
// Construction
public:
	SCORE_UP_Dialog(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(SCORE_UP_Dialog)
	enum { IDD = IDD_DIALOG_SCORE_UP };
	long	m_str_Score;
	long	m_str_Makeup;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SCORE_UP_Dialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SCORE_UP_Dialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCORE_UP_DIALOG_H__B656772A_BF84_447A_8F87_C78389DCA617__INCLUDED_)
