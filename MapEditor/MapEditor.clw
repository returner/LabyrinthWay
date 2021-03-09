; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMapEditorView
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mapeditor.h"
LastPage=0

ClassCount=9
Class1=CCellData
Class2=CCutDlg
Class3=CInformationDlg
Class4=CMainFrame
Class5=CMapEditorApp
Class6=CAboutDlg
Class7=CMapEditorDoc
Class8=CMapEditorView

ResourceCount=5
Resource1=IDD_INFORMATION
Resource2=IDD_ABOUTBOX
Resource3=IDD_MAPEDITOR_FORM
Resource4=IDR_MAINFRAME
Class9=CPosition
Resource5=IDD_CUT

[CLS:CCellData]
Type=0
BaseClass=CWnd
HeaderFile=CellData.h
ImplementationFile=CellData.cpp

[CLS:CCutDlg]
Type=0
BaseClass=CDialog
HeaderFile=CutDlg.h
ImplementationFile=CutDlg.cpp
LastObject=CCutDlg
Filter=W
VirtualFilter=dWC

[CLS:CInformationDlg]
Type=0
BaseClass=CDialog
HeaderFile=InformationDlg.h
ImplementationFile=InformationDlg.cpp
Filter=W
LastObject=CInformationDlg
VirtualFilter=dWC

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
LastObject=CMainFrame
Filter=T
VirtualFilter=fWC

[CLS:CMapEditorApp]
Type=0
BaseClass=CWinApp
HeaderFile=MapEditor.h
ImplementationFile=MapEditor.cpp
LastObject=CMapEditorApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=MapEditor.cpp
ImplementationFile=MapEditor.cpp
LastObject=CAboutDlg

[CLS:CMapEditorDoc]
Type=0
BaseClass=CDocument
HeaderFile=MapEditorDoc.h
ImplementationFile=MapEditorDoc.cpp
LastObject=CMapEditorDoc

[CLS:CMapEditorView]
Type=0
BaseClass=CFormView
HeaderFile=MapEditorView.h
ImplementationFile=MapEditorView.cpp
LastObject=CMapEditorView
Filter=W
VirtualFilter=VWC

[DLG:IDD_CUT]
Type=1
Class=CCutDlg
ControlCount=15
Control1=IDC_EDIT_CUT_X,edit,1350631552
Control2=IDC_EDIT_CUT_Y,edit,1350631552
Control3=IDC_EDIT_RED,edit,1350762624
Control4=IDC_EDIT_GREEN,edit,1350762624
Control5=IDC_EDIT_BLUE,edit,1350762624
Control6=IDOK,button,1342242816
Control7=IDC_CANCEL,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,button,1342308359
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352

[DLG:IDD_INFORMATION]
Type=1
Class=CInformationDlg
ControlCount=44
Control1=IDC_EDIT_HX,edit,1484849280
Control2=IDC_EDIT_HY,edit,1484849280
Control3=IDC_EDIT_AX,edit,1484849280
Control4=IDC_EDIT_AY,edit,1484849280
Control5=IDC_EDIT_BX,edit,1484849280
Control6=IDC_EDIT_BY,edit,1484849280
Control7=IDC_BUTTON_POSITION,button,1073807360
Control8=IDC_EDIT_ATT_HEIGHT,edit,1484849280
Control9=IDC_EDIT_ATT_SLOPE,edit,1484849280
Control10=IDC_EDIT_ATT_ATT,edit,1484849280
Control11=IDC_EDIT_ATT_DIR_X,edit,1216413824
Control12=IDC_EDIT_ATT_DIR_Y,edit,1216413824
Control13=IDC_BUTTON_INPUT,button,1476460544
Control14=IDC_ORIGIN_X,static,1342308352
Control15=IDC_ORIGIN_Y,static,1342308352
Control16=IDC_END_X,static,1342308352
Control17=IDC_END_Y,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,button,1342177287
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_POINT_X,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_POINT_Y,static,1342308352
Control28=IDC_STATIC,button,1342177287
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1208090624
Control33=IDC_STATIC,static,1208090624
Control34=IDC_STATIC,button,1342177287
Control35=IDC_STATIC,static,1342308352
Control36=IDC_STATIC,static,1342308352
Control37=IDC_STATIC,static,1342308352
Control38=IDC_STATIC,static,1342308352
Control39=IDC_STATIC,static,1342308352
Control40=IDC_STATIC,static,1342308352
Control41=IDC_STATIC,static,1342308352
Control42=IDC_STATIC,static,1342308352
Control43=IDC_STATIC,static,1342308352
Control44=IDC_STATIC,static,1342177806

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308364

[DLG:IDD_MAPEDITOR_FORM]
Type=1
Class=CMapEditorView
ControlCount=0

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE_AS
Command3=IDM_CUT
Command4=ID_INVALIDATE
Command5=IDM_VIEW_HEIGHT
Command6=IDM_VIEW_SLOPE
Command7=IDM_VIEW_GROUND
Command8=IDM_VIEW_DIRX
Command9=IDM_VIEW_DIRY
Command10=IDM_IMAGE_LEFT
Command11=IDM_IMAGE_RIGHT
Command12=IDM_IMAGE_UP
Command13=IDM_IMAGE_DOWN
Command14=ID_APP_ABOUT
CommandCount=14

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE_AS
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=IDM_CUT
Command11=ID_INVALIDATE
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_CUT
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=IDM_VIEW_HEIGHT
Command19=IDM_VIEW_SLOPE
Command20=IDM_VIEW_GROUND
Command21=IDM_VIEW_DIRX
Command22=IDM_VIEW_DIRY
Command23=ID_APP_ABOUT
Command24=ID_HELP
Command25=IDM_IMAGE_LEFT
Command26=IDM_IMAGE_RIGHT
Command27=IDM_IMAGE_UP
Command28=IDM_IMAGE_DOWN
CommandCount=28

[ACL:IDR_MAINFRAME]
Type=1
Class=?
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

[CLS:CPosition]
Type=0
HeaderFile=Position.h
ImplementationFile=Position.cpp
BaseClass=generic CWnd
Filter=W
LastObject=CPosition

