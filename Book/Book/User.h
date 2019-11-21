#pragma once

#include <fstream>
#include <conio.h>
using namespace std;

#include "TaiKhoan.h"
#include "DanhsachHoadon.h"

class User: public TaiKhoan
{
private:
	DanhsachHoadon DSHD;
public:
	User();
	~User();
	User(const User&);
	User(string, string);
	void menu(DanhSach listBook);
	void xemSach(DanhSach listBook);
	void TimSach(DanhsachHoadon);
};