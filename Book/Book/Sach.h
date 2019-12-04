#ifndef SACH_H_
#define SACH_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Sach
{
private:
	string tenSach;
	string ISBN;
	string NXB;
	string tacGia;
	int giaTien;

	bool hidNXB;
	bool hidtacGia;
	bool hide;
public:
	Sach();
	~Sach();
	Sach(const Sach&);
	Sach(char*, char*, char*, char*, int);
	Sach& operator = (const Sach&);
	void printBook();
	void inputSach();

	string getTenSach();
	string getISBN();
	string getTacGia();
	string getNXB();
	int getGiaTien();
	bool is_hideNXB();
	bool is_hideTG();
	bool is_hideSach();

	void setGiaTien(int);
	void setTenSach(string);
	void setISBN(string);
	void setTacGia(string);
	void setNXB(string);
	void hideNXB();
	void unhideNXB();
	void hideTG();
	void unhideTG();
	void hideBook();
	void unhideBook();

	friend ostream &operator << (ostream&, Sach&);
};

#endif