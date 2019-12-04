#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
using namespace std;

//#include "Sach.h"
#include "DanhSach.h"
//#include "HoaDon.h"
//#include "Guest.h"
#include "TaiKhoan.h"
//#include "User.h"
//#include "NXB.h"
//#include "TacGia.h"
//#include "Admin.h"

vector<TaiKhoan*> readFileTK(char* filename, DanhSach &DS);
void createNewAcc(vector<TaiKhoan*> &TK);
//void mainMenu(DanhSach &DS);
void mainMenu(DanhSach &DS, vector<TaiKhoan*> &TK);
void DangNhap(DanhSach &listBook, vector<TaiKhoan*> &tk);
void writeFileTaiKhoan(string filename, vector<TaiKhoan*> TK);
//void DangNhap(DanhSach listBook);
