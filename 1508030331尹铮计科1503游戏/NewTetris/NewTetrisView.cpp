// NewTetrisView.cpp : implementation of the CNewTetrisView class
//

#include "stdafx.h"
#include "NewTetris.h"

#include "NewTetrisDoc.h"
#include "NewTetrisView.h"
#include "HelpDialog.h"
#include "mmsystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define NUM_BRICK_TYPES	7
#define NUM_TURNS_PER_STEP	3
#define COLOR_CHANGE 60
/////////////////////////////////////////////////////////////////////////////
// CNewTetrisView

IMPLEMENT_DYNCREATE(CNewTetrisView, CView)

BEGIN_MESSAGE_MAP(CNewTetrisView, CView)
	//{{AFX_MSG_MAP(CNewTetrisView)
	ON_COMMAND(ID_Game_Start, OnGameStart)
	ON_COMMAND(ID_DIFF_EASY, OnDiffEasy)
	ON_COMMAND(ID_DIFF_MID, OnDiffMid)
	ON_COMMAND(ID_DIFF_SUP, OnDiffSup)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_COMMAND(IDD_HELP1, OnHelp1)
	ON_COMMAND(IDD_Pause, OnPause)
	ON_COMMAND(IDD_Restart, OnRestart)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewTetrisView construction/destruction

CNewTetrisView::CNewTetrisView()
{
	// TODO: add construction code here
//////////////// 面板 1 ///////////////
	bin=new CBin(10,20); 
	activeBrick=NULL; 
	gameOver=1;
	brickInFlight=1; 
	brickType=0; 
	initOrientation=0; 
	notCollide=0; 
	numLines=0; 
	difficulty=500;
	outputImage = new unsigned char* [20]; 
	for (int i=0; i<20; i++) 
	{
		outputImage[i] = new unsigned char [10];
	}
	bin->getImage(outputImage);
//////////////// 面板 2 ///////////////
	bin2=new CBin(10,20); 
	activeBrick2=NULL; 
	gameOver2=1;
	brickInFlight2=1; 
	brickType2=0; 
	initOrientation2=0; 
	notCollide2=0; 
	numLines2=0; 
	difficulty2=500;
	outputImage2 = new unsigned char* [20]; 
	for (int j=0; j<20; j++) 
	{
		outputImage2[j] = new unsigned char [10];
	}
	bin2->getImage(outputImage2);
	flag1 = 1;//预显示，第一次下落
	flag2 = 1;
	////////  预显示1  ////////
	binY1 = new CBin(10,20);//新建一个类
	activeBrickY1 = NULL;   //定义指向当前下落砖块的指针
	bType1 = 0;    //砖块类别
	iOrient1 = 0;  //初始状态
	outputImageY1 = new unsigned char* [20];//开辟一个指针数组
	for (i = 0; i < 20; ++i)
	{
		outputImageY1[i] = new unsigned char[10];//开辟空间
	}
	binY1->getImage(outputImageY1);//将印象空间拷贝进image1数组中(存放固定块)
	
	////////  预显示2  ////////
	binY2 = new CBin(10,20);//新建一个类
	activeBrickY2 = NULL;   //定义指向当前下落砖块的指针
	bType2 = 0;    //砖块类别
	iOrient2 = 0;  //初始状态
	outputImageY2 = new unsigned char* [20];//开辟一个指针数组
	for (i = 0; i < 20; ++i)
	{
		outputImageY2[i] = new unsigned char[10];//开辟空间
	}
	binY2->getImage(outputImageY2);//将印象空间拷贝进image1数组中(存放固定块)
/*	p=0;*/
}

CNewTetrisView::~CNewTetrisView()
{
	delete bin;
	delete bin2;
}

BOOL CNewTetrisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNewTetrisView drawing

