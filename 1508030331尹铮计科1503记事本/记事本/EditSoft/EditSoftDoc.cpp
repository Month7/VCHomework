// EditSoftDoc.cpp : implementation of the CEditSoftDoc class
//

#include "stdafx.h"
#include "EditSoft.h"

#include "EditSoftDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditSoftDoc

IMPLEMENT_DYNCREATE(CEditSoftDoc, CDocument)

BEGIN_MESSAGE_MAP(CEditSoftDoc, CDocument)
	//{{AFX_MSG_MAP(CEditSoftDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditSoftDoc construction/destruction

CEditSoftDoc::CEditSoftDoc()
{
	// TODO: add one-time construction code here
	m_bkColor=RGB(0,255,0);
	m_txtColor=RGB(0,0,0);
	bOpenFlag=FALSE;
}

CEditSoftDoc::~CEditSoftDoc()
{
}

BOOL CEditSoftDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEditSoftDoc serialization

void CEditSoftDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar<<m_bkColor; 
		ar<<m_txtColor; 
		ar<<m_lf.lfHeight;
		ar<<m_lf.lfWidth; 
		ar<<m_lf.lfEscapement; 
		ar<<m_lf.lfOrientation;
		ar<<m_lf.lfWeight; 
		ar<<m_lf.lfItalic; 
		ar<<m_lf.lfUnderline;
		ar<<m_lf.lfStrikeOut; 
		ar<<m_lf.lfCharSet; 
		ar<<m_lf.lfOutPrecision; 
		ar<<m_lf.lfClipPrecision; 
		ar<<m_lf.lfQuality; 
		ar<<m_lf.lfPitchAndFamily;
		CString FaceName=m_lf.lfFaceName; 
		ar<<FaceName;
	}
	else
	{
		// TODO: add loading code here 
		ar>>m_bkColor; 
		ar>>m_txtColor; 
		ar>>m_lf.lfHeight;
		ar>>m_lf.lfWidth;
		ar>>m_lf.lfEscapement; 
		ar>>m_lf.lfOrientation; 
		ar>>m_lf.lfWeight; 
		ar>>m_lf.lfItalic; 
		ar>>m_lf.lfUnderline;
		ar>>m_lf.lfStrikeOut; 
		ar>>m_lf.lfCharSet; 
		ar>>m_lf.lfOutPrecision; 
		ar>>m_lf.lfClipPrecision;
		ar>>m_lf.lfQuality; 
		ar>>m_lf.lfPitchAndFamily; 
		CString FaceName;
		ar>>FaceName;
		strcpy(m_lf.lfFaceName,FaceName); 
		m_Font.DeleteObject(); 
		m_Font.CreateFontIndirect(&m_lf); 
		bOpenFlag=TRUE;

	}
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);

}

/////////////////////////////////////////////////////////////////////////////
// CEditSoftDoc diagnostics

#ifdef _DEBUG
void CEditSoftDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEditSoftDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEditSoftDoc commands
