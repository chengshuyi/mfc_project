// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "pack.h"
#include "MainDlg.h"
#include "afxdialogex.h"


// CMainDlg 对话框

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDlg::IDD, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDLEFT, &CMainDlg::OnBnClickedLeft)
END_MESSAGE_MAP()


// CMainDlg 消息处理程序


void CMainDlg::OnBnClickedLeft()
{
	// TODO: 在此添加控件通知处理程序代码
}
