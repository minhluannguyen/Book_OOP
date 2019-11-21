#pragma once

#include <vector>
#include <fstream>
#include <string>
using namespace std;
#include "Sach.h"

class DanhSach
{
private:
	vector<Sach> listBook;
public:
	DanhSach();
	~DanhSach();
	DanhSach(const DanhSach&);
	void addBook(Sach);
	void inputBook();
	void readBookFile(string);
	void printList();
	int searchBook_name(char*);
	int searchBook_ISBN(char*);
	void deleteBook(int);
	void updatePrice(int, int);
	DanhSach& operator = (DanhSach&);
	void updateBook(Sach, int);
	Sach &getBook(int);
	int getSize();
};