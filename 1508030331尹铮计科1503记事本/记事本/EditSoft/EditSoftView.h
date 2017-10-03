// EditSoftView.h : interface of the CEditSoftView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDITSOFTVIEW_H__E42A9A10_88E2_4C7C_98A5_146F70AC976E__INCLUDED_)
#define AFX_EDITSOFTVIEW_H__E42A9A10_88E2_4C7C_98A5_146F70AC976E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEditSoftView : public CEditView
{
protected: // create from serialization only
	CEditSoftView();
	DECLARE_DYNCREATE(CEditSoftView)

// Attributes
public:
	CEditSoftDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditSoftView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEditSoftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEditSoftView)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnFont();
	afx_msg void OnTxtcolor();
	afx_msg void OnBkcolor();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnLeft();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EditSoftView.cpp
inline CEditSoftDoc* CEditSoftView::GetDocument()
   { return (CEditSoftDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITSOFTVIEW_H__E42A9A10_88E2_4C7C_98A5_146F70AC976E__INCLUDED_)
