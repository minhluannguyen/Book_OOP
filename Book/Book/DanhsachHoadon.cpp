#include "Header.h"

DanhsachHoadon::DanhsachHoadon()
{
}


DanhsachHoadon::~DanhsachHoadon()
{
}

void DanhsachHoadon::inputDSHD(DanhSach &listS)
{
	int i = 0, choice = 0;
	while (choice != 2)
	{
		i++;
		Sach tmpB;
		char s[50];
		cout << "----------------------------------------------\n";
		cout << "Moi ban nhap ten sach can tim: ";
		cin >> s;
		int id = listS.searchBook_name(s);
		while (id == -1)
		{
			cout << "\nMoi nhap lai: ";
			cin >> s;
			id = listS.searchBook_name(s);
		}
		
		tmpB = listS.getBook(id);
		cout << "Sach ban da chon: \n";
		cout << i << ".\n";
		tmpB.printBook();
		cout << "Nhap so luong sach muon mua: ";
		int num;
		cin >> num;
		cin.ignore();
		HoaDon HD;
		HD.ThemSach(tmpB, num);
		listHD.push_back(HD);
		cout << "-------------------\n";
		cout << "Ban muon lam gi tiep theo?\n";
		cout << "1. Chon them sach." << endl;
		cout << "2. Mua sach" << endl;
		cout << "Lua chon cua ban: ";
		cin >> choice;
		if (choice == 2)
			return;
	}
}

int DanhsachHoadon::TinhTien()
{
	int sum = 0;
	vector<HoaDon> ::iterator it;
	for (it = listHD.begin(); it != listHD.end(); ++it)
	{
		sum = sum + (*it).getTien();
	}
	return sum;
}

void DanhsachHoadon::mergeList(DanhsachHoadon DS)
{
	for (int i = 0; i < DS.listHD.size(); i++)
	{
		listHD.push_back(DS.listHD[i]);
	}
}

void DanhsachHoadon::printList()
{
	if (listHD.size() > 0)
	{
		for (int i = 0; i < listHD.size(); i++)
		{
			cout << i + 1 << "_____" << endl;
			listHD[i].printHD();
		}
		cout << "Total: " << TinhTien() << endl;
	}
	else
	{
		cout << "Hoa don rong!!!\n";
		_getch();
	}
}