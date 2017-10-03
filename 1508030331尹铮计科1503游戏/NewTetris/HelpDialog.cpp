// HelpDialog.cpp : implementation file
//

#include "stdafx.h"
#include "NewTetris.h"
#include "HelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// HelpDialog dialog


HelpDialog::HelpDialog(CWnd* pParent /*=NULL*/)
	: CDialog(HelpDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(HelpDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void HelpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(HelpDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(HelpDialog, CDialog)
	//{{AFX_MSG_MAP(HelpDialog)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// HelpDialog message handlers

BOOL HelpDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_LINK)->GetWindowRect(&m_pRectLink); //����̬�ı�����Ļ��������m��pRectLink��
	ScreenToClient(&m_pRectLink);//����Ļ����ת��Ϊ�ͻ�����
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void HelpDialog::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//������������ھ�̬�ı���ʱ����������С��״
	if (point.x>m_pRectLink.left&&point.x<m_pRectLink.right&&point.y>m_pRectLink.top&&point.y<m_pRectLink.bottom)
		
		//�˴�����ж������㷨
		
	{ 
		HCURSOR hCursor;
		hCursor=AfxGetApp()->LoadCursor(IDC_HAND);  
		//�������ΪС��״
		SetCursor(hCursor);
	}
	//���������������Ĭ��(��ͷ)�����״,һ������ƿ��󴰿ڻ��Զ��ָ�Ĭ�������״�����������
//	if (...)//�˴����������겻�ھ�̬�ı����������㷨,�����ɲ���
		
// 	{ 
// 		hCURSOR hCursor;
// 	
// 	hCursor=AfxGetApp()->LoadStandardCursor(IDC_IBEAM);
// 	
// 	//�������ΪĬ��ֵ(��ͷ)
// 	
// SetCursor(hCursor); }
	CDialog::OnMouseMove(nFlags, point);
}

void HelpDialog::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (point.x>m_pRectLink.left&&point.x<m_pRectLink.right&&point.y>m_pRectLink.top&&point.y<m_pRectLink.bottom)
		
		//�˴�����ж������㷨
		
	{ if (nFlags==MK_LBUTTON)//����������
	
	{ //Ϊ�������Ч�����˴��������ϱ任�����״�Ĵ���
		
		ShellExecute(0, NULL, "http://blog.csdn.net/qq_29187355?", NULL,NULL, SW_NORMAL);
		//Ҳ������ӵ����ʼ�������
	}
	}
	CDialog::OnLButtonDown(nFlags, point);
}
