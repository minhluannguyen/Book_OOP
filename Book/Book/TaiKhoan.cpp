#include "TaiKhoan.h"



TaiKhoan::TaiKhoan()
{
}

TaiKhoan::TaiKhoan(TaiKhoan& TK)
{
	UserName = TK.UserName;
	PassWord = TK.PassWord;
}

TaiKhoan::TaiKhoan(string user, string pass)
{
	UserName = user;
	PassWord = pass;
}

TaiKhoan &TaiKhoan::operator=(TaiKhoan &TK)
{
	this->UserName = TK.UserName;
	this->PassWord = TK.PassWord;

	return *this;
}

bool TaiKhoan::verify(string name, string pass)
{
	if (name == UserName && pass == PassWord)
		return true;
	return false;
}

TaiKhoan::~TaiKhoan()
{
}

void TaiKhoan::newAcc()
{
	cout << "Ten tai khoan moi: ";
	getline(cin, UserName);
	cout << "Mat khau moi: ";
	getline(cin, PassWord);
}

void TaiKhoan::writeFile(ostream & os)
{
	os << UserName << endl;
	os << PassWord << endl;
}

string TaiKhoan::getUsername()
{
	return UserName;
}

void TaiKhoan::receiveMess(Messenge M)
{
	Tin_da_nhan.push_back(M);
}

void TaiKhoan::nhanTin(TaiKhoan &sender, vector<TaiKhoan*> TK)
{
	string nguoiGui, nguoiNhan, ND;
	time_t date;
	bool ok = false;
	cout << "Nguoi nhan (username nguoi nhan): ";
	getline(cin, nguoiNhan);
	vector<TaiKhoan*> ::iterator it;
	for (it = TK.begin(); it != TK.end(); it++)
	{
		if (nguoiNhan == (*it)->getUsername())
		{
			ok = true;
			break;
		}
	}

	if (!ok)
	{
		cout << "Nguoi nhan ban nhap khong ton tai!";
		_getch();
		return;
	}
	else
	{
		nguoiGui = sender.UserName;
		cout << "Noi dung tin nhan: ";
		getline(cin, ND);
		time(&date);
	}
	Messenge M(nguoiNhan, nguoiGui, ND, date);
	(*it)->Tin_da_nhan.push_back(M);
	Tin_da_goi.push_back(M);
}
