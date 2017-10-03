#if !defined(AFX_SCOREINPUTDLG_H__C4AC7F3D_E73C_4E2C_B33C_66E4797AB78F__INCLUDED_)
#define AFX_SCOREINPUTDLG_H__C4AC7F3D_E73C_4E2C_B33C_66E4797AB78F__INCLUDED_
#include "ScoreSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoreInputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScoreInputDlg dialog

class CScoreInputDlg : public CDialog
{
// Construction
public:
	void RefreshData(CString strSQL);
	void CreateScoreTable();
	CScoreInputDlg(CWnd* pParent = NULL);   // standard constructor
	CScoreSet  m_recordset;

// Dialog Data
	//{{AFX_DATA(CScoreInputDlg)
	enum { IDD = IDD_DIALOG_SCORE_INPUT };
	CListCtrl	m_ctrList;
	CString	m_strClass;
	CString	m_strTime;
	CString	m_strExamclass;
	CString	m_strSubject;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoreInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScoreInputDlg)
	afx_msg void OnButtonInput();
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOREINPUTDLG_H__C4AC7F3D_E73C_4E2C_B33C_66E4797AB78F__INCLUDED_)
