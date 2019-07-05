#pragma once

#include "books.h"

// CDeleteUpdate �Ի���

class CDeleteUpdate : public CDialog
{
	DECLARE_DYNAMIC(CDeleteUpdate)

public:
	CDeleteUpdate(CWnd* pParent = NULL);   // ��׼���캯��
	CDeleteUpdate(int,CString,int);
	virtual ~CDeleteUpdate();

// �Ի�������
	enum { IDD = IDD_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	// //����
	CString bookName;
	// ����
	int bookNumber;
	//���
	int bookId;
	BookList bookList;
	
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedSubmit();
};
