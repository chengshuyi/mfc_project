// sendJson.cpp : 实现文件
//

#include "stdafx.h"
#include "pack.h"
#include "sendJson.h"
#include "afxdialogex.h"


// sendJson 对话框

IMPLEMENT_DYNAMIC(sendJson, CDialogEx)

sendJson::sendJson(CWnd* pParent /*=NULL*/)
	: CDialogEx(sendJson::IDD, pParent)
{

}

sendJson::~sendJson()
{
}

void sendJson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(sendJson, CDialogEx)
END_MESSAGE_MAP()


// sendJson 消息处理程序
