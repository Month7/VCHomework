// StudentView.h : interface of the CStudentView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENTVIEW_H__CA7CF5C8_1EDA_41E3_894C_C02EA4CE9114__INCLUDED_)
#define AFX_STUDENTVIEW_H__CA7CF5C8_1EDA_41E3_894C_C02EA4CE9114__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStudentView : public CView
{
protected: // create from serialization only
	CStudentView();
	DECLARE_DYNCREATE(CStudentView)

// Attributes
public:
	CStudentDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStudentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStudentView)
	afx_msg void OnPaint();
	afx_msg void OnUserMsg();
	afx_msg void OnStuMsg();
	afx_msg void OnScoreInput();
	afx_msg void OnScoreSearch();
	afx_msg void OnWriter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in StudentView.cpp
inline CStudentDoc* CStudentView::GetDocument()
   { return (CStudentDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTVIEW_H__CA7CF5C8_1EDA_41E3_894C_C02EA4CE9114__INCLUDED_)
