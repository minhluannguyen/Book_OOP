#include "Header.h"

void main()
{
	DanhSach DS;
	DanhsachHoadon DSHD;
	DS.inputBook();
	DSHD.inputDSHD(DS);
	cout << DSHD.TinhTien();
	system("pause");
	/*
	NXB Tre("tre", "tre");
	string name, pass;
	cout << "Login\n";
	do
	{
		cout << "User Name: ";
		cin >> name;
		cout << "Password: ";
		cin >> pass;
	} while (!Tre.verify(name, pass));
	Tre.ThemSach();
	Tre.XoaSach();
	*/
}