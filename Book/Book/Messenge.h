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
	time_t date;
public:
	Messenge();
	Messenge(string, string, string, time_t);
	~Messenge();
	void setNguoiNhan(string);
	void setNguoiGui(string);
	void setTinNhan(string);
	void setTime(time_t);
};

