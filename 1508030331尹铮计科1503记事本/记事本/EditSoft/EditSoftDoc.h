// EditSoftDoc.h : interface of the CEditSoftDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDITSOFTDOC_H__1DBA7F19_F48A_48FA_95D1_FF754CB56372__INCLUDED_)
#define AFX_EDITSOFTDOC_H__1DBA7F19_F48A_48FA_95D1_FF754CB56372__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEditSoftDoc : public CDocument
{
protected: // create from serialization only
	CEditSoftDoc();
	DECLARE_DYNCREATE(CEditSoftDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditSoftDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEditSoftDoc();
	COLORREF m_bkColor;
	COLORREF m_txtColor;
	CFont m_Font;
	LOGFONT m_lf;
	BOOL bOpenFlag;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEditSoftDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITSOFTDOC_H__1DBA7F19_F48A_48FA_95D1_FF754CB56372__INCLUDED_)
