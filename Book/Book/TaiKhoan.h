#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
using namespace std;

#include "Messenge.h"

class TaiKhoan
{
protected:
	string UserName;
	string PassWord;
	vector<Messenge> Tin_da_nhan;
	vector<Messenge> Tin_da_goi;
public:
	TaiKhoan();
	TaiKhoan(TaiKhoan&);
	TaiKhoan(string, string);
	bool verify(string, string);
	virtual string getNameClass() = 0;
	TaiKhoan &operator = (TaiKhoan&);
	virtual ~TaiKhoan() = 0;
	void newAcc();
	void writeFile(ostream &os);
	virtual string getTen() = 0;
	virtual void setTen(string) = 0;
	string getUsername();

	void receiveMess(Messenge);
	void nhanTin(TaiKhoan&, vector<TaiKhoan*>);
};

