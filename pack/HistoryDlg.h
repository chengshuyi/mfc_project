#pragma once


// CHistoryDlg �Ի���

class CHistoryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHistoryDlg)

public:
	CHistoryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHistoryDlg();

// �Ի�������
	enum { IDD = IDD_HISTORY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
};
