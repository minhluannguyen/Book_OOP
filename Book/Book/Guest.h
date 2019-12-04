#pragma once

#include "TaiKhoan.h"
#include "DanhSach.h"

class Guest
{
public:
	Guest();
	~Guest();
	void xemSach(DanhSach&, vector<TaiKhoan*> &TK);
};