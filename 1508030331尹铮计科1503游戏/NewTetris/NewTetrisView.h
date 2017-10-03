// NewTetrisView.h : interface of the CNewTetrisView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWTETRISVIEW_H__527EF8F0_922C_4A32_8953_881B51379BCE__INCLUDED_)
#define AFX_NEWTETRISVIEW_H__527EF8F0_922C_4A32_8953_881B51379BCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "bin.h"
#include "brick.h"

class CNewTetrisView : public CView
{
protected: // create from serialization only
	CNewTetrisView();
	DECLARE_DYNCREATE(CNewTetrisView)

// Attributes
public:
	CNewTetrisDoc* GetDocument();
	COLORREF GetLightColor(COLORREF m_crBody);
	COLORREF GetDarkColor(COLORREF m_crBody);
//////////////// ��� 1 ///////////////
	CBin*bin;	//������Ϸ���ο�ָ��
	CBrick*activeBrick;	//����ָ��ǰ����ש���ָ��
	int gameOver;	//�ж���Ϸ�Ƿ����
	int brickInFlight;		//�ж�ש���Ƿ�������״̬
	int brickType;	//ש�����
	unsigned int initOrientation;	//��ʼ״̬ 
	int notCollide;	//��ͻ��
	unsigned int numLines;	//�������� 
	unsigned char**outputImage;
	int difficulty;	//�����Ѷ�
//////////////// ��� 2 ///////////////
	CBin*bin2;	//������Ϸ���ο�ָ��
	CBrick*activeBrick2;	//����ָ��ǰ����ש���ָ��
	int gameOver2;	//�ж���Ϸ�Ƿ����
	int brickInFlight2;		//�ж�ש���Ƿ�������״̬
	int brickType2;	//ש�����
	unsigned int initOrientation2;	//��ʼ״̬ 
	int notCollide2;	//��ͻ��
	unsigned int numLines2;	//�������� 
	unsigned char**outputImage2;
	int difficulty2;	//�����Ѷ�
	void DrawImage(CBin *bin,CBin *bin2,unsigned char** image,unsigned char** image2,unsigned char **imageY1,
							   unsigned char **imageY2,CDC *pDC); 
	////////  Ԥ��ʾ����1  ////////
	CBin *binY1;  //������Ϸ���ο�ָ��
	CBrick *activeBrickY1;   //����ָ��ǰ����ש���ָ��
	int bType1;    //ש�����
	unsigned int iOrient1;  //��ʼ״̬
	unsigned char **outputImageY1;  
	////////  Ԥ��ʾ����2  ////////
	CBin *binY2;  //������Ϸ���ο�ָ��
	CBrick *activeBrickY2;   //����ָ��ǰ����ש���ָ��
	int bType2;    //ש�����
	unsigned int iOrient2;  //��ʼ״̬
	unsigned char **outputImageY2;  
	int flag1,flag2;      //�Ƿ����䣬����Ԥ��ʾ
/*	int p;*/         //��ͣ
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewTetrisView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNewTetrisView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNewTetrisView)
	afx_msg void OnGameStart();
	afx_msg void OnDiffEasy();
	afx_msg void OnDiffMid();
	afx_msg void OnDiffSup();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnHelp1();
	afx_msg void OnPause();
	afx_msg void OnRestart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NewTetrisView.cpp
inline CNewTetrisDoc* CNewTetrisView::GetDocument()
   { return (CNewTetrisDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWTETRISVIEW_H__527EF8F0_922C_4A32_8953_881B51379BCE__INCLUDED_)
