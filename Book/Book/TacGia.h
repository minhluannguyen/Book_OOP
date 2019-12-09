#pragma once
#include <string>
using namespace std;
#include "TaiKhoan.h"
#include "DanhSach.h"

class TacGia: public TaiKhoan
{
private:
	string tenTG;
	vector<Sach*> ListBook;
public:
	TacGia();
	virtual ~TacGia();
	TacGia(TacGia&);
	TacGia(string, string);
	TacGia(string, string, string, DanhSach&);
	bool verify(string, string);
	virtual void menu(DanhSach&, vector<TaiKhoan*>&);
	void ThemSachTG(DanhSach&);
	void XoaSachTG(DanhSach&);
	void SuaSachTG(DanhSach&);
	void updateList(DanhSach&);
	virtual string getNameClass();
	virtual string getTen();
	virtual void setTen(string);
};