void CNewTetrisView::OnDraw(CDC* pDC)
{
CNewTetrisDoc* pDoc = GetDocument(); 
	ASSERT_VALID(pDoc);
// 	pDC->Rectangle(0,0,200,400); 
// 	char buf[100];
// 	sprintf(buf,"玩家一：分数：%d",numLines*10);
// 	pDC->TextOut(200,20,buf); 
// 	pDC->Rectangle(350,0,550,400); 
// 	char buf2[100];
// 	sprintf(buf2,"玩家二：分数：%d",numLines2*10);
// 		pDC->TextOut(550,20,buf2); 
// 	DrawImage(bin,bin2,outputImage,outputImage2,pDC);
	int m_nWidth,m_nHeight; 
	CDC m_memDC; 
	CBitmap m_memBmp;
/*	m_memBmp.LoadBitmap(IDB_BITMAP2); //装载位图*/
	//1.用于映射屏幕的内存设备环境
	//获取游戏窗口的大小用于下面设置内存位图的尺寸
	CRect windowRect;
	GetClientRect(&windowRect); 
	m_nWidth = windowRect.Width(); 
	m_nHeight = windowRect.Height();
	//内存设备环境与屏幕设备环境关联（兼容）
	m_memDC.CreateCompatibleDC(pDC);
	//内存位图与与屏幕关联(兼容),大小为游戏窗口的尺寸
/*	m_memBmp.CreateCompatibleBitmap(pDC,m_nWidth,m_nHeight); */
	m_memDC.FillSolidRect(windowRect,RGB(0,0,0));
	//内存设备环境与内存位图关联，以便通过m_memDC 在内存位图上作画
	m_memDC.SelectObject(&m_memBmp); 
	DrawImage(bin,bin2,outputImage,outputImage2,outputImageY1,outputImageY2,pDC);
	//把内存DC 上的图形拷贝到电脑屏幕
	pDC->BitBlt(0,0,m_nWidth,m_nHeight,&m_memDC,0,0,SRCCOPY);
	m_memDC.DeleteDC(); //删除DC
	m_memBmp.DeleteObject(); //删除位图

}

/////////////////////////////////////////////////////////////////////////////
// CNewTetrisView printing

BOOL CNewTetrisView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNewTetrisView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNewTetrisView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNewTetrisView diagnostics

#ifdef _DEBUG
void CNewTetrisView::AssertValid() const
{
	CView::AssertValid();
}

void CNewTetrisView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNewTetrisDoc* CNewTetrisView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNewTetrisDoc)));
	return (CNewTetrisDoc*)m_pDocument;
}
void CNewTetrisView::DrawImage(CBin *bin,CBin *bin2,unsigned char** image,unsigned char** image2,unsigned char **imageY1,
							   unsigned char **imageY2,CDC *pDC)
{
	unsigned int width,i,j; unsigned int height; width=bin->getWidth(); height=bin->getHeight(); 
	int nSize = 20; //砖块大小
	CRect rect; 
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP3); //加载位图
	CBrush brush;  
	brush.CreatePatternBrush(&bitmap);  //创建位图画刷
	GetClientRect(&rect);       //获得客户区大小
	pDC->FillRect(rect,&brush);   //将矩形区域用位图填充
/*	pDC->FillSolidRect(rect,RGB(255,255,255));	//绘制背景色*/
/*	pDC->Rectangle(100,0,300,400); */
	char buf[100];
	sprintf(buf,"玩家一：分数：%d",numLines*10);
	pDC->TextOut(300,20,buf); 
