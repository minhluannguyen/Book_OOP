#pragma once

//#include <string>
//using namespace std;

#include "TaiKhoan.h"
#include "DanhSach.h"
//#include "Header.h"

class NXB :public TaiKhoan
{
private:
	string tenNXB;
	vector<Sach*> ListBook;
public:
	NXB();
	virtual ~NXB();
	NXB(NXB&);
	NXB(string, string);
	NXB(string, string, string, DanhSach&);
	bool verify(string, string);
	void menu(DanhSach&);
	void ThemSachNXB(DanhSach&);
	void XoaSachNXB(DanhSach&);
	void SuaSachNXB(DanhSach&);
	void updateList(DanhSach&);
	virtual string getNameClass();
	virtual string getTen();
	virtual void setTen(string);
};

