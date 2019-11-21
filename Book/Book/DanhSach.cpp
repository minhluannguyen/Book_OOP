#include "DanhSach.h"

DanhSach::DanhSach()
{
}

DanhSach::~DanhSach()
{
}

DanhSach::DanhSach(const DanhSach& DS)
{
	listBook = DS.listBook;
}

void DanhSach::addBook(Sach S)
{
	listBook.push_back(S);
}

void DanhSach::inputBook()
{
	cout << "So luong sach muon nhap: ";
	int n;
	cin >> n;
	cin.ignore();
	int num;
	for (int i = 0; i < n; i++) {
		Sach tmp;
		cout << "Nhap thong tin sach thu " << i + 1 << ":\n";
		tmp.inputSach();
		listBook.push_back(tmp);
	}
}

void DanhSach::readBookFile(string filename)
{
	ifstream fi(filename);
	int n, cost;
	if (fi.is_open())
	{
		fi >> n;
		fi.ignore();
		for (int i = 0; i < n; i++)
		{
			Sach tmpS;
			string tmp;
			getline(fi, tmp);
			tmpS.setTenSach(tmp);
			getline(fi, tmp);
			tmpS.setISBN(tmp);
			getline(fi, tmp);
			tmpS.setNXB(tmp);
			getline(fi, tmp);
			tmpS.setTacGia(tmp);
			fi >> cost;
			fi.ignore();
			tmpS.setGiaTien(cost);
			listBook.push_back(tmpS);
		}
	}
	fi.close();
}

void DanhSach::printList()
{
	int n = listBook.size();
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". \n";
		listBook[i].printBook();
	}
}

int DanhSach::searchBook_name(char* name)
{
	int countBook = 0;
	int id = -1;
	int n = listBook.size();
	char tmp[10];
	for (int i = 0; i < n; i++)
	{
		if (listBook[i].getTenSach() == name)
		{
			countBook++;
			id = i;
		}
	}

	if (countBook == 1)
	{
		return id;
	}
	else
		if (countBook > 1) {
			cout << "Co nhieu sach cung ten!! Moi nhap ISBN: ";
			gets_s(tmp);
			return searchBook_ISBN(tmp);
		}
		else
		{
			cout << "Khong co sach!!";
			return -1;
		}
}

int DanhSach::searchBook_ISBN(char* code)
{
	int n = listBook.size();
	for (int i = 0; i < n; i++)
	{
		if (listBook[i].getISBN() == code)
		{
			return i;
		}
	}

	return -1;
}

void DanhSach::deleteBook(int id)
{
	vector<Sach> ::iterator it;
	it = listBook.begin();
	for (int i = 0 ; i < id; i++)
	{
		it++;
	}
	listBook.erase(it);
}

void DanhSach::updatePrice(int id, int price)
{
	listBook[id].setGiaTien(price);
}

DanhSach& DanhSach::operator = (DanhSach& ds)
{
	DanhSach tmp;
	tmp = ds;
	return tmp;
}

void DanhSach::updateBook(Sach s, int id)
{
	listBook[id] = s;
}

Sach &DanhSach::getBook(int id)
{
	return listBook[id];
}

int DanhSach::getSize()
{
	return listBook.size();
}