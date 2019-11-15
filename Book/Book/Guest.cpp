#include "Header.h"



Guest::Guest()
{
}


Guest::~Guest()
{
}

void Guest::TimSach(DanhSach DS)
{
	system("cls");
	int choice;
	cout << "Xin chao quy khach!\n";
	cout << "1. Mua sach." << endl;
	cout << "2. Thoat chuong trinh" << endl;
	cout << "Lua chon cua ban: ";
	cin >> choice;

	if (choice == 2)
		return;
	int i = 0;
	DanhsachHoadon BillList;
	//BillList.ThemDanhSach(DS);
	User us;
	us.TimSach(BillList);
}