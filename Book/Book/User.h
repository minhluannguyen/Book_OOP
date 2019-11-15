#pragma once
#include "Header.h"
class User: public Guest
{
private:
	string username;
	string password;
	int tuoi;
public:
	User();
	~User();
	void TimSach(DanhsachHoadon);
};