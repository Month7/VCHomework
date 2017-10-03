#if !defined(AFX_SEARCH_H__5567F4F4_45AA_429A_86FB_FF97E378A166__INCLUDED_)
#define AFX_SEARCH_H__5567F4F4_45AA_429A_86FB_FF97E378A166__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SEARCH.h : header file
//
#include "ScoreSet.h"
/////////////////////////////////////////////////////////////////////////////
// SEARCH dialog

class SEARCH : public CDialog
{
// Construction
public:
	void RefreshData(CString strSQL);
	SEARCH(CWnd* pParent = NULL);   // standard constructor
	CScoreSet  m_recordset;
// Dialog Data
	//{{AFX_DATA(SEARCH)
	enum { IDD = IDD_DIALOG_SEARCH };
	CEdit	m_ctrSubject;
	CEdit	m_ctrName;
	CEdit	m_ctrClass;
	CListCtrl	m_ctrList;
	CString	m_strClass;
	CString	m_strName;
	CString	m_strSubject;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SEARCH)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SEARCH)
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnButton1Delete();
	afx_msg void OnButton1Modify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCH_H__5567F4F4_45AA_429A_86FB_FF97E378A166__INCLUDED_)
