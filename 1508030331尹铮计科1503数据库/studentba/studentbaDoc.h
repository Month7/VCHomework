// studentbaDoc.h : interface of the CStudentbaDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENTBADOC_H__CD534E96_DB97_47B1_ABCB_40AA31E65DCD__INCLUDED_)
#define AFX_STUDENTBADOC_H__CD534E96_DB97_47B1_ABCB_40AA31E65DCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "studentbaSet.h"


class CStudentbaDoc : public CDocument
{
protected: // create from serialization only
	CStudentbaDoc();
	DECLARE_DYNCREATE(CStudentbaDoc)

// Attributes
public:
	CStudentbaSet m_studentbaSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentbaDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStudentbaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStudentbaDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTBADOC_H__CD534E96_DB97_47B1_ABCB_40AA31E65DCD__INCLUDED_)
