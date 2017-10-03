// studentbaView.h : interface of the CStudentbaView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENTBAVIEW_H__235E70CF_0E22_4A1A_881D_D6E43D6FF2F7__INCLUDED_)
#define AFX_STUDENTBAVIEW_H__235E70CF_0E22_4A1A_881D_D6E43D6FF2F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStudentbaSet;

class CStudentbaView : public CRecordView
{
protected: // create from serialization only
	CStudentbaView();
	DECLARE_DYNCREATE(CStudentbaView)

public:
	//{{AFX_DATA(CStudentbaView)
	enum { IDD = IDD_STUDENTBA_FORM };
	CStudentbaSet* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	CStudentbaDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentbaView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnMove(UINT nIDMoveCommand);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStudentbaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
protected:
	BOOL m_Add;

// Generated message map functions
protected:
	//{{AFX_MSG(CStudentbaView)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in studentbaView.cpp
inline CStudentbaDoc* CStudentbaView::GetDocument()
   { return (CStudentbaDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTBAVIEW_H__235E70CF_0E22_4A1A_881D_D6E43D6FF2F7__INCLUDED_)
