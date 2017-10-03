// studentba.h : main header file for the STUDENTBA application
//

#if !defined(AFX_STUDENTBA_H__860279F1_AF9A_4796_B736_5A84969ED25E__INCLUDED_)
#define AFX_STUDENTBA_H__860279F1_AF9A_4796_B736_5A84969ED25E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStudentbaApp:
// See studentba.cpp for the implementation of this class
//

class CStudentbaApp : public CWinApp
{
public:
	CStudentbaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentbaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CStudentbaApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTBA_H__860279F1_AF9A_4796_B736_5A84969ED25E__INCLUDED_)
