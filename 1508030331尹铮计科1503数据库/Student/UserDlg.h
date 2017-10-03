#if !defined(AFX_USERDLG_H__229E82B7_44D5_4714_B5C1_51736E55B4D1__INCLUDED_)
#define AFX_USERDLG_H__229E82B7_44D5_4714_B5C1_51736E55B4D1__INCLUDED_
#include "UserSet2.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserDlg dialog

class CUserDlg : public CDialog
{
// Construction
public:
	void RefreshData();
	CUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserDlg)
	enum { IDD = IDD_DIALOG_USER };
	CListCtrl	m_ctrList;
	CUserSet2  m_recordset;
	CEdit	m_ctrRePass;
	CEdit	m_ctrPass;
	CEdit	m_ctrUser;
	CString	m_strUser;
	CString	m_strPass;
	CString	m_strRePass;
	BOOL	m_bIsAdmin;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserDlg)
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	virtual void OnOK();
	afx_msg void OnButtonCancle();
	virtual BOOL OnInitDialog();
	afx_msg void OnClickListUsername(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERDLG_H__229E82B7_44D5_4714_B5C1_51736E55B4D1__INCLUDED_)
