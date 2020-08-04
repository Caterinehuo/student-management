#if !defined(AFX_DATAINPUTDLG_H__01E82843_C13A_4778_8F9C_DC5AA29E4449__INCLUDED_)
#define AFX_DATAINPUTDLG_H__01E82843_C13A_4778_8F9C_DC5AA29E4449__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataInputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataInputDlg dialog

class CDataInputDlg : public CDialog
{
// Construction
public:
	CDataInputDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDataInputDlg)
	enum { IDD = IDD_DATAINPUT };
	CEdit	m_Sports;
	CEdit	m_Physics;
	CEdit	m_Num;
	CEdit	m_Name;
	CEdit	m_Math;
	CEdit	m_Major;
	CEdit	m_Gender;
	CEdit	m_English;
	CEdit	m_Birthday;
	//}}AFX_DATA

	CString sNum;
	CString sName;
	CString sGender;
	CString sBirthday;
	CString sMajor;
	int nMath;
	int nEnglish;
	int nSports;
	int nPhysics;

	CString sMath;
	CString sEnglish;
	CString sSports;
	CString sPhysics;

	int nType;//0代表添加，1代表修改

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDataInputDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAINPUTDLG_H__01E82843_C13A_4778_8F9C_DC5AA29E4449__INCLUDED_)
