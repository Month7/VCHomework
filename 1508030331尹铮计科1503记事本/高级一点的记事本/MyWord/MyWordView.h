// MyWordView.h : interface of the CMyWordView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYWORDVIEW_H__6127644A_DC59_45EC_9C19_482E2F823ACA__INCLUDED_)
#define AFX_MYWORDVIEW_H__6127644A_DC59_45EC_9C19_482E2F823ACA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyWordCntrItem;

class CMyWordView : public CRichEditView
{
protected: // create from serialization only
	CMyWordView();
	DECLARE_DYNCREATE(CMyWordView)

// Attributes
public:
	CMyWordDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWordView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyWordView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyWordView)
	afx_msg void OnDestroy();
	afx_msg void OnFormatFont();
	afx_msg void OnBkcolor();
	afx_msg void OnLeft();
	afx_msg void OnRight();
	afx_msg void OnCenter();
	afx_msg void On2();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTxtColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyWordView.cpp
inline CMyWordDoc* CMyWordView::GetDocument()
   { return (CMyWordDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWORDVIEW_H__6127644A_DC59_45EC_9C19_482E2F823ACA__INCLUDED_)