/*	pDC->Rectangle(450,0,650,400); */
	char buf2[100];
	sprintf(buf2,"玩家二：分数：%d",numLines2*10);
		pDC->TextOut(850,20,buf2); 
	CRect rc,rc2;  	       
	CRect rcY1;
	CRect rcY2;              //定义矩形区
	COLORREF BrickColor[8]={0xFFFFFF,0xFF0000,0x00FF00,0x0000FF, 0x00FFFF,0xFFFF00,0x800000,0x800080};
	//预显示
	for (i = 0; i < 4; ++i)//一行一行的画砖块
	{
		for (j = 2; j < 8; ++j)
		{
			rcY1 = CRect((j-2)*nSize+380, i*nSize+250, (j+1-2)*nSize+380, (i+1)*nSize+250);
			rcY2 = CRect((j-2)*nSize+530, i*nSize+250, (j+1-2)*nSize+530, (i+1)*nSize+250);
			//绘制面板
			//1
			if (0 != imageY1[i][j])
			{
				pDC->FillRect(rcY1, &CBrush(BrickColor[imageY1[i][j]]));//画临时砖块(运动中)
				pDC->Draw3dRect(rcY1,GetLightColor(BrickColor[imageY1[i][j]]),GetDarkColor(BrickColor[imageY1[i][j]]));
			}
			//2
			if (0 != imageY2[i][j])
			{
				pDC->FillRect(rcY2, &CBrush(BrickColor[imageY2[i][j]]));//画临时砖块(运动中)
				pDC->Draw3dRect(rcY2,GetLightColor(BrickColor[imageY2[i][j]]),GetDarkColor(BrickColor[imageY2[i][j]]));
			}
		}
	}
	/////////游戏界面显示
	for (i=0; i<height; i++)                                  //一行一行的画砖块
	{
		for(j=0;j<width;j++)
		{
			rc=CRect(j*nSize+100,i*nSize+100,(j+1)*nSize+100,(i+1)*nSize+100);
			rc2=CRect(j*nSize+750,i*nSize+100,(j+1)*nSize+750,(i+1)*nSize+100);
			//绘制面板1
			if (image[i][j]!=0)
			{
				pDC->FillRect(rc, &CBrush(BrickColor[image[i][j]]));                       //画临时砖块(运动中)
				pDC->Draw3dRect(rc,GetLightColor(BrickColor[image[i][j]]),GetDarkColor(BrickColor[image[i][j]]));
			}//绘制面板2
			if (image2[i][j]!=0)
			{
				pDC->FillRect(rc2, &CBrush(BrickColor[image2[i][j]]));
				pDC->Draw3dRect(rc2,GetLightColor(BrickColor[image2[i][j]]),GetDarkColor(BrickColor[image2[i][j]]));
			}
		}
	}

}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNewTetrisView message handlers

void CNewTetrisView::OnGameStart() 
{
	// TODO: Add your command handler code here
	////////////播放音乐////////////////////
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_LOOP);
/*	PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_ASYNC|SND_RESOURCE|SND_NODEFAULT|SND_LOOP);*/
	/////////////////面板1//////////////////
	gameOver=0; brickInFlight=0; numLines=0;
	gameOver2=0; brickInFlight2=0; numLines2=0;
	for (unsigned int i = 0; i<20; i++)
	{
		for (unsigned int j = 0; j<10; j++) 
		{
			outputImage[i][j]=0;
			outputImage2[i][j]=0;
		}
	}
	bin->setImage(outputImage); 
	bin2->setImage(outputImage2); 
	SetTimer(0,difficulty,NULL);
	SetTimer(2,difficulty2,NULL);
}
	/////////////////面板2//////////////////
// 	gameOver2=0; brickInFlight2=0; numLines2=0;
// 	for (unsigned int m = 0; m<20; m++)
// 	{
// 		for (unsigned int k = 0; k<10; k++) 
// 			outputImage2[m][k]=0;
// 	}
// 	bin2->setImage(outputImage2); 
// 	SetTimer(1,difficulty2,NULL);


void CNewTetrisView::OnDiffEasy() 
{
	// TODO: Add your command handler code here
	difficulty=500; 
	difficulty2=500;
	OnGameStart();
}

void CNewTetrisView::OnDiffMid() 
{
	// TODO: Add your command handler code here
	difficulty=350; 
	difficulty2=500;
	OnGameStart();
}

void CNewTetrisView::OnDiffSup() 
{
	// TODO: Add your command handler code here
	difficulty=150;
	difficulty2=150;
	OnGameStart();
}

