// studentbaSet.h : interface of the CStudentbaSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENTBASET_H__19CEE337_5EA4_4BED_AE23_0D28B25C680C__INCLUDED_)
#define AFX_STUDENTBASET_H__19CEE337_5EA4_4BED_AE23_0D28B25C680C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStudentbaSet : public CRecordset
{
public:
	CStudentbaSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStudentbaSet)

// Field/Param Data
	//{{AFX_FIELD(CStudentbaSet, CRecordset)
	long	m_column1;
	CString	m_Num;
	CString	m_Name;
	long	m_NormalScore;
	long	m_MidScore;
	long	m_FinalScore;
	long	m_SumScore;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentbaSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTBASET_H__19CEE337_5EA4_4BED_AE23_0D28B25C680C__INCLUDED_)

