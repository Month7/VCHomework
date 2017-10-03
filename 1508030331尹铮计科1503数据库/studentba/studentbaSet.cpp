// studentbaSet.cpp : implementation of the CStudentbaSet class
//

#include "stdafx.h"
#include "studentba.h"
#include "studentbaSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentbaSet implementation

IMPLEMENT_DYNAMIC(CStudentbaSet, CRecordset)

CStudentbaSet::CStudentbaSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStudentbaSet)
	m_column1 = 0;
	m_Num = _T("");
	m_Name = _T("");
	m_NormalScore = 0;
	m_MidScore = 0;
	m_FinalScore = 0;
	m_SumScore = 0;
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CStudentbaSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=student");
}

CString CStudentbaSet::GetDefaultSQL()
{
	return _T("[score]");
}

void CStudentbaSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStudentbaSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[±àºÅ]"), m_column1);
	RFX_Text(pFX, _T("[Num]"), m_Num);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Long(pFX, _T("[NormalScore]"), m_NormalScore);
	RFX_Long(pFX, _T("[MidScore]"), m_MidScore);
	RFX_Long(pFX, _T("[FinalScore]"), m_FinalScore);
	RFX_Long(pFX, _T("[SumScore]"), m_SumScore);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStudentbaSet diagnostics

#ifdef _DEBUG
void CStudentbaSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudentbaSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
