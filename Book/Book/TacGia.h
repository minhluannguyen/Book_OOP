#pragma once
#include "Header.h"
class TacGia
{
protected:
	string UserName;
	string PassWord;
	DanhSach ListBook;
public:
	TacGia();
	~TacGia();
	TacGia(string, string);
	void ThemSach();
	void XoaSach();
	void SuaSach();
};

