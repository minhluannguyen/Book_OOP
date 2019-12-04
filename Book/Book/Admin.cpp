#include "Admin.h"

Admin::Admin()
{
	
}

Admin::Admin(Admin &)
{

}

Admin::~Admin()
{
}


Admin::Admin(string name, string pass)
{
	UserName = name;
	PassWord = pass;
}

void Admin::ThemSach(DanhSach &DS)
{
	DS.inputBook();
}

void Admin::HideNXB(DanhSach &DS)
{
	DS.printList();
	int n;
	cout << "So thu tu sach muon an: ";
	cin >> n;
	if (n <= 0 || n > DS.getSize())
	{
		cout << "Khong co so thu tu nay!!!";
		_getch();
		return;
	}
	DS.getBook(n - 1).hideNXB();
}

void Admin::HideTG(DanhSach &DS)
{
	DS.printList();
	int n;
	cout << "So thu tu sach muon an: ";
	cin >> n;
	if (n <= 0 || n > DS.getSize())
	{
		cout << "Khong co so thu tu nay!!!";
		_getch();
		return;
	}
	DS.getBook(n - 1).hideTG();
}

void Admin::UnHideNXB(DanhSach &DS)
{
	DS.printList();
	int n;
	cout << "So thu tu sach muon hien: ";
	cin >> n;
	if (n <= 0 || n > DS.getSize())
	{
		cout << "Khong co so thu tu nay!!!";
		_getch();
		return;
	}
	DS.getBook(n - 1).unhideNXB();
}

void Admin::UnHideTG(DanhSach &DS)
{
	DS.printList();
	int n;
	cout << "So thu tu sach muon hien: ";
	cin >> n;
	if (n <= 0 || n > DS.getSize())
	{
		cout << "Khong co so thu tu nay!!!";
		_getch();
		return;
	}
	DS.getBook(n - 1).unhideTG();
}

void Admin::menu(DanhSach &DS)
{
	int choice = 1;
	while (choice != 0)
	{
		system("cls");
		cout << "Xin chao quy khach!\n";
		cout << "1. Them sach." << endl;
		cout << "2. An NXB." << endl;
		cout << "3. An tac gia." << endl;
		cout << "4. Hien NXB." << endl;
		cout << "5. Hien tac gia." << endl;
		cout << "6. In danh sach." << endl;
		cout << "0. Dang xuat.\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;

		if (choice == 0)
			return;
		if (choice == 1)
		{
			ThemSach(DS);
		}
		if (choice == 2)
		{
			HideNXB(DS);
		}
		if (choice == 3)
		{
			HideTG(DS);
		}
		if (choice == 4)
		{
			UnHideNXB(DS);
		}
		if (choice == 5)
		{
			UnHideTG(DS);
		}
		if (choice == 6)
		{
			DS.printList();
			_getch();
		}
	}
}

string Admin::getNameClass()
{
	return "Admin";
}

string Admin::getTen()
{
	return "";
}

void Admin::setTen(string)
{}