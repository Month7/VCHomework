// EditSoft.h : main header file for the EDITSOFT application
//

#if !defined(AFX_EDITSOFT_H__288431C4_2A4C_4911_B9C5_BC6DEBD86D38__INCLUDED_)
#define AFX_EDITSOFT_H__288431C4_2A4C_4911_B9C5_BC6DEBD86D38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEditSoftApp:
// See EditSoft.cpp for the implementation of this class
//

class CEditSoftApp : public CWinApp
{
public:
	CEditSoftApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditSoftApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEditSoftApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITSOFT_H__288431C4_2A4C_4911_B9C5_BC6DEBD86D38__INCLUDED_)
