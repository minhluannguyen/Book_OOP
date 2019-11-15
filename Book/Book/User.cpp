#include "User.h"

User::User()
{
}

User::~User()
{
}

User::User(string name, string pass)
{
	username = name;
	password = pass;
}

void User::xemSach(DanhSach listBook)
{
	int choice = 1;
	while (choice != 0)
	{
		system("cls");
		listBook.printList();
		cout << "Ban muon? ";
		cout << "1. Chon sach." << endl;
		cout << "0. Quay lai.\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;

		if (choice == 1)
		{
			DanhsachHoadon tmpDS;
			tmpDS.inputDSHD(listBook);
			cout << "----------------------------------------------\n";
			cout << "Tong tien: " << tmpDS.TinhTien() << endl;
			cout << "Ban co xac nhan muon mua don hang nay?\n";
			cout << "1. Co.\n2. Khong.\nLua chon cua ban: ";
			int choice;
			cin >> choice;
			cin.ignore();
			if (choice == 1)
			{
				DSHD.mergeList(tmpDS);
				cout << "Giao dich thanh cong!!! Cam on ban da mua sach.\n";
				_getch();
			}
				return;
		}
	}
}

void User::menu(DanhSach listBook)
{
	int choice = 1;
	while (choice != 0)
	{
		system("cls");
		cout << "Xin chao quy khach!\n";
		cout << "1. Xem sach." << endl;
		cout << "2. Xem danh sach hoa don." << endl;
		cout << "0. Dang xuat.\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;

		if (choice == 0)
			return;
		if (choice == 1)
		{
			xemSach(listBook);
		}
		if (choice == 2)
		{
			system("cls");
			DSHD.printList();
			_getch();
		}
	}
}

void User::TimSach(DanhsachHoadon BillList)
{
	system("cls");
	ifstream fi("user.txt");
	vector<User> DSUser;
	if (fi.is_open())
	{
		int n;
		fi >> n;
		for (int i = 0; i < n; i++)
		{
			User utmp;
			int tmpTuoi;
			string tmp;
			fi >> tmp;
			utmp.username = tmp;
			fi >> tmp;
			utmp.password = tmp;

			DSUser.push_back(utmp);
		}
	}
	fi.close();
	string tmpName, tmpPass;
	bool isCorrect = false;
	while (!(isCorrect))
	{
		cout << "Moi ban dang nhap: \n";
		cout << "Username: ";
		cin >> tmpName;
		cout << "Password: ";
		//coi file user.txt
		cin >> tmpPass;
		vector<User> ::iterator it;
		for (it = DSUser.begin(); it != DSUser.end(); ++it)
		{
			if ((*it).username == tmpName)
			{
				if ((*it).password == tmpPass)
				{
					isCorrect = true;
					break;
				}
			}
		}
		if (!(isCorrect))
		{
			cout << "Sai username hoac password, moi nhap lai!\n";
		}
		else
			cout << "Dang nhap thanh cong!\n";
	}
	cout << "--------------------------------------------------------\n";
	cout << "Tong tien: " << BillList.TinhTien() << endl;
	cout << "Ban co xac nhan muon mua don hang nay?\n";
	cout << "1. Co.\n2. Khong.\nLua chon cua ban: ";
	int choice;
	cin >> choice;
	cin.ignore();
	if (choice == 1)
	{
		cout << "Giao dich thanh cong!!! Cam on ban da mua sach.\n";
		_getch();
	}
	else
	{
		return;
	}
}