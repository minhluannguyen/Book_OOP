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
	virtual ~User();
	User(const User&);
	User(string, string);
	virtual void menu(DanhSach&, vector<TaiKhoan*>&);
	void xemSach(DanhSach listBook);
	//void TimSach(DanhsachHoadon);
	virtual string getNameClass();
	virtual string getTen();
	virtual void setTen(string);
};