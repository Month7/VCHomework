#if !defined(AFX_WRITERDIALOG_H__E24F4A76_4BB2_4D04_9312_8721A6CB766E__INCLUDED_)
#define AFX_WRITERDIALOG_H__E24F4A76_4BB2_4D04_9312_8721A6CB766E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WriterDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// WriterDialog dialog

class WriterDialog : public CDialog
{
// Construction
public:
	WriterDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(WriterDialog)
	enum { IDD = IDD_DIALOG_WRITER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(WriterDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(WriterDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WRITERDIALOG_H__E24F4A76_4BB2_4D04_9312_8721A6CB766E__INCLUDED_)
