#include "TacGia.h"



TacGia::TacGia()
{
}


TacGia::~TacGia()
{
}

TacGia::TacGia(string name, string pass)
{
	UserName = name;
	PassWord = pass;
}

void TacGia::ThemSach()
{
	ListBook.inputBook();
}

void TacGia::XoaSach()
{
	ListBook.printList();
	int n;
	cout << "So thu tu sach muon xoa: ";
	cin >> n;
	ListBook.deleteBook(n);
}

void TacGia::SuaSach()
{
	int n;
	ListBook.printList();
	cout << "So thu tu sach can sua: ";
	cin >> n;
	//ListBook.updateList(n);
}