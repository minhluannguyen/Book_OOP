#include "Messenge.h"



Messenge::Messenge()
{
}

Messenge::Messenge(string receiver, string sender, string ND, time_t dateIn)
{
	nguoiNhan = receiver;
	nguoiGui = sender;
	Mess = ND;
	date = dateIn;
}


Messenge::~Messenge()
{
}

void Messenge::setNguoiNhan(string s)
{
	nguoiNhan = s;
}

void Messenge::setNguoiGui(string s)
{
	nguoiGui = s;
}

void Messenge::setTinNhan(string s)
{
	Mess = s;
}

void Messenge::setTime(time_t t)
{
	date = t;
}
