// SEARCH.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "SEARCH.h"
#include "SCORE_UP_Dialog.h"
#include "Score.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SEARCH dialog


SEARCH::SEARCH(CWnd* pParent /*=NULL*/)
	: CDialog(SEARCH::IDD, pParent)
{
	//{{AFX_DATA_INIT(SEARCH)
	m_strClass = _T("");
	m_strName = _T("");
	m_strSubject = _T("");
	//}}AFX_DATA_INIT
}


void SEARCH::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SEARCH)
	DDX_Control(pDX, IDC_SE_SUB, m_ctrSubject);
	DDX_Control(pDX, IDC_SE_NAME, m_ctrName);
	DDX_Control(pDX, IDC_SE_CLASS, m_ctrClass);
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Text(pDX, IDC_SE_CLASS, m_strClass);
	DDX_Text(pDX, IDC_SE_NAME, m_strName);
	DDX_Text(pDX, IDC_SE_SUB, m_strSubject);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SEARCH, CDialog)
	//{{AFX_MSG_MAP(SEARCH)
	ON_BN_CLICKED(IDC_BnClickedButtonSearch, OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON1_DELETE, OnButton1Delete)
	ON_BN_CLICKED(IDC_BUTTON1_MODIFY, OnButton1Modify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SEARCH message handlers

BOOL SEARCH::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
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
	CString strSQL="select * from score";
	RefreshData(strSQL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void SEARCH::RefreshData(CString strSQL)
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

void SEARCH::OnBnClickedButtonSearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString strSQL,strTemp;
	strTemp="";
	BOOL bHaveCon = FALSE;
	if(m_strSubject!="")
	{
		strSQL.Format("select * from score where subject = '%s' ",m_strSubject);
		bHaveCon = TRUE;
	}
	if(m_strName!="")
	{
		if(bHaveCon)
		{
			strTemp.Format(" name = '%s' ",m_strName);
			strSQL=strSQL+ " and " + strTemp;
		}
		else
		{
			strSQL.Format("select * from score where name = '%s' ",m_strName);
		}
		bHaveCon=TRUE;
	}
if(m_strClass!="")
{
	if(bHaveCon)
	{
		strTemp.Format(" class = '%s' ",m_strClass);
		strSQL=strSQL+ " and " + strTemp;
	}
	else
	{
		strSQL.Format("select * from score where class = '%s' ",m_strClass);
	}
	bHaveCon=TRUE;
}
if(!bHaveCon)
{
	strSQL="select * from score";
}
	RefreshData(strSQL);
}

void SEARCH::OnButton1Delete() 
{
	// TODO: Add your control notification handler code here
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		AfxMessageBox(" 请选择一条记录进行查看！");
		return;
	}
	CString strSQL;
	/*strSQL.Format("select * from score where ID = '%s'",m_ctrList.GetItemText(i,0));*/
/*	strSQL.Format("select * from score where ID = '%d'",m_ctrList.GetSelectionMark());*/
	strSQL.Format("select * from score where ID=%s",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		AfxMessageBox(" 打开数据库失败!");
		return ;
	}
	m_recordset.Delete();
	m_recordset.Close();
	strSQL= "select * from score";
	RefreshData(strSQL);
}

void SEARCH::OnButton1Modify() 
{
	// TODO: Add your control notification handler code here
	SCORE_UP_Dialog Dlg;
	UpdateData();
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		AfxMessageBox(" 请选择一条记录进行修改！");
		return;
	}
/*	Dlg.m_strCode=m_ctrList.GetItemText(i,0);*/
/*	Dlg.m_ID=m_ctrList.GetItemText(i,0);*/
	if(IDOK==Dlg.DoModal())
	{// 修改记录
		CString strSQL;
	/*	strSQL.Format("select * from student where code = '%s'",Dlg.m_strCode);*/
		strSQL.Format("select * from score where ID=%s",m_ctrList.GetItemText(i,0));
/*		strSQL.Format("select * from score where ID=%s",Dlg.m_ID);*/
		if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			AfxMessageBox(" 打开数据库失败!");
			return ;
		}
		m_recordset.Edit();
/*		CString m_str_Score;*/
// 		m_recordset.m_code =Dlg.m_strCode ;
// 		m_recordset.m_name =Dlg.m_strName ;
// 		m_recordset.m_sex =Dlg.m_strSex ;
// 		m_recordset.m_birthday =Dlg.m_tmBirth ;
// 		m_recordset.m_department =Dlg.m_strDepartment ;
// 		m_recordset.m_major =Dlg.m_strMajor ;
//		m_recordset.m_class =Dlg.m_strClass ;
// 		m_recordset.m_phone =Dlg.m_strPhone ;
// 		m_recordset.m_address =Dlg.m_strAddress ;
/*		m_recordset.m_ID=Dlg.Dlg.m_ID;*/
/*		m_recordset.m_ID=m_ctrList.GetItemText(i,0);*/
/*		itoa(Dlg.m_strSCore,m_strScore,10);*/
		m_recordset.m_score=Dlg.m_str_Score;
		m_recordset.m_makeup_score=Dlg.m_str_Makeup;
		m_recordset.Update();
		m_recordset.Close();
		strSQL= "select * from score ";
		RefreshData(strSQL);
	}
}