void CNewTetrisView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	unsigned int binWidth, binHeight;
	unsigned int i=0;
	unsigned int j=0;
	CDC*pDC=GetDC();
	binWidth=bin->getWidth();
	binHeight=bin->getHeight();
	// start the game
	if (nIDEvent == 0)
	{
	if (!brickInFlight&&!gameOver)         //开始游戏
	{
		///////////////////  预显示  /////////////
		// 没有砖块落下时，需要新建一个砖块.
            // 新建砖块需要随机指定砖块的形状和初始状态.
		if (1 == flag1)   //第一个方块，不是预测产生的
		{
			bType1 = (rand() % NUM_BRICK_TYPES) + 1;//rand()%7：随机产生0-6的数字。
			iOrient1 = (unsigned int) (rand() % 4);//随机状态0-3
			flag1 = 0;
		}
		
		brickType = bType1;//rand()%7：随机产生0-6的数字。
		initOrientation = iOrient1;//随机状态0-3
		if (0 == flag1)//2
		{
			bType1 = (rand() % NUM_BRICK_TYPES) + 1;//rand()%7：随机产生0-6的数字。
			iOrient1 = (unsigned int) (rand() % 4);//随机状态0-3
		if (bType1 == 1)
			activeBrickY1 = new CIBrick;
		else if (bType1 == 2) 
			activeBrickY1 = new CLBrick; 
		else if (bType1 == 3) 
			activeBrickY1 = new CSBrick;
		else if (bType1 == 3) 
			activeBrickY1 = new COBrick;
		else if (bType1 == 4) 
			activeBrickY1 = new CTBrick;
		else if (bType1 == 5) 
			activeBrickY1 = new CZBrick;
		else if (bType1 == 6) 
			activeBrickY1 = new CJBrick;
		else if (bType1 == 7) 
			activeBrickY1 = new CZBrick;
			activeBrickY1->setColour((unsigned char)bType1);//设置砖块颜色
			activeBrickY1->putAtTop(iOrient1, binWidth/2);//置顶
			binY1->getImage(outputImageY1); //将固定块拷贝到临时数组
			activeBrickY1->operator>>(outputImageY1); //将刚产生的加入
			}
		if (brickType == 1)
			activeBrick = new CIBrick;
		else if (brickType == 2) 
			activeBrick = new CLBrick; 
		else if (brickType == 3) 
			activeBrick = new CSBrick;
		else if (brickType == 3) 
			activeBrick = new COBrick;
		else if (brickType == 4) 
			activeBrick = new CTBrick;
		else if (brickType == 5) 
			activeBrick = new CZBrick;
		else if (brickType == 6) 
			activeBrick = new CJBrick;
		else if (brickType == 7) 
			activeBrick = new CZBrick;
		// 		else if (brickType == 4) 
		// 			activeBrick = new COBrick;
			KillTimer(0);//关闭定时器
			SetTimer(0,difficulty,NULL);//设置定时器
		activeBrick->setColour((unsigned char)brickType); 
		activeBrick->putAtTop(initOrientation, binWidth/2);
		notCollide = activeBrick->checkCollision(bin);
		if (notCollide)
		{
			brickInFlight = 1;
			bin->getImage(outputImage);       //拷贝固定砖块数组进临时数组
			activeBrick->operator>>(outputImage);  //将砖块下一位置添加进去
			Invalidate(FALSE);      //刷新
		}
		else
		{
			//程序结束 
			gameOver = 1; 
			delete activeBrick; 
			brickInFlight =0;
		}
	}
	if (brickInFlight&&!gameOver)
	{
		notCollide = activeBrick->shiftDown(bin);     //检查冲突
		if (notCollide)
		{
			bin->getImage(outputImage);       //将印象中的临时砖块拷贝进固定块中
			activeBrick->operator>>(outputImage); //将砖块下一位置添加进去
		}
		else
		{
			brickInFlight = 0; 
			bin->getImage(outputImage);  //将印象中的临时砖块拷贝进固定块中
			activeBrick->operator>>(outputImage);  //将砖块下一位置添加进去
			bin->setImage(outputImage);  //重置固定块
			Invalidate(FALSE); //刷新
			numLines = numLines + bin->removeFullLines();  //统计消除行数
			bin->getImage(outputImage);    //获取印象数组中的砖块
		}
		Invalidate(FALSE);
		if (1==gameOver)
		{
			KillTimer(0);//关闭定时器
			if (MessageBox("玩家二获胜，还玩么","提示",MB_YESNO) == IDYES)
			{
				OnGameStart();
			}
			else
			{
				exit(0);//退出游戏
			}
		}
	}
	}////面板2
	else
	{ 
		if (!brickInFlight2&&!gameOver2)
		{
// 		brickType2 = (rand() % NUM_BRICK_TYPES) + 1; 
// 		initOrientation2 = (unsigned int) (rand() % 4);//防止rand 函数每次运行结果一样
// 													  /*	CTimetime=CTime::GetCurrentTime();intq=int(time.GetSecond());
// 		brickType = (q % NUM_BRICK_TYPES)+ 1; initOrientation = (unsigned int) (q % 4);*/
			///////////////////  预显示  /////////////
			// 没有砖块落下时，需要新建一个砖块.
            // 新建砖块需要随机指定砖块的形状和初始状态.
			if (1 == flag2)   //第一个方块，不是预测产生的
			{
				bType2 = (rand() % NUM_BRICK_TYPES) + 1;//rand()%7：随机产生0-6的数字。
				iOrient2 = (unsigned int) (rand() % 4);//随机状态0-3
				flag2 = 0;
			}
			brickType2 = bType2;//rand()%7：随机产生0-6的数字。
			initOrientation2 = iOrient2;//随机状态0-3
			if (0 == flag2)//2
			{
				bType2 = (rand() % NUM_BRICK_TYPES) + 1;//rand()%7：随机产生0-6的数字。
				iOrient2 = (unsigned int) (rand() % 4);//随机状态0-3
				if (bType2 == 1)
					activeBrickY2 = new CIBrick;
				else if (bType2 == 2) 
					activeBrickY2 = new CLBrick; 
				else if (bType2 == 3) 
					activeBrickY2 = new CSBrick;
				else if (bType2 == 3) 
					activeBrickY2 = new COBrick;
				else if (bType2 == 4) 
					activeBrickY2 = new CTBrick;
				else if (bType2 == 5) 
					activeBrickY2 = new CZBrick;
				else if (bType2 == 6) 
					activeBrickY2 = new CJBrick;
				else if (bType2 == 7) 
					activeBrickY2 = new CZBrick;
				activeBrickY2->setColour((unsigned char)bType2);//设置砖块颜色
				activeBrickY2->putAtTop(iOrient2, binWidth/2);//置顶
				binY2->getImage(outputImageY2); //将固定块拷贝到临时数组
				activeBrickY2->operator>>(outputImageY2); //将刚产生的加入
			}
		if (brickType2 == 1)
			activeBrick2 = new CIBrick;
		else if (brickType2 == 2) 
			activeBrick2 = new CLBrick; 
		else if (brickType2 == 3) 
			activeBrick2 = new CSBrick;
		else if (brickType2 == 3) 
			activeBrick2 = new COBrick;
		else if (brickType2 == 4) 
			activeBrick2 = new CTBrick;
		else if (brickType2 == 5) 
			activeBrick2 = new CZBrick;
		else if (brickType2 == 6) 
			activeBrick2 = new CJBrick;
		else if (brickType2 == 7) 
			activeBrick2 = new CZBrick;
		// 		else if (brickType == 4) 
		// 			activeBrick = new COBrick;
		KillTimer(2);//关闭定时器
		SetTimer(2,difficulty2,NULL);//设置定时器
		activeBrick2->setColour((unsigned char)brickType2); 
		activeBrick2->putAtTop(initOrientation2, binWidth/2);
		notCollide2 = activeBrick2->checkCollision(bin2);
		if (notCollide2)
		{
			brickInFlight2 = 1;
			bin2->getImage(outputImage2); 
			activeBrick2->operator>>(outputImage2); 
			Invalidate(FALSE);
		}
		else
		{
			//程序结束 
			gameOver2 = 1; 
			delete activeBrick2; 
			brickInFlight2 =0;
		}
	}
	if (brickInFlight2&&!gameOver2)
	{
		notCollide2 = activeBrick2->shiftDown(bin2); 
		if (notCollide2)
		{
			bin2->getImage(outputImage2); 
			activeBrick2->operator>>(outputImage2);
		}
		else
		{
			brickInFlight2 = 0;
			bin2->getImage(outputImage2);             
			activeBrick2->operator>>(outputImage2); //
			bin2->setImage(outputImage2); 
			Invalidate(FALSE);
			numLines2 = numLines2 + bin2->removeFullLines();
			bin2->getImage(outputImage2);
		}
		Invalidate(FALSE);
		if (1==gameOver2)
		{
			KillTimer(2);
			OnGameStart();
			/*if(MessageBox("玩家一获胜，还玩么","提示",MB_YESNO)==IDYES) 
			{	OnGameStart();}
			else exit(0); */        //退出程序
		}
	}
	}
	CView::OnTimer(nIDEvent);
}

