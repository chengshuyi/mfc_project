// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "pack.h"
#include "LoginDlg.h"
#include "afxdialogex.h"

#include "protocol.h"
#include "sendByTCP.h"
#include "RegisterDlg.h"

// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
	, user_idnum(_T(""))
	, user_pwd(_T(""))
	, idnum_wrong(_T("请输入18位身份证号码"))
	, pwd_wrong(_T("密码错误"))
	, idnum_no_exist(_T("该用户不存在"))
	, pwd_no_exist(_T("请输入密码"))
	, login_sucess(_T("登陆成功!"))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_IDNUM, user_idnum);
	DDX_Text(pDX, IDC_IDNUM, user_idnum);
	DDV_MaxChars(pDX, user_idnum, 18);
	//  DDX_Text(pDX, IDC_PWD, user_pwd);
	//  DDV_MaxChars(pDX, user_pwd, 17);
	DDX_Text(pDX, IDC_PWD, user_pwd);
	DDV_MaxChars(pDX, user_pwd, 17);
	//  DDX_Control(pDX, IDC_IDNUM, idnum_edit);
	DDX_Control(pDX, IDC_IDNUM, idnum_edit);
	DDX_Control(pDX, IDC_PWD, pwd_edit);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDLOGIN, &CLoginDlg::OnBnClickedLogin)
	ON_WM_SYSCOMMAND()
    ON_BN_CLICKED(IDREGISTER, &CLoginDlg::OnBnClickedRegister)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;
}


void CLoginDlg::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	idnum_edit.GetWindowText(user_idnum);
	pwd_edit.GetWindowText(user_pwd);

#ifdef _DEBUG
	// test account
	if(user_idnum.Compare(_T("admin"))==0 && user_pwd.Compare(_T("admin"))==0){
		MessageBox(login_sucess);
		CDialogEx::OnOK();
		return;
	}
#endif

	if (CStringA(user_idnum).GetLength()!=18){
		MessageBox(idnum_wrong);
		return;
	}

	if (CStringA(user_idnum).GetLength()==0){
		MessageBox(pwd_no_exist);
		return;
	}

	//check user password
	struct user u;
	u.idnum_len = 18;
	memcpy(u.idnum,user_idnum,18);
	//strcpy(u.idnum,(LPCTSTR)user_idnum);

	sendByTCP s;
	s.initSocket("127.0.0.1",4000);
	s.sendData((char*)&u,sizeof(u),GETPASSWORD);
	if(s.recvData((char*)&u,sizeof(u))){
		CString cs1,cs2;
		cs1 = u.idnum;
		cs2 = u.pwd;
		if(user_idnum.CompareNoCase(cs1)==0 && user_pwd.Compare(cs2)==0){
			MessageBox(login_sucess);
			CDialogEx::OnOK();
			return;
		}else{
			MessageBox(pwd_wrong);
		}
	}
}

CString CLoginDlg::get_idnum(){
	return user_idnum;
}


void CLoginDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnSysCommand(nID, lParam);
}


//void CLoginDlg::OnIdcancel()
//{
//	// TODO: 在此添加命令处理程序代码
//}


void CLoginDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	TRACE("click x.\n");
	CDialogEx::OnCancel();
}


void CLoginDlg::OnBnClickedRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE("LOGIN DIALOG: click REGISTER.\n");
	CRegisterDlg dlg;
	INT_PTR nResponse = dlg.DoModal();
	CString idnum = dlg.get_idnum();
	idnum_edit.SetWindowText(idnum);
}
