#include "Header.h"



HoaDon::HoaDon()
{
	Soluong = 0;
}


HoaDon::~HoaDon()
{
}

void HoaDon::ThemSach(Sach book, int count)
{
	S = book;
	Soluong = count;
}

int HoaDon::getTien()
{
	return S.getGiaTien()*Soluong;
}