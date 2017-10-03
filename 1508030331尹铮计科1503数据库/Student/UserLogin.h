#if !defined(AFX_USERLOGIN_H__D3625FC7_4593_41CE_A9DE_EABF8E0DC2E0__INCLUDED_)
#define AFX_USERLOGIN_H__D3625FC7_4593_41CE_A9DE_EABF8E0DC2E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserLogin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserLogin dialog

class CUserLogin : public CDialog
{
// Construction
public:
	CUserLogin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserLogin)
	enum { IDD = IDD_DIALOG_LOGIN };
	CEdit	m_ctrPass;
	CEdit	m_ctrUser;
	CString	m_strUser;
	CString	m_strPass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserLogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserLogin)
	afx_msg void OnBnClickedOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERLOGIN_H__D3625FC7_4593_41CE_A9DE_EABF8E0DC2E0__INCLUDED_)
