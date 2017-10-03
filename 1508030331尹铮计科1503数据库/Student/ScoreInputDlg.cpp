// ScoreInputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "ScoreInputDlg.h"
#include "StudentSet1.h"
#include "Score.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoreInputDlg dialog


CScoreInputDlg::CScoreInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScoreInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScoreInputDlg)
	m_strClass = _T("");
	m_strTime = _T("");
	m_strExamclass = _T("");
	m_strSubject = _T("");
	//}}AFX_DATA_INIT
}


void CScoreInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScoreInputDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Text(pDX, IDC_CLASS1, m_strClass);
	DDX_Text(pDX, IDC_TIME, m_strTime);
	DDX_Text(pDX, IDC_EXAMCLASS, m_strExamclass);
	DDX_Text(pDX, IDC_SUBJECT, m_strSubject);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScoreInputDlg, CDialog)
	//{{AFX_MSG_MAP(CScoreInputDlg)
	ON_BN_CLICKED(IDC_BUTTON_INPUT, OnButtonInput)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoreInputDlg message handlers

void CScoreInputDlg::OnButtonInput() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_strClass.IsEmpty())
	{
		AfxMessageBox(" 请输入班级");
		return;
	}
	if(m_strTime.IsEmpty())
	{
		AfxMessageBox(" 请输入考试时间段");
		return;
	}
	if(m_strExamclass.IsEmpty())
	{
		AfxMessageBox(" 请输入考试类型");
		return;
	}
	if(m_strSubject.IsEmpty())
	{
		AfxMessageBox(" 请输入考试科目");
		return;
	}
	CString strSQL;
	strSQL.Format("select * from score where class = '%s' and time = '%s' and type = '%s'and subject = '%s'",m_strClass,m_strTime,m_strExamclass,m_strSubject);
		if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			MessageBox(" 打开数据库失败!"," 数据库错误",MB_OK);
			return ;
		}
		if(m_recordset.GetRecordCount()==0)
		{
			m_recordset.Close();
			CreateScoreTable();
		}
		else
		{
			m_recordset.Close();
		}
	RefreshData(strSQL);
}

void CScoreInputDlg::CreateScoreTable()
{
	CString strSQL;
	CStudentSet1 StudentSet;
	strSQL.Format("select * from student where class = '%s'",m_strClass);
	if(!StudentSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox(" 打开数据库失败!"," 数据库错误",MB_OK);
		return ;
	}
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		MessageBox(" 打开数据库失败!"," 数据库错误",MB_OK);
		return ;
	}
	while(!StudentSet.IsEOF())
	{
		m_recordset.AddNew();
		m_recordset.m_code = StudentSet.m_code;
		m_recordset.m_class = m_strClass;
		m_recordset.m_name = StudentSet.m_name;
		m_recordset.m_subject = m_strSubject;
		m_recordset.m_time = m_strTime;
		m_recordset.m_type = m_strExamclass;
		m_recordset.Update();
		StudentSet.MoveNext();
	}
	m_recordset.Close();
	StudentSet.Close();
}

void CScoreInputDlg::RefreshData(CString strSQL)
{
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);
	UpdateData(TRUE);
if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
{
	MessageBox(" 打开数据库失败!"," 数据库错误",MB_OK);
	return ;
}
int i=0;
char buffer[20];
while(!m_recordset.IsEOF())
{
	_ltoa(m_recordset.m_ID,buffer,10);
	m_ctrList.InsertItem(i,buffer);
	m_ctrList.SetItemText(i,1,m_recordset.m_code);
	m_ctrList.SetItemText(i,2,m_recordset.m_name);
	m_ctrList.SetItemText(i,3,m_recordset.m_subject);
	_ltoa(m_recordset.m_score,buffer,10);
	m_ctrList.SetItemText(i,4,buffer);
	_ltoa(m_recordset.m_makeup_score,buffer,10);
	m_ctrList.SetItemText(i,5,buffer);
	m_ctrList.SetItemText(i,6,m_recordset.m_absent);
	i++;
	m_recordset.MoveNext();
}
m_recordset.Close();
m_ctrList.SetRedraw(TRUE);
}

BOOL CScoreInputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	CString strSQL;
	// 初始化成绩列表
	m_ctrList.InsertColumn(0," 序号");
	m_ctrList.InsertColumn(1," 学号");
	m_ctrList.InsertColumn(2," 姓名");
	m_ctrList.InsertColumn(3," 科目");
	m_ctrList.InsertColumn(4," 成绩");
	m_ctrList.InsertColumn(5," 补考成绩");
	m_ctrList.InsertColumn(6," 缺考标志");
	m_ctrList.SetColumnWidth(0,60);
	m_ctrList.SetColumnWidth(1,80);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,100);
	m_ctrList.SetColumnWidth(4,80);
	m_ctrList.SetColumnWidth(5,80);
	m_ctrList.SetColumnWidth(6,60);
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CScoreInputDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString strSQL;
	long score=0,makeup=0;
	CScore Dlg;
	UpdateData(TRUE);
	int i = m_ctrList.GetSelectionMark();
	if(i<0) return;
if(IDOK!=Dlg.DoModal())
{
	return;
}
if(!Dlg.m_strScore.IsEmpty())
score = atol(Dlg.m_strScore);
if(!Dlg.m_strMakeup.IsEmpty())
makeup = atol(Dlg.m_strMakeup);
strSQL.Format("select * from score where ID=%s",m_ctrList.GetItemText(i,0));
if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
{
	MessageBox(" 打开数据库失败!"," 数据库错误",MB_OK);
	return ;
}
m_recordset.Edit();
if(Dlg.m_bAbsent)
m_recordset.m_absent = " 是";
m_recordset.m_score = score;
m_recordset.m_makeup_score = makeup;
m_recordset.Update();
char buffer[20];
_ltoa(m_recordset.m_score,buffer,10);
m_ctrList.SetItemText(i,4,buffer);
_ltoa(m_recordset.m_makeup_score,buffer,10);
m_ctrList.SetItemText(i,5,buffer);
m_ctrList.SetItemText(i,6,m_recordset.m_absent);
m_recordset.Close();
	*pResult = 0;
}
