#pragma once
#include "afxwin.h"


// CLoginDlg �Ի���

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginDlg();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedLogin();

	CString get_idnum();
private:
	CString user_idnum;
	CString user_pwd;
	CEdit idnum_edit;
	CEdit pwd_edit;

	CString idnum_wrong;
	CString pwd_wrong;
	CString idnum_no_exist;
	CString pwd_no_exist;
	CString login_sucess;

public:
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	virtual void OnCancel();
	afx_msg void OnBnClickedRegister();
};
