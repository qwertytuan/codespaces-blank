#include <iostream>
#include <fstream>
#include <string.h>
#include "giucho-muave.hpp"
#include "nguoidung.hpp"
using namespace std;

int main()
{

	remove("temp1.txt");
	int c;
	cout << "================Chao mung den voi trang dat ve================\n";
	cout << "\t\tCac chuyen bay hien co:\n";	 
	HienThiThongTinChuyenBay();
	cout << "\t\tVui long dang ky hoac dang nhap de tiep tuc su dung dich vu.\n";
	cout << "\t\tChon 1 de dang nhap.\n";
	cout << "\t\tChon 2 de dang ky.\n";
	cout << "\t\tChon 3 tim kiem cac chuyen bay.\n";
	cout << "==============================================================\n";
	cout << "\t\tNhap lua chon cua ban: ";
	cin >> c;

	switch (c)
	{
	case 1:
	    cout <<"\n";
		DangNhap();
		main();
		break;
	case 2:
	    cout <<"\n";
		DangKy();
		break;
	case 3:
	    cout <<"\n";
		TimKiemChuyenBay();
		break;
	default:
		cout << "\t\tVui long chon cac tuy chon da cung cap tren\n"
			 << endl;
		main();
	}
}
