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

//vector<TaiKhoan*> readFileTK(char* filename);
void mainMenu(DanhSach &DS);
void DangNhap(DanhSach listBook);
