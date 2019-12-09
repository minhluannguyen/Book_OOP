#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>
using namespace std;

#include "Messenge.h"
#include "DanhSach.h"

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
	virtual void menu(DanhSach&, vector<TaiKhoan*>&) = 0;
	string getUsername();

	void receiveMess(Messenge);
	void messMenu(vector<TaiKhoan*>&);
	void nhanTin(TaiKhoan&, vector<TaiKhoan*>&);
	void readFileMess();
	void writeFileMess();
};

