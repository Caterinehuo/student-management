// DataInputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "学生成绩管理系统.h"
#include "DataInputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataInputDlg dialog


CDataInputDlg::CDataInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDataInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataInputDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDataInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataInputDlg)
	DDX_Control(pDX, IDC_SPORTS, m_Sports);
	DDX_Control(pDX, IDC_PHYSICS, m_Physics);
	DDX_Control(pDX, IDC_NUM, m_Num);
	DDX_Control(pDX, IDC_NAME, m_Name);
	DDX_Control(pDX, IDC_MATH, m_Math);
	DDX_Control(pDX, IDC_MAJOR, m_Major);
	DDX_Control(pDX, IDC_GENDER, m_Gender);
	DDX_Control(pDX, IDC_ENGLISH, m_English);
	DDX_Control(pDX, IDC_BIRTHDAY, m_Birthday);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataInputDlg, CDialog)
	//{{AFX_MSG_MAP(CDataInputDlg)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataInputDlg message handlers

void CDataInputDlg::OnOK() 
{

	m_Num.GetWindowText(sNum);
	m_Name.GetWindowText(sName);
	m_Gender.GetWindowText(sGender);
	m_Birthday.GetWindowText(sBirthday);
	m_Major.GetWindowText(sMajor);
		
	m_Math.GetWindowText(sMath);
	m_Sports.GetWindowText(sSports);
	m_English.GetWindowText(sEnglish);
	m_Physics.GetWindowText(sPhysics);

	nMath=atoi(sMath);
	nEnglish=atoi(sEnglish);
	nPhysics=atoi(sPhysics);
	nSports=atoi(sSports);

	if (!sNum.IsEmpty())
	{
		if (!sName.IsEmpty())
		{
			if (!sGender.IsEmpty())
			{
				if (!sBirthday.IsEmpty())
				{
					if (!sMajor.IsEmpty())
					{
						if (!sMath.IsEmpty())
						{
							if (!sEnglish.IsEmpty())
							{
								if (!sSports.IsEmpty())
								{
									if (!sPhysics.IsEmpty())
									{
										if (nType==0)
										{
											MessageBox("添加成功！");
										} 
										else
										{
											MessageBox("修改成功！");
										}
										CDialog::OnOK();
									} 
									else
									{
										MessageBox("物理成绩为空！请填写物理成绩");
									}
								} 
								else
								{	
									MessageBox("体育成绩为空！请填写体育成绩");
								}
							} 
							else
							{
								MessageBox("英语成绩为空！请填写英语成绩");
							}
						} 
						else
						{
							MessageBox("数学成绩为空！请填写数学成绩");
						}
					} 
					else
					{
						MessageBox("专业为空！请填写专业");
					}
				} 
				else
				{
					MessageBox("生日为空！请填写生日");
				}
			} 
			else
			{
				MessageBox("性别为空！请填写性别");
			}
		} 
		else
		{
			MessageBox("姓名为空！请填写姓名");
		}
	} 
	else
	{
		MessageBox("学号为空！请填写学号");
	}	
}


BOOL CDataInputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();


	if (nType==1)
	{
		m_Num.SetWindowText(sNum);
		m_Name.SetWindowText(sName);
		m_Gender.SetWindowText(sGender);
		m_Birthday.SetWindowText(sBirthday);
		m_Major.SetWindowText(sMajor);

		sMath.Format("%d",nMath);
		sSports.Format("%d",nSports);
		sEnglish.Format("%d",nEnglish);
		sPhysics.Format("%d",nPhysics);

		m_Math.SetWindowText(sMath);
		m_Sports.SetWindowText(sSports);
		m_English.SetWindowText(sEnglish);
		m_Physics.SetWindowText(sPhysics);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDataInputDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rc;
	GetClientRect(&rc);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP3);
	
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0,0,rc.Width(), rc.Height(), &dcMem,0,0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}

void CDataInputDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnLButtonDown(nFlags, point);
	
	PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(point.x,   point.y));
}
