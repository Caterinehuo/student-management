// ѧ���ɼ�����ϵͳDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ѧ���ɼ�����ϵͳ.h"
#include "ѧ���ɼ�����ϵͳDlg.h"
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
	
	//================================ ��ʼ������ ================================
	if (m_LoginDlg.DoModal()==IDCANCEL)
	{
		CDialog::OnCancel();
	}
	
	m_DataList.InsertColumn(0,_T("ѧ��"),2,80);
	m_DataList.InsertColumn(1,_T("����"),2,80);
	m_DataList.InsertColumn(2,_T("�Ա�"),2,60);
	m_DataList.InsertColumn(3,_T("����"),2,100);
	m_DataList.InsertColumn(4,_T("רҵ"),2,100);
	m_DataList.InsertColumn(5,_T("��ѧ�ɼ�"),2,80);
	m_DataList.InsertColumn(6,_T("Ӣ��ɼ�"),2,80);
	m_DataList.InsertColumn(7,_T("�����ɼ�"),2,80);
	m_DataList.InsertColumn(8,_T("����ɼ�"),2,80);

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

//=================================== ���ѧ����Ϣ =======================================
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

//=================================== �޸�ѧ����Ϣ =======================================
void CMyDlg::OnRevisedata() 
{
	int nSelectLine;
	nSelectLine=m_DataList.GetSelectionMark();
	if (nSelectLine==-1)
	{
		MessageBox("��ѡ��һ����Ϣ�����޸�");
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

//=================================== ɾ��ѧ����Ϣ =======================================
void CMyDlg::OnDeletedata() 
{
	CString sShowMessage;
	int nSelectLine;
	nSelectLine=m_DataList.GetSelectionMark();
	if (nSelectLine!=-1)
	{
		sShowMessage.Format("ȷ��ɾ�� %s %s ͬѧ����Ϣ��",m_AllStudentData[nSelectLine].sNum,m_AllStudentData[nSelectLine].sName);
		if (MessageBox(sShowMessage,_T("ɾ����ʾ"),MB_OKCANCEL)==IDOK)
		{
			i_AllStudentData=m_AllStudentData.begin();
			for (int i=0;i<nSelectLine;i++)
			{
				i_AllStudentData++;
			}
			m_AllStudentData.erase(i_AllStudentData);
			MessageBox("ɾ���ɹ���");
			ShowAllData();
		}
	} 
	else
	{
		MessageBox("��ѡ��һ����Ϣ����ɾ��");
	}
}

//=================================== ��ѯѧ����Ϣ =======================================
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
				sOneline.Format("ѧ�ţ�%s\r\n",m_AllStudentData[i].sNum);
				sShowMessage+=sOneline;
				sOneline.Format("������%s\r\n",m_AllStudentData[i].sName);
				sShowMessage+=sOneline;
				sOneline.Format("�Ա�%s\r\n",m_AllStudentData[i].sGender);
				sShowMessage+=sOneline;
				sOneline.Format("���գ�%s\r\n",m_AllStudentData[i].sBirthday);
				sShowMessage+=sOneline;
				sOneline.Format("רҵ��%s\r\n",m_AllStudentData[i].sMajor);
				sShowMessage+=sOneline;
				sOneline.Format("��ѧ�ɼ���%d\r\n",m_AllStudentData[i].nMath);
				sShowMessage+=sOneline;
				sOneline.Format("Ӣ��ɼ���%d\r\n",m_AllStudentData[i].nEnglish);
				sShowMessage+=sOneline;
				sOneline.Format("�����ɼ���%d\r\n",m_AllStudentData[i].nSports);
				sShowMessage+=sOneline;
				sOneline.Format("����ɼ���%d\r\n",m_AllStudentData[i].nPhysics);
				sShowMessage+=sOneline;

				MessageBox(sShowMessage);

				break;
			}
		}
		if (nCheck==0)
		{
			sShowMessage.Format("ϵͳ�в�����ѧ��Ϊ��%s ��ѧ����Ϣ",sSearchNum);
			MessageBox(sShowMessage);
		}
	}
	else
	{
		MessageBox("��������Ҫ��ѯ��ѧ��");
	}
	
}

//======================================��ȡ�ļ���Ϣ�ĺ���==========================================
void CMyDlg::ReadFile()
{
	setlocale( LC_CTYPE,  "chs" );//���ÿ��Դ��ļ��ж�ȡ����
	int nBit;//��¼���ʱ���ҵ�λ��
	CString sOneLine;//��ȡ��һ����Ϣ
	CStdioFile readfile;//��ȡ��Ϣ�Ķ���
	readfile.Open("ѧ����Ϣ.txt",CFile::modeRead);//���ļ�
	while(readfile.ReadString(sOneLine))//��ȡ��һ��
	{
		CStudentData OneStudent;//����һ��������Ϣ�Ķ���
		//�Ӷ�ȡ��һ���аѸ�����Ŀ��ֳ���
		//ѧ��
		nBit = sOneLine.Find(_T(";"));
		OneStudent.sNum=sOneLine.Mid(0,nBit);
		sOneLine.Delete(0,nBit+1);
		//����
		nBit=sOneLine.Find(_T(";"));
		OneStudent.sName=sOneLine.Mid(0,nBit);
		sOneLine.Delete(0,nBit+1);
		//�Ա�
		nBit=sOneLine.Find(_T(";"));
		OneStudent.sGender=sOneLine.Mid(0,nBit);
		sOneLine.Delete(0,nBit+1);
		//����
		nBit=sOneLine.Find(_T(";"));
		OneStudent.sBirthday=sOneLine.Mid(0,nBit);
		sOneLine.Delete(0,nBit+1);
		//רҵ
		nBit=sOneLine.Find(_T(";"));
		OneStudent.sMajor=sOneLine.Mid(0,nBit);
		sOneLine.Delete(0,nBit+1);
		//��ѧ�ɼ�
		nBit=sOneLine.Find(_T(";"));
		OneStudent.nMath=atoi(sOneLine.Mid(0,nBit));
		sOneLine.Delete(0,nBit+1);
		//Ӣ��ɼ�
		nBit=sOneLine.Find(_T(";"));
		OneStudent.nEnglish=atoi(sOneLine.Mid(0,nBit));
		sOneLine.Delete(0,nBit+1);
		//�����ɼ�
		nBit=sOneLine.Find(_T(";"));
		OneStudent.nSports=atoi(sOneLine.Mid(0,nBit));
		sOneLine.Delete(0,nBit+1);
		//����ɼ�
		nBit=sOneLine.Find(_T(";"));
		OneStudent.nPhysics=atoi(sOneLine.Mid(0,nBit));
		sOneLine.Delete(0,nBit+1);
		
		m_AllStudentData.push_back(OneStudent);//����ȡ���һ����Ϣ����������
	}
	readfile.Close();//�ر��ļ�
}

//========================================�����ļ���Ϣ�ĺ���========================================
void CMyDlg::SaveFile()
{
	setlocale( LC_CTYPE,  "chs" );//���ÿ��Դ��ļ��ж�ȡ����
	CString sOneLine;//����һ����Ϣ
	
	CString sMath;
	CString sEnglish;
	CString sSports;
	CString sPhysics;
	
	CStdioFile writefile;//д���ļ��Ķ���
	writefile.Open("ѧ����Ϣ.txt",CFile::modeCreate|CFile::modeWrite);//����Ҫд����ļ�
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
	writefile.Close();//�ر��ļ�����
}

//========================================= ��ʾȫ����Ϣ���� ========================================
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
