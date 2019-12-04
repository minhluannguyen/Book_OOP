#include "Header.h"
#include "User.h"
#include "NXB.h"
#include "TacGia.h"
#include "Admin.h"
#include "Guest.h"

void mainMenu(DanhSach &DS, vector<TaiKhoan*> &TK)
{
	int choice = 1;
	while (choice != 0)
	{
		system("cls");
		cout << "Xin chao quy khach!\n";
		cout << "1. Dang nhap." << endl;
		cout << "2. Dang ky." << endl;
		cout << "3. Xem sach." << endl;
		cout << "0. Thoat.\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;
		cin.ignore();

		if (choice == 0)
			return;
		if (choice == 1)
		{
			DangNhap(DS, TK);
		}
		if (choice == 3)
		{
			Guest gt;
			gt.xemSach(DS, TK);
		}
		if (choice == 2)
		{
			createNewAcc(TK);
		}
	}
}

vector<TaiKhoan*> readFileTK(char* filename, DanhSach &DS)
{
	ifstream fi(filename);
	vector<TaiKhoan*> tmpVec;
	
	string username;
	string password;
	string tmpname, tmpuser, tmppass, tmptype;
	bool ok = true;

	if (fi.is_open())
	{
		int n;
		fi >> n;
		fi.ignore();

		for (int i = 0; i < n; i++)
		{
			getline(fi, tmptype);
			getline(fi, tmpuser);
			getline(fi, tmppass);

			if (tmptype == "User")
			{
				TaiKhoan* us = new User(tmpuser, tmppass);
				tmpVec.push_back(us);
			}
			else
				if (tmptype == "TacGia")
				{
					getline(fi, tmpname);
					TaiKhoan* tg = new TacGia(tmpname, tmpuser, tmppass, DS);
					tmpVec.push_back(tg);
				}
				else
					if (tmptype == "NXB")
					{
						getline(fi, tmpname);
						TaiKhoan* XB = new NXB(tmpname, tmpuser, tmppass, DS);
						tmpVec.push_back(XB);
					}
					else
						if (tmptype == "Admin")
						{
							TaiKhoan* ad = new Admin(tmpuser, tmppass);
							tmpVec.push_back(ad);
						}

		}
	}
	fi.close();
	return tmpVec;
}

void DangNhap(DanhSach &listBook, vector<TaiKhoan*> &tk)
{
	//ifstream fi("account.txt");
	string username;
	string password;
	string tmpname, tmpuser, tmppass, tmptype;
	//DanhSach tmpDS;
	bool ok = true;

	system("cls");
	cout << "Moi ban dang nhap: \n";
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);

	int n = tk.size();

	for (int i = 0; i < n; i++)
	{
		tmptype = tk[i]->getNameClass();

		if (tk[i]->verify(username, password))
		{
			ok = false;
			cout << "Dang nhap thanh cong!!!!\n";
			_getch();
			if (tmptype == "User")
			{
				User us(username, password);
				us.menu(listBook);
			}
			else
				if (tmptype == "TacGia")
				{
					tmpname = tk[i]->getTen();
					TacGia tg(tmpname, username, password, listBook);
					tg.menu(listBook);
				}
				else
					if (tmptype == "NXB")
					{
						tmpname = tk[i]->getTen();
						NXB XB(tmpname, username, password, listBook);
						XB.menu(listBook);
					}
					else if (tmptype == "Admin")
					{
						Admin ad(username, password);
						ad.menu(listBook);
					}
		}

	}
	if (ok)
	{
		cout << "Dang nhap khong thanh cong!";
		_getch();
	}
}

//void DangNhap(DanhSach listBook)
//{
//	ifstream fi("account.txt");
//	string username;
//	string password;
//	string tmpname, tmpuser, tmppass, tmptype;
//	DanhSach tmpDS;
//	bool ok = true;
//
//	system("cls");
//	cout << "Moi ban dang nhap: \n";
//	cout << "Username: ";
//	getline(cin, username);
//	cout << "Password: ";
//	getline(cin, password);
//
//	if (fi.is_open())
//	{
//		int n;
//		fi >> n;
//		fi.ignore();
//
//		for (int i = 0; i < n; i++)
//		{
//			getline(fi, tmptype);
//			getline(fi, tmpuser);
//			getline(fi, tmppass);
//
//			if (tmpuser == username && tmppass == password)
//			{
//				ok = false;
//				cout << "Dang nhap thanh cong!!!!\n";
//				_getch();
//				if (tmptype == "User")
//				{
//					User us;
//					us.menu(listBook);
//				}
//				else
//					if (tmptype == "TacGia")
//					{
//						getline(fi, tmpname);
//						TacGia tg(tmpname, username, password, listBook);
//						tg.menu(listBook);
//					}
//					else
//						if (tmptype == "NXB")
//						{
//							getline(fi, tmpname);
//							NXB XB(tmpname, username, password, listBook);
//							XB.menu(listBook);
//						}
//						else
//						{
//							Admin ad(username, password);
//							ad.menu(listBook);
//						}
//			}
//
//		}
//		if (ok)
//		{
//			cout << "Dang nhap khong thanh cong!";
//			_getch();
//		}
//	}
//	fi.close();
//}

void createNewAcc(vector<TaiKhoan*> &TK)
{
	int choice = 1;
	string s;
	while (choice != 0)
	{
		system("cls");
		cout << "Dang ki tai khoan moi! Chon loai tai khoan ban muon dang ki:\n";
		cout << "1. Thuong." << endl;
		cout << "2. Nha xuat ban." << endl;
		cout << "3. Tac gia." << endl;
		cout << "0. Thoat.\n";
		cout << "Lua chon cua ban: ";
		cin >> choice;
		cin.ignore();

		if (choice == 0)
			return;
		if (choice == 1)
		{
			TaiKhoan* us = new User;
			us->newAcc();
			TK.push_back(us);
		}
		if (choice == 2)
		{
			TaiKhoan* nxb = new NXB;
			nxb->newAcc();
			cout << "Ten nha xuat ban: ";
			cin >> s;
			nxb->setTen(s);
			TK.push_back(nxb);
		}
		if (choice == 3)
		{
			TaiKhoan* tg = new TacGia;
			tg->newAcc();
			cout << "Ten tac gia: ";
			cin >> s;
			tg->setTen(s);
			TK.push_back(tg);
		}
	}
}

void writeFileTaiKhoan(string filename, vector<TaiKhoan*> TK)
{
	ofstream os(filename);
	
	os << TK.size() << endl;
	for (int i = 0; i < TK.size(); i++)
	{
		string tmptype = TK[i]->getNameClass();
		if (tmptype == "User")
		{
			os << tmptype << endl;
			TK[i]->writeFile(os);
		}
		else
			if (tmptype == "TacGia")
			{
				os << tmptype << endl;
				TK[i]->writeFile(os);
				os << TK[i]->getTen() << endl;
			}
			else
				if (tmptype == "NXB")
				{
					os << tmptype << endl;
					TK[i]->writeFile(os);
					os << TK[i]->getTen() << endl;
				}
				else
					if (tmptype == "Admin")
					{
						os << tmptype << endl;
						TK[i]->writeFile(os);
					}

	}
}