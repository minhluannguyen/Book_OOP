#include "NXB.h"



NXB::NXB()
{
}


NXB::~NXB()
{
}

NXB::NXB(string name, string pass)
{
	UserName = name;
	PassWord = pass;
}

bool NXB::verify(string name, string pass)
{
	if (name == UserName && pass == PassWord)
		return true;
	return false;
}

void NXB::ThemSach()
{
	ListBook.inputBook();
}

void NXB::XoaSach()
{
	ListBook.printList();
	int n;
	cout << "So thu tu sach muon xoa: ";
	cin >> n;
	ListBook.deleteBook(n);
}

void NXB::SuaSach()
{
	int n;
	ListBook.printList();
	cout << "So thu tu sach can sua: ";
	cin >> n;
	//ListBook.updateList(n);
}

void NXB::printList()
{
	//ListBook.printList();
}