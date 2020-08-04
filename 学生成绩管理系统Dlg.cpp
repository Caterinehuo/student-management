// 学生成绩管理系统Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "学生成绩管理系统.h"
#include "学生成绩管理系统Dlg.h"
#include <locale>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_INPUT_NUM, m_InputNum);
	DDX_Control(pDX, IDC_DATALIST, m_DataList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADDDATA, OnAdddata)
	ON_BN_CLICKED(IDC_REVISEDATA, OnRevisedata)
	ON_BN_CLICKED(IDC_DELETEDATA, OnDeletedata)
	ON_BN_CLICKED(IDC_SEARCHDATA, OnSearchdata)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//================================ 初始化代码 ================================
	if (m_LoginDlg.DoModal()==IDCANCEL)
	{
		CDialog::OnCancel();
	}
	
	m_DataList.InsertColumn(0,_T("学号"),2,80);
	m_DataList.InsertColumn(1,_T("姓名"),2,80);
	m_DataList.InsertColumn(2,_T("性别"),2,60);
	m_DataList.InsertColumn(3,_T("生日"),2,100);
	m_DataList.InsertColumn(4,_T("专业"),2,100);
	m_DataList.InsertColumn(5,_T("数学成绩"),2,80);
	m_DataList.InsertColumn(6,_T("英语成绩"),2,80);
	m_DataList.InsertColumn(7,_T("体育成绩"),2,80);
	m_DataList.InsertColumn(8,_T("物理成绩"),2,80);

	ReadFile();
	ShowAllData();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		CRect rc;
		GetClientRect(&rc);
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP2);
		
		BITMAP bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0,0,rc.Width(), rc.Height(), &dcMem,0,0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CMyDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	SaveFile();
	CDialog::OnCancel();
}

//=================================== 添加学生信息 =======================================
void CMyDlg::OnAdddata() 
{
	CStudentData m_NewData;
	m_DataInputDlg.nType=0;
	if (m_DataInputDlg.DoModal()==IDOK)
	{
		m_NewData.sNum=m_DataInputDlg.sNum;
		m_NewData.sName=m_DataInputDlg.sName;
		m_NewData.sGender=m_DataInputDlg.sGender;
		m_NewData.sBirthday=m_DataInputDlg.sBirthday;
		m_NewData.sMajor=m_DataInputDlg.sMajor;
		m_NewData.nMath=m_DataInputDlg.nMath;
		m_NewData.nEnglish=m_DataInputDlg.nEnglish;
		m_NewData.nSports=m_DataInputDlg.nSports;
		m_NewData.nPhysics=m_DataInputDlg.nPhysics;

		m_AllStudentData.push_back(m_NewData);
		ShowAllData();
	}

}

//=================================== 修改学生信息 =======================================
void CMyDlg::OnRevisedata() 
{
	int nSelectLine;
	nSelectLine=m_DataList.GetSelectionMark();
	if (nSelectLine==-1)
	{
		MessageBox("请选择一行信息进行修改");
	} 
	else
	{

		m_DataInputDlg.nType=1;
		m_DataInputDlg.sNum=m_AllStudentData[nSelectLine].sNum;
		m_DataInputDlg.sName=m_AllStudentData[nSelectLine].sName;
		m_DataInputDlg.sGender=m_AllStudentData[nSelectLine].sGender;
		m_DataInputDlg.sBirthday=m_AllStudentData[nSelectLine].sBirthday;
		m_DataInputDlg.sMajor=m_AllStudentData[nSelectLine].sMajor;
		m_DataInputDlg.nMath=m_AllStudentData[nSelectLine].nMath;
		m_DataInputDlg.nEnglish=m_AllStudentData[nSelectLine].nEnglish;
		m_DataInputDlg.nSports=m_AllStudentData[nSelectLine].nSports;
		m_DataInputDlg.nPhysics=m_AllStudentData[nSelectLine].nPhysics;

		if (m_DataInputDlg.DoModal()==IDOK)
		{
			m_AllStudentData[nSelectLine].sNum=m_DataInputDlg.sNum;
			m_AllStudentData[nSelectLine].sName=m_DataInputDlg.sName;
			m_AllStudentData[nSelectLine].sGender=m_DataInputDlg.sGender;
			m_AllStudentData[nSelectLine].sBirthday=m_DataInputDlg.sBirthday;
			m_AllStudentData[nSelectLine].sMajor=m_DataInputDlg.sMajor;
			m_AllStudentData[nSelectLine].nMath=m_DataInputDlg.nMath;
			m_AllStudentData[nSelectLine].nEnglish=m_DataInputDlg.nEnglish;
			m_AllStudentData[nSelectLine].nSports=m_DataInputDlg.nSports;
			m_AllStudentData[nSelectLine].nPhysics=m_DataInputDlg.nPhysics;
			ShowAllData();
		}
	}	
}

