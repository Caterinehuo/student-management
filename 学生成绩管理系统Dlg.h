// 学生成绩管理系统Dlg.h : header file
//

#if !defined(AFX_DLG_H__AF559D82_08C6_4309_8BDC_28C4CDE24506__INCLUDED_)
#define AFX_DLG_H__AF559D82_08C6_4309_8BDC_28C4CDE24506__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "vector"
#include "StudentData.h"

#include "DataInputDlg.h"
#include "LoginDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CEdit	m_InputNum;
	CListCtrl	m_DataList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
	CDataInputDlg m_DataInputDlg;
	CLoginDlg m_LoginDlg;
	std::vector<CStudentData> m_AllStudentData;
	std::vector<CStudentData>::iterator i_AllStudentData;
public:
	void ReadFile();
	void SaveFile();
	void ShowAllData();

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnAdddata();
	afx_msg void OnRevisedata();
	afx_msg void OnDeletedata();
	afx_msg void OnSearchdata();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__AF559D82_08C6_4309_8BDC_28C4CDE24506__INCLUDED_)
