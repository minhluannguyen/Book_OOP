#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <time.h>

class Messenge
{
private:
	string nguoiNhan;
	string nguoiGui;
	string Mess;
public:
	Messenge();
	Messenge(string, string, string);
	~Messenge();
	void setNguoiNhan(string);
	void setNguoiGui(string);
	void setTinNhan(string);

	string getNguoiNhan();
	string getNguoiGui();
	string getMess();

	friend ostream &operator<<(ostream&, Messenge&);
	friend istream &operator>>(istream&, Messenge&);
};

