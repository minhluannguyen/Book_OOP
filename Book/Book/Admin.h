#pragma once

#include <string>
using namespace std;
#include "TaiKhoan.h"
#include "DanhSach.h"

class Admin :public TaiKhoan
{
public:
	Admin();
	Admin(Admin &);
	Admin(string, string);
	virtual ~Admin();
	void menu(DanhSach&);
	void ThemSach(DanhSach&);
	void HideNXB(DanhSach&);
	void HideTG(DanhSach&);
	void UnHideNXB(DanhSach&);
	void UnHideTG(DanhSach&);
	virtual string getNameClass();
	virtual string getTen();
	virtual void setTen(string);
};

