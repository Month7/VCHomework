; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNewTetrisView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NewTetris.h"
LastPage=0

ClassCount=6
Class1=CNewTetrisApp
Class2=CNewTetrisDoc
Class3=CNewTetrisView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=HelpDialog
Resource3=IDD_DIALOG1

[CLS:CNewTetrisApp]
Type=0
HeaderFile=NewTetris.h
ImplementationFile=NewTetris.cpp
Filter=N

[CLS:CNewTetrisDoc]
Type=0
HeaderFile=NewTetrisDoc.h
ImplementationFile=NewTetrisDoc.cpp
Filter=N

[CLS:CNewTetrisView]
Type=0
HeaderFile=NewTetrisView.h
ImplementationFile=NewTetrisView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CNewTetrisView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDD_Restart




[CLS:CAboutDlg]
Type=0
HeaderFile=NewTetris.cpp
ImplementationFile=NewTetris.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_ABOUT
Command2=ID_Game_Start
Command3=ID_DIFF_EASY
Command4=ID_DIFF_MID
Command5=ID_DIFF_SUP
Command6=IDD_HELP1
Command7=IDD_Pause
Command8=IDD_Restart
CommandCount=8

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=HelpDialog
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_LINK,static,1342308352
Control5=IDC_STATIC,static,1342308352

[CLS:HelpDialog]
Type=0
HeaderFile=HelpDialog.h
ImplementationFile=HelpDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=HelpDialog
VirtualFilter=dWC

