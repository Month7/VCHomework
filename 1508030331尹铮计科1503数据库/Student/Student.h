// Student.h : main header file for the STUDENT application
//

#if !defined(AFX_STUDENT_H__428D16AF_8E8C_45F7_8A5D_A6184CC848EC__INCLUDED_)
#define AFX_STUDENT_H__428D16AF_8E8C_45F7_8A5D_A6184CC848EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "UserLogin.h"

/////////////////////////////////////////////////////////////////////////////
// CStudentApp:
// See Student.cpp for the implementation of this class
//

class CStudentApp : public CWinApp
{
public:
	CStudentApp();
public:
	BOOL m_bIsAdmin;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CStudentApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENT_H__428D16AF_8E8C_45F7_8A5D_A6184CC848EC__INCLUDED_)
