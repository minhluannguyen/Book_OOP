#include "Messenge.h"



Messenge::Messenge()
{
}

Messenge::Messenge(string receiver, string sender, string ND)
{
	nguoiNhan = receiver;
	nguoiGui = sender;
	Mess = ND;
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

string Messenge::getNguoiNhan()
{
	return nguoiNhan;
}

string Messenge::getNguoiGui()
{
	return nguoiGui;
}

string Messenge::getMess()
{
	return Mess;
}

ostream & operator<<(ostream &os, Messenge &M)
{
	os << M.nguoiNhan << endl;
	os << M.nguoiGui << endl;
	os << M.Mess << endl;
	return os;
}

istream & operator>>(istream &is, Messenge &M)
{
	getline(is, M.nguoiNhan);
	getline(is, M.nguoiGui);
	getline(is, M.Mess);
	return is;
}