#pragma once
#include <vector>
using namespace std;

#include "DanhSach.h"
#include "HoaDon.h"
class DanhsachHoadon
{
private:
	vector<HoaDon> listHD;
public:
	DanhsachHoadon();
	~DanhsachHoadon();
	void inputDSHD(DanhSach&);
	int TinhTien();
	void mergeList(DanhsachHoadon DS);
	void printList();
};

