// DeleteUpdate.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "book.h"
#include "DeleteUpdate.h"
#include "ManageDlg.h"


// CDeleteUpdate �Ի���

IMPLEMENT_DYNAMIC(CDeleteUpdate, CDialog)

CDeleteUpdate::CDeleteUpdate(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteUpdate::IDD, pParent)
	,bookId(0)
	, bookName()
	, bookNumber()
{

}

CDeleteUpdate::CDeleteUpdate(int id,CString bn,int bnum)
: CDialog(CDeleteUpdate::IDD, NULL)
,bookId(id)
, bookName(bn)
, bookNumber(bnum)
{
	
}

CDeleteUpdate::~CDeleteUpdate()
{
}

void CDeleteUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, bookName);
	DDX_Text(pDX, IDC_EDIT_NUMBER, bookNumber);
}


BEGIN_MESSAGE_MAP(CDeleteUpdate, CDialog)
	ON_BN_CLICKED(IDCANCEL, &CDeleteUpdate::OnBnClickedCancel)
	ON_BN_CLICKED(IDSUBMIT, &CDeleteUpdate::OnBnClickedSubmit)
END_MESSAGE_MAP()


// CDeleteUpdate ��Ϣ�������

BOOL CDeleteUpdate::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDeleteUpdate::OnBnClickedCancel()
{
	OnCancel();
}

void CDeleteUpdate::OnBnClickedSubmit()
{
	if(bookId==0){
		Book book;
		UpdateData(TRUE);
		UpdateData(FALSE);
		book.name=bookName.GetBuffer(0);
		book.number=bookNumber;
		bookList.addBook(book);
	}
	else{
		Book book;
		UpdateData(TRUE);
		UpdateData(FALSE);
		book.id=bookId;
		book.name=bookName.GetBuffer(0);
		book.number=bookNumber;
		bookList.updateBook(book);
	}
	OnCancel();
	
}
