// NewTetris.h : main header file for the NEWTETRIS application
//

#if !defined(AFX_NEWTETRIS_H__CEC7FB87_5E3C_4A80_B317_09B5BE10F075__INCLUDED_)
#define AFX_NEWTETRIS_H__CEC7FB87_5E3C_4A80_B317_09B5BE10F075__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CNewTetrisApp:
// See NewTetris.cpp for the implementation of this class
//

class CNewTetrisApp : public CWinApp
{
public:
	CNewTetrisApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewTetrisApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CNewTetrisApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWTETRIS_H__CEC7FB87_5E3C_4A80_B317_09B5BE10F075__INCLUDED_)
