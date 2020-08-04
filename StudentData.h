// StudentData.h: interface for the CStudentData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENTDATA_H__0638382B_8CE9_43C1_AEA6_BBFD31A90872__INCLUDED_)
#define AFX_STUDENTDATA_H__0638382B_8CE9_43C1_AEA6_BBFD31A90872__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStudentData  
{
public:
	CString sNum;
	CString sName;
	CString sGender;
	CString sBirthday;
	CString sMajor;
	int nMath;
	int nEnglish;
	int nSports;
	int nPhysics;


	CStudentData();
	virtual ~CStudentData();

};

#endif // !defined(AFX_STUDENTDATA_H__0638382B_8CE9_43C1_AEA6_BBFD31A90872__INCLUDED_)
