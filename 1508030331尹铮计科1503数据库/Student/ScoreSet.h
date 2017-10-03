#if !defined(AFX_SCORESET_H__2AF8CAE5_42A8_44ED_AFA1_7F59D7BD4620__INCLUDED_)
#define AFX_SCORESET_H__2AF8CAE5_42A8_44ED_AFA1_7F59D7BD4620__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoreSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScoreSet recordset

class CScoreSet : public CRecordset
{
public:
	CScoreSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CScoreSet)

// Field/Param Data
	//{{AFX_FIELD(CScoreSet, CRecordset)
	long	m_ID;
	CString	m_class;
	CString	m_time;
	CString	m_code;
	CString	m_name;
	CString	m_subject;
	CString	m_type;
 	long	m_score;
 	long	m_makeup_score;
	CString	m_absent;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoreSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCORESET_H__2AF8CAE5_42A8_44ED_AFA1_7F59D7BD4620__INCLUDED_)
