#include "Header.h"
#include "Admin.h"

void main()
{
	DanhSach DS;
	vector<TaiKhoan*> vtTK;


	//DS.inputBook();
	char a[] = "account.txt";
	DS.readBookFile("BookList.txt");
	//TaiKhoan *ad = new Admin("admin", "admin");
	//vtTK.push_back(ad);
	//writeFileTaiKhoan("account.bin", vtTK);
	vtTK = readFileTK(a, DS);
	mainMenu(DS, vtTK);
	DS.saveBookFile("BookList.txt");
	writeFileTaiKhoan("account.txt", vtTK);
	//delete[]ad;
}

/*DS.readBookFile("BookList.txt");
	ofstream fo("account.bin", ios::binary);
	//TaiKhoan *ad = new Admin("admin", "admin");
	Admin ad("admin", "admin");
	vtTK.push_back(&ad);
	fo.write((char*)(&vtTK), sizeof(vtTK));
	fo.close();

	ifstream fi("account.bin", ios::binary);
	vector<TaiKhoan*> res;
	fi.seekg(0, fi.end);
	int length = fi.tellg();
	fi.seekg(0, fi.beg);
	fi.read((char*)&res, length);
	cout << res[0]->getUsername() << endl;
	vtTK.clear();
	_getch();
	fi.close();
	delete[]ad;*/