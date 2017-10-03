#if !defined(AFX_USERSET2_H__530F3A20_7728_447B_A07C_7C38DBC88E01__INCLUDED_)
#define AFX_USERSET2_H__530F3A20_7728_447B_A07C_7C38DBC88E01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserSet2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserSet2 recordset

class CUserSet2 : public CRecordset
{
public:
	CUserSet2(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CUserSet2)

// Field/Param Data
	//{{AFX_FIELD(CUserSet2, CRecordset)
	CString	m_user;
	CString	m_password;
	BOOL	m_idAdmin;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserSet2)
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

#endif // !defined(AFX_USERSET2_H__530F3A20_7728_447B_A07C_7C38DBC88E01__INCLUDED_)
