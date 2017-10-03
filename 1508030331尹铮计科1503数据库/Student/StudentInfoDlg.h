#if !defined(AFX_STUDENTINFODLG_H__744A7966_72A3_4CF3_B581_22A56D3D0005__INCLUDED_)
#define AFX_STUDENTINFODLG_H__744A7966_72A3_4CF3_B581_22A56D3D0005__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentInfoDlg dialog

class CStudentInfoDlg : public CDialog
{
// Construction
public:
	CStudentInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStudentInfoDlg)
	enum { IDD = IDD_DIALOG_STUDENT_INFO };
	CString	m_strCode;
	CString	m_strDepartment;
	CString	m_strName;
	CString	m_strSex;
	CString	m_strMajor;
	CTime	m_tmBirth;
	CString	m_strClass;
	CString	m_strPhone;
	CString	m_strAddress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStudentInfoDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTINFODLG_H__744A7966_72A3_4CF3_B581_22A56D3D0005__INCLUDED_)
