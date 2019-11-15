#pragma once
#include "Header.h"
class HoaDon
{
private:
	Sach S;
	int Soluong;
public:
	HoaDon();
	~HoaDon();
	void ThemSach(Sach, int);
	void TinhTien();
	int getTien();
	void printHD();
};