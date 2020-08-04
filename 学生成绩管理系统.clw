; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDataInputDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "学生成绩管理系统.h"

ClassCount=5
Class1=CMyApp
Class2=CMyDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_MY_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DATAINPUT
Resource4=IDD_ABOUTBOX
Class4=CLoginDlg
Class5=CDataInputDlg
Resource5=IDD_LOGIN

[CLS:CMyApp]
Type=0
HeaderFile=学生成绩管理系统.h
ImplementationFile=学生成绩管理系统.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=学生成绩管理系统Dlg.h
ImplementationFile=学生成绩管理系统Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMyDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=学生成绩管理系统Dlg.h
ImplementationFile=学生成绩管理系统Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=10
Control1=IDCANCEL,button,1342242816
Control2=IDC_DATALIST,SysListView32,1350631425
Control3=IDC_ADDDATA,button,1342242816
Control4=IDC_REVISEDATA,button,1342242816
Control5=IDC_DELETEDATA,button,1342242816
Control6=IDC_SEARCHDATA,button,1342242816
Control7=IDC_INPUT_NUM,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287

[DLG:IDD_DATAINPUT]
Type=1
Class=CDataInputDlg
ControlCount=22
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_MATH,edit,1350631552
Control10=IDC_ENGLISH,edit,1350631552
Control11=IDC_SPORTS,edit,1350631552
Control12=IDC_PHYSICS,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_NUM,edit,1350631552
Control19=IDC_NAME,edit,1350631552
Control20=IDC_GENDER,edit,1350631552
Control21=IDC_BIRTHDAY,edit,1350631552
Control22=IDC_MAJOR,edit,1350631552

[DLG:IDD_LOGIN]
Type=1
Class=CLoginDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ACCOUNT,edit,1350631552
Control6=IDC_PASSWORD,edit,1350631584

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLoginDlg

[CLS:CDataInputDlg]
Type=0
HeaderFile=DataInputDlg.h
ImplementationFile=DataInputDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDataInputDlg

