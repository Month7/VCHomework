#if !defined(AFX_STUDENTSET1_H__34F86FD0_4B01_463A_BB29_810318B8912B__INCLUDED_)
#define AFX_STUDENTSET1_H__34F86FD0_4B01_463A_BB29_810318B8912B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentSet1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentSet1 recordset

class CStudentSet1 : public CRecordset
{
public:
	CStudentSet1(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStudentSet1)

// Field/Param Data
	//{{AFX_FIELD(CStudentSet1, CRecordset)
	CString	m_code;
	CString	m_name;
	CString	m_sex;
	CTime	m_birthday;
	CString	m_address;
	CString	m_phone;
	CString	m_department;
	CString	m_major;
	CString	m_class;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentSet1)
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

#endif // !defined(AFX_STUDENTSET1_H__34F86FD0_4B01_463A_BB29_810318B8912B__INCLUDED_)
