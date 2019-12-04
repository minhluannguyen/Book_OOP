#include "NXB.h"

NXB::NXB()
{
}

NXB::NXB(NXB &XB)
{
	tenNXB = XB.tenNXB;
	ListBook = XB.ListBook;
}

NXB::NXB(string name, string user, string pass, DanhSach &DS)
{
	UserName = user;
	PassWord = pass;
	tenNXB = name;

	for (int i = 0; i < DS.getSize(); i++)
	{
		if (!DS.getBook(i).is_hideNXB() && tenNXB == DS.getBook(i).getNXB())
			ListBook.push_back(&DS.getBook(i));
	}
}


NXB::~NXB()
{
}

bool NXB::verify(string name, string pass)
{
	if (name == UserName && pass == PassWord)
		return true;
	return false;
}

void NXB::menu(DanhSach &DS)
{
	int choice = 1;
	while (choice != 0)
	{
		system("cls");
		cout << "Xin chao quy khach!\n";
		cout << "1. Them sach." << endl;
		cout << "2. Xoa sach." << endl;
		cout << "3. Sua sach." << endl;
		cout << "0. Dang xuat.\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;

		if (choice == 0)
			return;
		if (choice == 1)
		{
			ThemSachNXB(DS);
		}
		if (choice == 2)
		{
			XoaSachNXB(DS);
		}
		if (choice == 3)
		{
			SuaSachNXB(DS);
		}
	}
}

void NXB::ThemSachNXB(DanhSach &DS)
{
	cout << "So luong sach muon nhap: ";
	int n;
	string tmpS;
	cin >> n;
	cin.ignore();
	int num;
	for (int i = 0; i < n; i++) {
		Sach tmp;
		cout << "Nhap thong tin sach thu " << i + 1 << ":\n";
		//tmp.inputSach();
		cout << "Ten sach: ";
		cin >> tmpS;
		tmp.setTenSach(tmpS);
		cout << "ISBN: ";
		cin >> tmpS;
		tmp.setISBN(tmpS);
		tmp.setNXB(tenNXB);
		cout << "NXB: ";
		cin >> tmpS;
		tmp.setTacGia(tmpS);
		cout << "Gia tien: ";
		cin >> num;
		cin.ignore();
		DS.addBook(tmp);
	}

	updateList(DS);
}

void NXB::XoaSachNXB(DanhSach &DS)
{
	system("cls");
	for (int i = 0; i < ListBook.size(); i++)
	{
		ListBook[i]->printBook();
	}
	//DS.printList();
	int n;
	cout << "So thu tu sach muon xoa: ";
	cin >> n;
	if (n <= 0 || n > ListBook.size())
	{
		cout << "Khong co so thu tu nay!!!";
		_getch();
		return;
	}

	ListBook[n - 1]->hideNXB();
	updateList(DS);
	//DS.deleteBook(n);
}

void NXB::SuaSachNXB(DanhSach &DS)
{
	system("cls");
	for (int i = 0; i < ListBook.size(); i++)
	{
		ListBook[i]->printBook();
	}
	//DS.printList();
	int n;
	cout << "So thu tu sach can sua: ";
	cin >> n;
	if (n <= 0 || n > ListBook.size())
	{
		cout << "Khong co so thu tu nay!!!";
		_getch();
		return;
	}
	Sach tmpS;
	tmpS.inputSach();
	*ListBook[n - 1] = tmpS;
	//DS.updateBook(tmpS, n - 1);
	updateList(DS);
	cout << "Sach da duoc sua!!!";
	_getch();
}

void NXB::updateList(DanhSach &DS)
{
	ListBook.clear();
	for (int i = 0; i < DS.getSize(); i++)
	{
		if (!DS.getBook(i).is_hideNXB() && tenNXB == DS.getBook(i).getNXB())
			ListBook.push_back(&DS.getBook(i));
	}
}

string NXB::getNameClass()
{
	return "NXB";
}

string NXB::getTen()
{
	return tenNXB;
}

void NXB::setTen(string s)
{
	tenNXB = s;
}
