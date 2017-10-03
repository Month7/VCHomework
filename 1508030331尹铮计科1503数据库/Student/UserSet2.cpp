// UserSet2.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "UserSet2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserSet2

IMPLEMENT_DYNAMIC(CUserSet2, CRecordset)

CUserSet2::CUserSet2(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CUserSet2)
	m_user = _T("");
	m_password = _T("");
	m_idAdmin = FALSE;
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CUserSet2::GetDefaultConnect()
{
	return _T("ODBC;DSN=stu");
}

CString CUserSet2::GetDefaultSQL()
{
	return _T("[user]");
}

void CUserSet2::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CUserSet2)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[user]"), m_user);
	RFX_Text(pFX, _T("[password]"), m_password);
	RFX_Bool(pFX, _T("[idAdmin]"), m_idAdmin);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CUserSet2 diagnostics

#ifdef _DEBUG
void CUserSet2::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUserSet2::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
