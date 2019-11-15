#ifndef DANHSACH_H_
#define DANHSACH_H_

#include "Header.h"

class DanhSach
{
private:
	vector<Sach> listBook;
public:
	DanhSach();
	~DanhSach();
	DanhSach(const DanhSach&);
	void inputBook();
	void printList();
	int searchBook_name(char*);
	int searchBook_ISBN(char*);
	void deleteBook(int);
	void updatePrice(int, int);
	DanhSach& operator = (DanhSach&);
	void updateBook(Sach, int);
	Sach getBook(int);
};

#endif