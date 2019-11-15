#pragma once
#include "Header.h"
class User
{
private:
	string username;
	string password;
	DanhsachHoadon DSHD;
public:
	User();
	~User();
	User(string, string);
	void menu(DanhSach listBook);
	void xemSach(DanhSach listBook);
	void TimSach(DanhsachHoadon);
};