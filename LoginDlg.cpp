// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "—ß…˙≥…º®π‹¿ÌœµÕ≥.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Control(pDX, IDC_PASSWORD, m_Password);
	DDX_Control(pDX, IDC_ACCOUNT, m_Account);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnOK() 
{
	CString sAccount;
	CString sPassword;
	m_Account.GetWindowText(sAccount);
	m_Password.GetWindowText(sPassword);
	if (sAccount.IsEmpty())
	{
		MessageBox("«Î ‰»Î’À∫≈");
	} 
	else
	{
		if (sPassword.IsEmpty())
		{
			MessageBox("«Î ‰»Î√‹¬Î");
		} 
		else
		{
			if (sAccount.Compare("Admin")==0)
			{
				if (sPassword.Compare("888888")==0)
				{
					CDialog::OnOK();
				} 
				else
				{
					MessageBox("√‹¬Î¥ÌŒÛ£°");
				}
			} 
			else
			{
				MessageBox("’À∫≈¥ÌŒÛ£°");
			}
		}
	}
}

void CLoginDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rc;
	GetClientRect(&rc);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP1);
	
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0,0,rc.Width(), rc.Height(), &dcMem,0,0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}

void CLoginDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
	PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(point.x,   point.y));
}
