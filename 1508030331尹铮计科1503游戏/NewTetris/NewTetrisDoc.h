// NewTetrisDoc.h : interface of the CNewTetrisDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWTETRISDOC_H__05350801_B389_4883_88DA_23F0010F2708__INCLUDED_)
#define AFX_NEWTETRISDOC_H__05350801_B389_4883_88DA_23F0010F2708__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNewTetrisDoc : public CDocument
{
protected: // create from serialization only
	CNewTetrisDoc();
	DECLARE_DYNCREATE(CNewTetrisDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewTetrisDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNewTetrisDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNewTetrisDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWTETRISDOC_H__05350801_B389_4883_88DA_23F0010F2708__INCLUDED_)
