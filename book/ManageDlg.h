#pragma once
#include "afxcmn.h"
#include "books.h"

// CManageDlg �Ի���

class CManageDlg : public CDialog
{
	DECLARE_DYNAMIC(CManageDlg)
 
public:
	CManageDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CManageDlg();

// �Ի�������
	enum { IDD = IDD_MANAGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	
	// //ͼ���б�
	CListCtrl bookList;
	
	BookList books;
	
	void showAll();

	afx_msg void OnBnClickedButtonSearch();
	
	virtual BOOL OnInitDialog();
	
	//ͼ����
	CString bookId;
	afx_msg void OnBnClickedButtonShowall();
	afx_msg void OnBnClickedButtonAddbook();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonUpdate();
};
