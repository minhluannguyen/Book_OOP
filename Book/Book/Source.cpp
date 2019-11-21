#include "Header.h"

void main()
{
	DanhSach DS;
	//vector<TaiKhoan*> vtTK;
	//DS.inputBook();
	//char a[] = "account.txt";
	//vtTK = readFileTK(a);
	DS.readBookFile("BookList.txt");
	mainMenu(DS);
}