void CNewTetrisView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    //控制面板1
	if (nChar == VK_RIGHT) activeBrick->shiftRight(bin);
	else if (nChar == VK_LEFT) activeBrick->shiftLeft(bin);
	else if (nChar == VK_UP)   activeBrick->rotateClockwise(bin); 
	else if (nChar == VK_DOWN) activeBrick->shiftDown(bin);
	Invalidate();
	//控制面板2
	if (nChar =='D' ) activeBrick2->shiftRight(bin2);
	else if (nChar == 'A') activeBrick2->shiftLeft(bin2);
	else if (nChar == 'W')   activeBrick2->rotateClockwise(bin2); 
	else if (nChar == 'S') activeBrick2->shiftDown(bin2);
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
COLORREF CNewTetrisView::GetLightColor(COLORREF m_crBody)
{
	BYTE r = GetRValue(m_crBody); BYTE g = GetGValue(m_crBody); BYTE b = GetBValue(m_crBody);
	r = r+COLOR_CHANGE>255 ?255 : r+COLOR_CHANGE; g = g+COLOR_CHANGE>255 ? 255 : g+COLOR_CHANGE; b = b+COLOR_CHANGE>255 ? 255 :b+COLOR_CHANGE;
	return RGB(r, g, b);
}
COLORREF CNewTetrisView::GetDarkColor(COLORREF m_crBody)
{
	BYTE r = GetRValue(m_crBody); BYTE g = GetGValue(m_crBody); BYTE b = GetBValue(m_crBody);
	r = r-COLOR_CHANGE<0 ?0 : r-COLOR_CHANGE; g = g-COLOR_CHANGE<0 ? 0 : g-COLOR_CHANGE; b = b-COLOR_CHANGE<0 ? 0 :b-COLOR_CHANGE;
	return RGB(r, g, b);
}


void CNewTetrisView::OnHelp1() 
{
	// TODO: Add your command handler code here
	HelpDialog dlg;
	dlg.DoModal();
}

void CNewTetrisView::OnPause() 
{
	// TODO: Add your command handler code here
	KillTimer(0);
	KillTimer(2);
	// 	if (p==0)
	// 	{
	// 		KillTimer(0);
	// 		KillTimer(2);
	// 		p=1;
	// 	}
	// 	if (p==1)
	// 	{
	// 		SetTimer(0,difficulty,NULL);
	// 		SetTimer(2,difficulty2,NULL);
	// 		p=0;
// 	}
}

void CNewTetrisView::OnRestart() 
{
	// TODO: Add your command handler code here
	SetTimer(0,difficulty,NULL);
	SetTimer(2,difficulty2,NULL);
}
