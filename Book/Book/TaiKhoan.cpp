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

void TaiKhoan::messMenu(vector<TaiKhoan*> &TK)
{
	int choice = 1;
	while (choice != 0)
	{
		system("cls");
		cout << "Tin nhan\n";
		cout << "1. Xem tin da nhan." << endl;
		cout << "2. Xem tin da gui." << endl;
		cout << "3. Soan tin nhan." << endl;
		cout << "0. Thoat.\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;
		cin.ignore();

		if (choice == 0)
			return;
		if (choice == 1)
		{
			for (int i = 0; i < Tin_da_nhan.size(); i++)
			{
				cout << "[" << Tin_da_nhan[i].getNguoiGui() << "] " << Tin_da_nhan[i].getMess() << endl;
			}
		}
		if (choice == 2)
		{
			for (int i = 0; i < Tin_da_goi.size(); i++)
			{
				cout << "[" << Tin_da_goi[i].getNguoiNhan() << "] " << Tin_da_goi[i].getMess() << endl;
			}
		}
		if (choice == 3)
		{
			nhanTin(*this, TK);
		}

		_getch();
	}
}

void TaiKhoan::nhanTin(TaiKhoan &sender, vector<TaiKhoan*> &TK)
{
	string nguoiGui, nguoiNhan, ND;
	bool ok = false;
	cout << "Nguoi nhan (username nguoi nhan): ";
	getline(cin, nguoiNhan);
	vector<TaiKhoan*>::iterator it;
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
		cout << "Nguoi nhan khong ton tai!";
		_getch();
		return;
	}
	else
	{
		nguoiGui = sender.UserName;
		cout << "Noi dung tin nhan: ";
		getline(cin, ND);
	}
	Messenge M(nguoiNhan, nguoiGui, ND);
	(*it)->Tin_da_nhan.push_back(M);
	Tin_da_goi.push_back(M);
	
	cout << "Tin da duoc goi!!!";
}

void TaiKhoan::readFileMess()
{
	string filename = UserName + "_mess.txt";
	ifstream fi(filename);
	if (fi.is_open())
	{
		int n;
		fi >> n;
		fi.ignore();
		for (int i = 0; i < n; i++)
		{
			Messenge tmpMess;
			fi >> tmpMess;
			Tin_da_nhan.push_back(tmpMess);
		}

		fi >> n;
		fi.ignore();
		for (int i = 0; i < n; i++)
		{
			Messenge tmpMess;
			fi >> tmpMess;
			Tin_da_goi.push_back(tmpMess);
		}
	}
	fi.close();
}

void TaiKhoan::writeFileMess()
{
	string filename = UserName + "_mess.txt";
	ofstream fo(filename);
	if (fo.is_open())
	{
		int n = Tin_da_nhan.size();
		fo << n << endl;
		for (int i = 0; i < n; i++)
		{
			fo << Tin_da_nhan[i];
		}

		n = Tin_da_goi.size();
		fo << n << endl;
		for (int i = 0; i < n; i++)
		{
			fo << Tin_da_goi[i];
		}
	}
	fo.close();
}
