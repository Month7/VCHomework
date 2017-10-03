// StudentSet1.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "StudentSet1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentSet1

IMPLEMENT_DYNAMIC(CStudentSet1, CRecordset)

CStudentSet1::CStudentSet1(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStudentSet1)
	m_code = _T("");
	m_name = _T("");
	m_sex = _T("");
	m_address = _T("");
	m_phone = _T("");
	m_department = _T("");
	m_major = _T("");
	m_class = _T("");
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CStudentSet1::GetDefaultConnect()
{
	return _T("ODBC;DSN=stu");
}

CString CStudentSet1::GetDefaultSQL()
{
	return _T("[student]");
}

void CStudentSet1::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStudentSet1)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[sex]"), m_sex);
	RFX_Date(pFX, _T("[birthday]"), m_birthday);
	RFX_Text(pFX, _T("[address]"), m_address);
	RFX_Text(pFX, _T("[phone]"), m_phone);
	RFX_Text(pFX, _T("[department]"), m_department);
	RFX_Text(pFX, _T("[major]"), m_major);
	RFX_Text(pFX, _T("[class]"), m_class);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStudentSet1 diagnostics

#ifdef _DEBUG
void CStudentSet1::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudentSet1::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
