#pragma once
#include "afxwin.h"


// CRegisterDlg �Ի���

class CRegisterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRegisterDlg)

public:
	CRegisterDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRegisterDlg();

// �Ի�������
	enum { IDD = IDD_REGISTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRegister();
	CString get_idnum();
//	CEdit edit_born;
private:
	CEdit edit_born;
	CEdit edit_idnum;
	CEdit edit_name;
	CEdit edit_old;
	CEdit edit_pwd;
	CButton chk_sex_boy;
	CButton chk_sex_girl;

	CString str_name;
	CString str_idnum;
	CString str_born;
	BOOL bool_sex_boy;
	BOOL bool_sex_girl;
	CString str_old;
	CString str_pwd;


	CString no_name;
	CString no_idnum;
	CString no_pwd;
	CString wrong_name;
	CString wrong_idnum;
	CString wrong_pwd;
	CString reg_sucess;
};