//=================================== 删除学生信息 =======================================
void CMyDlg::OnDeletedata() 
{
	CString sShowMessage;
	int nSelectLine;
	nSelectLine=m_DataList.GetSelectionMark();
	if (nSelectLine!=-1)
	{
		sShowMessage.Format("确定删除 %s %s 同学的信息吗？",m_AllStudentData[nSelectLine].sNum,m_AllStudentData[nSelectLine].sName);
		if (MessageBox(sShowMessage,_T("删除提示"),MB_OKCANCEL)==IDOK)
		{
			i_AllStudentData=m_AllStudentData.begin();
			for (int i=0;i<nSelectLine;i++)
			{
				i_AllStudentData++;
			}
			m_AllStudentData.erase(i_AllStudentData);
			MessageBox("删除成功！");
			ShowAllData();
		}
	} 
	else
	{
		MessageBox("请选择一行信息进行删除");
	}
}

//=================================== 查询学生信息 =======================================
void CMyDlg::OnSearchdata() 
{
	int nCheck=0;
	CString sOneline;
	CString sShowMessage;
	CString sSearchNum;
	m_InputNum.GetWindowText(sSearchNum);
	if (!sSearchNum.IsEmpty())
	{
		for (int i=0;i<m_AllStudentData.size();i++)
		{
			if (sSearchNum.Compare(m_AllStudentData[i].sNum)==0)
			{
				nCheck=1;
				sOneline.Format("学号：%s\r\n",m_AllStudentData[i].sNum);
				sShowMessage+=sOneline;
				sOneline.Format("姓名：%s\r\n",m_AllStudentData[i].sName);
				sShowMessage+=sOneline;
				sOneline.Format("性别：%s\r\n",m_AllStudentData[i].sGender);
				sShowMessage+=sOneline;
				sOneline.Format("生日：%s\r\n",m_AllStudentData[i].sBirthday);
				sShowMessage+=sOneline;
				sOneline.Format("专业：%s\r\n",m_AllStudentData[i].sMajor);
				sShowMessage+=sOneline;
				sOneline.Format("数学成绩：%d\r\n",m_AllStudentData[i].nMath);
				sShowMessage+=sOneline;
				sOneline.Format("英语成绩：%d\r\n",m_AllStudentData[i].nEnglish);
				sShowMessage+=sOneline;
				sOneline.Format("体育成绩：%d\r\n",m_AllStudentData[i].nSports);
				sShowMessage+=sOneline;
				sOneline.Format("物理成绩：%d\r\n",m_AllStudentData[i].nPhysics);
				sShowMessage+=sOneline;

				MessageBox(sShowMessage);

				break;
			}
		}
		if (nCheck==0)
		{
			sShowMessage.Format("系统中不包含学号为：%s 的学生信息",sSearchNum);
			MessageBox(sShowMessage);
		}
	}
	else
	{
		MessageBox("请输入需要查询的学号");
	}
	
}

