#include "Header.h"

Sach::Sach()
{
	giaTien = -1;
}

Sach::Sach(const Sach& book)
{
	tenSach = book.tenSach;
	ISBN = book.ISBN;
	NXB = book.NXB;
	tacGia = book.tacGia;
	giaTien = book.giaTien;
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
	cout << "NXB: " << NXB << endl;
	cout << "Tac gia: " << tacGia << endl;
	cout << "Gia tien: " << giaTien << endl;
}

void Sach::inputSach()
{
	cout << "Ten sach: ";
	cin >> tenSach;
	cout << "ISBN: ";
	cin >> ISBN;
	cout << "NXB: ";
	cin >> NXB;
	cout << "Tac gia: ";
	cin >> tacGia;
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

void Sach::setGiaTien(int n)
{
	giaTien = n;
}

void Sach::setTenSach(char* s)
{
	tenSach = s;
}

void Sach::setISBN(char* s)
{
	ISBN = s;
}

void Sach::setTacGia(char* s)
{
	tacGia = s;
}

void Sach::setNXB(char* s)
{
	NXB = s;
}
