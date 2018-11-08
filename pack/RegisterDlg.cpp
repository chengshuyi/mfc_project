// RegisterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "pack.h"
#include "RegisterDlg.h"
#include "afxdialogex.h"


// CRegisterDlg 对话框

IMPLEMENT_DYNAMIC(CRegisterDlg, CDialogEx)

CRegisterDlg::CRegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegisterDlg::IDD, pParent)
	, str_name(_T(""))
	, str_idnum(_T(""))
	, str_born(_T("-1"))
	, bool_sex_boy(TRUE)
	, bool_sex_girl(FALSE)
	, str_old(_T("-1"))
	, str_pwd(_T(""))
	, no_name(_T("请输入姓名"))
	, no_idnum(_T("请输入身份证号码"))
	, no_pwd(_T("请输入密码"))
	, wrong_name(_T("姓名输入错误"))
	, wrong_idnum(_T("请输入18位身份证号码"))
	, wrong_pwd(_T("密码格式错误"))
	, reg_sucess(_T("注册成功"))
{

}

CRegisterDlg::~CRegisterDlg()
{
}

void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BORN, edit_born);
	DDX_Control(pDX, IDC_BORN, edit_born);
	DDX_Control(pDX, IDC_IDNUM, edit_idnum);
	DDX_Control(pDX, IDC_NAME, edit_name);
	DDX_Control(pDX, IDC_OLD, edit_old);
	DDX_Control(pDX, IDC_PWD, edit_pwd);
	DDX_Control(pDX, IDC_SEX_BOY, chk_sex_boy);
	DDX_Control(pDX, IDC_SEX_GIRL, chk_sex_girl);
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialogEx)
	ON_BN_CLICKED(IDREGISTER, &CRegisterDlg::OnBnClickedRegister)
END_MESSAGE_MAP()


// CRegisterDlg 消息处理程序


void CRegisterDlg::OnBnClickedRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE("REGISTER DIALOG:click REGISTER.\n");

	edit_name.GetWindowText(str_name);
	edit_idnum.GetWindowText(str_idnum);
	edit_born.GetWindowText(str_born);
	bool_sex_boy = chk_sex_boy.GetCheck();
	bool_sex_girl = chk_sex_girl.GetCheck();
	edit_old.GetWindowText(str_old);
	edit_pwd.GetWindowText(str_pwd);

	TRACE("len(name)=%d,len(idnum)=%d,len(pwd)=%d\n",CStringA(str_name).GetLength(),CStringA(str_idnum).GetLength(),CStringA(str_pwd).GetLength());
	TRACE("name = %s , idnum = %s , born = %s , sex = %d , old = %s , pwd = %s.\n",CStringA(str_name),CStringA(str_idnum),CStringA(str_born),bool_sex_boy?1:0,CStringA(str_old),CStringA(str_pwd));

	//check name
	if (CStringA(str_name).GetLength()==0){
		MessageBox(no_name);
		return;
	}
	// check id num
	if (CStringA(str_idnum).GetLength()==0){
		MessageBox(no_idnum);
		return;
	}
	if (CStringA(str_idnum).GetLength()!=18){
		MessageBox(wrong_idnum);
		return;
	}
	//check pwd
	if (CStringA(str_pwd).GetLength()==0){
		MessageBox(no_pwd);
		return;
	}
	if (CStringA(str_pwd).GetLength()<6){
		MessageBox(wrong_pwd);
		return;
	}
	MessageBox(reg_sucess);
	CDialogEx::OnOK();
}

CString CRegisterDlg::get_idnum(){
	return str_idnum;
}

