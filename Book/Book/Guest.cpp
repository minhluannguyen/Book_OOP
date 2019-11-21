#include "Header.h"
#include "Guest.h"



Guest::Guest()
{
}

Guest::~Guest()
{
}

void Guest::xemSach(DanhSach DS)
{
	system("cls");

	DS.printList();
	int choice = 1;
	cout << "\nBan muon?\n";
	cout << "1. Dang nhap neu muon mua." << endl;
	cout << "0. Thoat.\n";
	cout << "Lua chon cua ban: ";
	cin >> choice;
	cin.ignore();

	if (choice == 1)
	{
		DangNhap(DS);
		return;
	}
	return;
}