//======================================读取文件信息的函数==========================================
void CMyDlg::ReadFile()
{
	setlocale( LC_CTYPE,  "chs" );//设置可以从文件中读取中文
	int nBit;//记录拆分时查找的位数
	CString sOneLine;//读取的一行信息
	CStdioFile readfile;//读取信息的对象
	readfile.Open("学生信息.txt",CFile::modeRead);//打开文件
	while(readfile.ReadString(sOneLine))//读取出一行
	{
		CStudentData OneStudent;//定义一个保存信息的对象
		//从读取的一行中把各个项目拆分出来
		//学号
		nBit = sOneLine.Find(_T(";"));
		OneStudent.sNum=sOneLine.Mid(0,nBit);
		sOneLine.Delete(0,nBit+1);
		//姓名
		nBit=sOneLine.Find(_T(";"));
		OneStudent.sName=sOneLine.Mid(0,nBit);
		sOneLine.Delete(0,nBit+1);
		//性别
		nBit=sOneLine.Find(_T(";"));
		OneStudent.sGender=sOneLine.Mid(0,nBit);
		sOneLine.Delete(0,nBit+1);
		//生日
		nBit=sOneLine.Find(_T(";"));
		OneStudent.sBirthday=sOneLine.Mid(0,nBit);
		sOneLine.Delete(0,nBit+1);
		//专业
		nBit=sOneLine.Find(_T(";"));
		OneStudent.sMajor=sOneLine.Mid(0,nBit);
		sOneLine.Delete(0,nBit+1);
		//数学成绩
		nBit=sOneLine.Find(_T(";"));
		OneStudent.nMath=atoi(sOneLine.Mid(0,nBit));
		sOneLine.Delete(0,nBit+1);
		//英语成绩
		nBit=sOneLine.Find(_T(";"));
		OneStudent.nEnglish=atoi(sOneLine.Mid(0,nBit));
		sOneLine.Delete(0,nBit+1);
		//体育成绩
		nBit=sOneLine.Find(_T(";"));
		OneStudent.nSports=atoi(sOneLine.Mid(0,nBit));
		sOneLine.Delete(0,nBit+1);
		//物理成绩
		nBit=sOneLine.Find(_T(";"));
		OneStudent.nPhysics=atoi(sOneLine.Mid(0,nBit));
		sOneLine.Delete(0,nBit+1);
		
		m_AllStudentData.push_back(OneStudent);//将读取完的一行信息放入容器中
	}
	readfile.Close();//关闭文件
}

//========================================保存文件信息的函数========================================
void CMyDlg::SaveFile()
{
	setlocale( LC_CTYPE,  "chs" );//设置可以从文件中读取中文
	CString sOneLine;//保存一行信息
	
	CString sMath;
	CString sEnglish;
	CString sSports;
	CString sPhysics;
	
	CStdioFile writefile;//写入文件的对象
	writefile.Open("学生信息.txt",CFile::modeCreate|CFile::modeWrite);//打开需要写入的文件
	for (int i=0;i<m_AllStudentData.size();i++)
	{
		sOneLine="";
		sMath.Format("%d",m_AllStudentData[i].nMath);
		sEnglish.Format("%d",m_AllStudentData[i].nEnglish);
		sSports.Format("%d",m_AllStudentData[i].nSports);
		sPhysics.Format("%d",m_AllStudentData[i].nPhysics);

		sOneLine=m_AllStudentData[i].sNum+_T(";")+m_AllStudentData[i].sName+_T(";")+m_AllStudentData[i].sGender
			+_T(";")+m_AllStudentData[i].sBirthday+_T(";")+m_AllStudentData[i].sMajor+_T(";")+sMath+_T(";")+sEnglish+_T(";")+
			sSports+_T(";")+sPhysics+_T(";\n");
		writefile.WriteString(sOneLine);
	}
	writefile.Close();//关闭文件对象
}

//========================================= 显示全部信息函数 ========================================
void CMyDlg::ShowAllData()
{
	CString sMath;
	CString sEnglish;
	CString sSports;
	CString sPhysics;

	m_DataList.DeleteAllItems();
	for (int i=0;i<m_AllStudentData.size();i++)
	{
		sMath.Format("%d",m_AllStudentData[i].nMath);
		sEnglish.Format("%d",m_AllStudentData[i].nEnglish);
		sSports.Format("%d",m_AllStudentData[i].nSports);
		sPhysics.Format("%d",m_AllStudentData[i].nPhysics);

		m_DataList.InsertItem(i,m_AllStudentData[i].sNum);
		m_DataList.SetItemText(i,1,m_AllStudentData[i].sName);
		m_DataList.SetItemText(i,2,m_AllStudentData[i].sGender);
		m_DataList.SetItemText(i,3,m_AllStudentData[i].sBirthday);
		m_DataList.SetItemText(i,4,m_AllStudentData[i].sMajor);
		m_DataList.SetItemText(i,5,sMath);
		m_DataList.SetItemText(i,6,sEnglish);
		m_DataList.SetItemText(i,7,sSports);
		m_DataList.SetItemText(i,8,sPhysics);
	}
}

void CMyDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{	
	CDialog::OnLButtonDown(nFlags, point);
	PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(point.x,   point.y));
}
