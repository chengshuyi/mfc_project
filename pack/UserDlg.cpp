// UserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "pack.h"
#include "UserDlg.h"
#include "afxdialogex.h"


// CUserDlg �Ի���

IMPLEMENT_DYNAMIC(CUserDlg, CDialogEx)

CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUserDlg::IDD, pParent)
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialogEx)
END_MESSAGE_MAP()


// CUserDlg ��Ϣ�������
