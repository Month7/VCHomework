#if !defined(AFX_STUDENTDLG_H__64E9910C_D5AA_4747_B042_6BAF2BA5E5C3__INCLUDED_)
#define AFX_STUDENTDLG_H__64E9910C_D5AA_4747_B042_6BAF2BA5E5C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StudentSet1.h"
#include "StudentInfoDlg.h"
// StudentDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg dialog

class CStudentDlg : public CDialog
{
// Construction
public:
	void RefreshData(CString strSQL);
	CStudentDlg(CWnd* pParent = NULL);   // standard constructor
	CStudentSet1 m_recordset;
// Dialog Data
	//{{AFX_DATA(CStudentDlg)
	enum { IDD = IDD_DIALOG_STUDENT };
	CEdit	m_ctrDepartment;
	CEdit	m_ctrMajor;
	CEdit	m_ctrClass;
	CListCtrl	m_ctrlList;
	CString	m_strClass;
	CString	m_strMajor;
	CString	m_strDepartment;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStudentDlg)
	afx_msg void OnButtonNew();
	afx_msg void OnButtonModify();
	afx_msg void OnButtonDelete1();
	afx_msg void OnButtonBrowse();
	afx_msg void OnButtonSearch();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTDLG_H__64E9910C_D5AA_4747_B042_6BAF2BA5E5C3__INCLUDED_)
