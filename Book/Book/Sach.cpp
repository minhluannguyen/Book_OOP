#include "Sach.h"

Sach::Sach()
{
	giaTien = -1;
	hidNXB = false;
	hidtacGia = false;
	hide = false;
}

Sach::Sach(const Sach& book)
{
	tenSach = book.tenSach;
	ISBN = book.ISBN;
	NXB = book.NXB;
	tacGia = book.tacGia;
	giaTien = book.giaTien;

	hidNXB = book.hidNXB;
	hidtacGia = book.hidtacGia;
	hide = book.hide;
}

Sach::Sach(char* name, char* code, char* publish, char* author, int price)
{
	tenSach = name;
	ISBN = code;
	NXB = publish;
	tacGia = author;
	giaTien = price;
}

Sach& Sach::operator=(const Sach& book)
{
	this->tenSach = book.tenSach;
	this->ISBN = book.ISBN;
	this->NXB = book.NXB;
	this->tacGia = book.tacGia;
	this->giaTien = book.giaTien;

	this->hidNXB = book.hidNXB;
	this->hidtacGia = book.hidtacGia;
	this->hide = book.hide;
	return *this;
}

Sach::~Sach()
{
}

string Sach::getTenSach()
{
	return tenSach;
}

string Sach::getISBN()
{
	return ISBN;
}

void Sach::printBook()
{
	cout << "Ten sach: " << tenSach << endl;
	cout << "ISBN: " << ISBN << endl;
	if (hidNXB == false)
		cout << "NXB: " << NXB << endl;
	if (hidtacGia == false)
		cout << "Tac gia: " << tacGia << endl;
	cout << "Gia tien: " << giaTien << endl;
}

void Sach::inputSach()
{
	cin.ignore();
	cout << "Ten sach: ";
	getline(cin, tenSach);
	cout << "ISBN: ";
	getline(cin, ISBN);
	cout << "NXB: ";
	getline(cin, NXB);
	cout << "Tac gia: ";
	getline(cin, tacGia);
	cout << "Gia tien: ";
	cin >> giaTien;
	cin.ignore();
}

string Sach::getTacGia()
{
	return tacGia;
}

string Sach::getNXB()
{
	return NXB;
}

int Sach::getGiaTien()
{
	return giaTien;
}
bool Sach::is_hideNXB()
{
	return hidNXB;
}

bool Sach::is_hideTG()
{
	return hidtacGia;
}
bool Sach::is_hideSach()
{
	return hide;
}

void Sach::setGiaTien(int n)
{
	giaTien = n;
}

void Sach::setTenSach(string s)
{
	tenSach = s;
}

void Sach::setISBN(string s)
{
	ISBN = s;
}

void Sach::setTacGia(string s)
{
	tacGia = s;
}

void Sach::setNXB(string s)
{
	NXB = s;
}

void Sach::hideNXB()
{
	hidNXB = true;
}

void Sach::unhideNXB()
{
	hidNXB = false;
}

void Sach::hideTG()
{
	hidtacGia = true;
}

void Sach::unhideTG()
{
	hidtacGia = false;
}

void Sach::hideBook()
{
	hide = true;
}

void Sach::unhideBook()
{
	hide = false;
}

ostream &operator << (ostream &os, Sach &S)
{
	os << S.tenSach << endl;
	os << S.ISBN << endl;
	if (S.hidNXB == false)
		os << 0 << endl;
	else
		os << 1 << endl;
	os << S.NXB << endl;
	if (S.hidtacGia == false)
		os << 0 << endl;
	else
		os << 1 << endl;
	os << S.tacGia << endl;
	os << S.giaTien << endl;
	return os;
}