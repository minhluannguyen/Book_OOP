#pragma once
#include "Header.h"
class DanhsachHoadon
{
private:
	vector<HoaDon> listHD;
public:
	DanhsachHoadon();
	~DanhsachHoadon();
	void inputDSHD(DanhSach&);
	int TinhTien();
};

