#include "TacGia.h"


TacGia::TacGia()
{
}

TacGia::TacGia(TacGia &TG)
{
	ListBook = TG.ListBook;
}

TacGia::~TacGia()
{
}

TacGia::TacGia(string name, string user, string pass, DanhSach &DS)
{
	UserName = user;
	PassWord = pass;
	tenTG = name;

	for (int i = 0; i < DS.getSize(); i++)
	{
		if (!DS.getBook(i).is_hideNXB() && tenTG == DS.getBook(i).getNXB())
			ListBook.push_back(&DS.getBook(i));
	}
}

bool TacGia::verify(string name, string pass)
{
	if (name == UserName && pass == PassWord)
		return true;
	return false;
}

void TacGia::menu(DanhSach &DS, vector<TaiKhoan*> &TK)
{
	int choice = 1;
	while (choice != 0)
	{
		system("cls");
		cout << "Xin chao quy khach!\n";
		cout << "1. Them sach." << endl;
		cout << "2. Xoa sach." << endl;
		cout << "3. Sua sach." << endl;
		cout << "4. Tin nhan." << endl;
		cout << "0. Dang xuat.\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;

		if (choice == 0)
			return;
		if (choice == 1)
		{
			ThemSachTG(DS);
		}
		if (choice == 2)
		{
			XoaSachTG(DS);
		}
		if (choice == 3)
		{
			SuaSachTG(DS);
		}
		if (choice == 4)
		{
			messMenu(TK);
		}
	}
}

void TacGia::ThemSachTG(DanhSach &DS)
{
	//DS.inputBook();
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
		cout << "NXB: ";
		cin >> tmpS;
		tmp.setNXB(tmpS);
		tmp.setTacGia(tenTG);
		cout << "Gia tien: ";
		cin >> num;
		cin.ignore();
		DS.addBook(tmp);
	}

	updateList(DS);
}

void TacGia::XoaSachTG(DanhSach &DS)
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

void TacGia::SuaSachTG(DanhSach &DS)
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

void TacGia::updateList(DanhSach &DS)
{
	ListBook.clear();
	for (int i = 0; i < DS.getSize(); i++)
	{
		if (!DS.getBook(i).is_hideNXB() && tenTG == DS.getBook(i).getNXB())
			ListBook.push_back(&DS.getBook(i));
	}
}

string TacGia::getNameClass()
{
	return "TacGia";
}

string TacGia::getTen()
{
	return tenTG;
}

void TacGia::setTen(string s)
{
	tenTG = s;
}
