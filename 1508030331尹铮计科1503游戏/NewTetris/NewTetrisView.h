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
//////////////// 面板 1 ///////////////
	CBin*bin;	//定义游戏矩形框指针
	CBrick*activeBrick;	//定义指向当前下落砖块的指针
	int gameOver;	//判断游戏是否结束
	int brickInFlight;		//判断砖块是否处于下落状态
	int brickType;	//砖块类别
	unsigned int initOrientation;	//初始状态 
	int notCollide;	//冲突否
	unsigned int numLines;	//消的行数 
	unsigned char**outputImage;
	int difficulty;	//定义难度
//////////////// 面板 2 ///////////////
	CBin*bin2;	//定义游戏矩形框指针
	CBrick*activeBrick2;	//定义指向当前下落砖块的指针
	int gameOver2;	//判断游戏是否结束
	int brickInFlight2;		//判断砖块是否处于下落状态
	int brickType2;	//砖块类别
	unsigned int initOrientation2;	//初始状态 
	int notCollide2;	//冲突否
	unsigned int numLines2;	//消的行数 
	unsigned char**outputImage2;
	int difficulty2;	//定义难度
	void DrawImage(CBin *bin,CBin *bin2,unsigned char** image,unsigned char** image2,unsigned char **imageY1,
							   unsigned char **imageY2,CDC *pDC); 
	////////  预显示定义1  ////////
	CBin *binY1;  //定义游戏矩形框指针
	CBrick *activeBrickY1;   //定义指向当前下落砖块的指针
	int bType1;    //砖块类别
	unsigned int iOrient1;  //初始状态
	unsigned char **outputImageY1;  
	////////  预显示定义2  ////////
	CBin *binY2;  //定义游戏矩形框指针
	CBrick *activeBrickY2;   //定义指向当前下落砖块的指针
	int bType2;    //砖块类别
	unsigned int iOrient2;  //初始状态
	unsigned char **outputImageY2;  
	int flag1,flag2;      //是否下落，用于预显示
/*	int p;*/         //暂停
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
