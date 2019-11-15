#ifndef SACH_H_
#define SACH_H_
class Sach
{
private:
	string tenSach;
	string ISBN;
	string NXB;
	string tacGia;
	int giaTien;
public:
	Sach();
	~Sach();
	Sach(const Sach&);
	Sach(char*, char*, char*, char*, int);
	Sach& operator = (const Sach&);
	void printBook();
	void inputSach();

	string getTenSach();
	string getISBN();
	string getTacGia();
	string getNXB();
	int getGiaTien();

	void setGiaTien(int);
	void setTenSach(char*);
	void setISBN(char*);
	void setTacGia(char* s);
	void setNXB(char* s);
};

#endif