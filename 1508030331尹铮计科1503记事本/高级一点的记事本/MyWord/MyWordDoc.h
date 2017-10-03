// MyWordDoc.h : interface of the CMyWordDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYWORDDOC_H__D257F33D_4917_4E7B_87EE_23F11272424B__INCLUDED_)
#define AFX_MYWORDDOC_H__D257F33D_4917_4E7B_87EE_23F11272424B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyWordDoc : public CRichEditDoc
{
protected: // create from serialization only
	CMyWordDoc();
	DECLARE_DYNCREATE(CMyWordDoc)

// Attributes
public:
	CFont m_Font;
	LOGFONT m_lf;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWordDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// Implementation
public:
	virtual ~CMyWordDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyWordDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWORDDOC_H__D257F33D_4917_4E7B_87EE_23F11272424B__INCLUDED_)
