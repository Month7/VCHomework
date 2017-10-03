// ScoreSet.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "ScoreSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoreSet

IMPLEMENT_DYNAMIC(CScoreSet, CRecordset)

CScoreSet::CScoreSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CScoreSet)
	m_ID = 0;
	m_class = _T("");
	m_time = _T("");
	m_code = _T("");
	m_name = _T("");
	m_subject = _T("");
	m_type = _T("");
	m_score = 0;
	m_makeup_score = 0;
	m_absent = _T("");
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CScoreSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=stu");
}

CString CScoreSet::GetDefaultSQL()
{
	return _T("[score]");
}

void CScoreSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CScoreSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[class]"), m_class);
	RFX_Text(pFX, _T("[time]"), m_time);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[subject]"), m_subject);
	RFX_Text(pFX, _T("[type]"), m_type);
	RFX_Long(pFX, _T("[score]"), m_score);
	RFX_Long(pFX, _T("[makeup_score]"), m_makeup_score);
	RFX_Text(pFX, _T("[absent]"), m_absent);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CScoreSet diagnostics

#ifdef _DEBUG
void CScoreSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CScoreSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
