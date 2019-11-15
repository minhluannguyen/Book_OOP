#pragma once
#include "Header.h"
class NXB
{
protected:
	string UserName;
	string PassWord;
	DanhSach ListBook;
public:
	NXB();
	~NXB();
	NXB(string, string);
	bool verify(string, string);
	void ThemSach();
	void XoaSach();
	void SuaSach();
	void printList();
};

