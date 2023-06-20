#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<fstream>
using namespace std;

// Khai bao cau truc chuyen bay
class ChuyenBay {
    public:
    int sothutu;
    char MaChuyenBay[10];
    char KhoiDau[10000];
    char Dich[10000];
    char ThoiGianDi[200];
    char ThoiGianDen[200];
};

// Khai bao mang chua thong tin chuyen bay
class ChuyenBay CacChuyenBay[100];
int SoChuyenBay = 0;

// Ham Nhap thong tin chuyen bay
void NhapChuyenBay() {    
   class ChuyenBay ChuyenBay;
    cout<<"Ma chuyen bay: ";
    cin>> ChuyenBay.MaChuyenBay;

    cout<<"Noi Khoi Hanh: ";
    cin>> ChuyenBay.KhoiDau;

    cout<<"Noi Den: ";
    cin>> ChuyenBay.Dich;

    cout<<"Ngay Bay: ";
    cin>> ChuyenBay.ThoiGianDi;
    cout<<"Ngay Den:";
    cin>> ChuyenBay.ThoiGianDen;


    CacChuyenBay[SoChuyenBay++] = ChuyenBay;
    cout<<"Da them chuyen bay!\n";
        ifstream f2("LuuTruMayBay.txt");
size_t line_count=0;
char c;
while(f2.get(c)){
if(c=='\n')
++line_count;
}

    ofstream f1("LuuTruMayBay.txt", ios::app);
	f1<<line_count<<' '<<ChuyenBay.MaChuyenBay<<' '<<ChuyenBay.KhoiDau<<' '<<ChuyenBay.Dich<<' '<<ChuyenBay.ThoiGianDi<<' '<<ChuyenBay.ThoiGianDen<<endl;;
}

// Ham Hien thi thong tin cac chuyen bay
void HienThiChuyenBay() {
    cout<<"Danh sach cac chuyen bay:\n";
    for (int i = 0; i < SoChuyenBay; i++) {
        class ChuyenBay ChuyenBay = CacChuyenBay[i];
        cout<<"Ma chuyen bay:"<<ChuyenBay.MaChuyenBay<<endl;
        cout<<"Noi Khoi Hanh: "<<ChuyenBay.KhoiDau<<endl;
        cout<<"Noi Den: "<<ChuyenBay.Dich<<endl;
        cout<<"Ngay Bay:"<<ChuyenBay.ThoiGianDi<<endl;
        cout<<"Ngay Den:"<<ChuyenBay.ThoiGianDen<<endl;
        cout<<"-----------------------\n";
    }
}

// Ham tim kiem thong tin chuyen bay
void TimKiemChuyenBay(char MaChuyenBay[]) {
    for (int i = 0; i < SoChuyenBay; i++) {
        class ChuyenBay ChuyenBay = CacChuyenBay[i];
        if (strcmp(ChuyenBay.MaChuyenBay, MaChuyenBay) == 0) {
            cout<<"Ma chuyen bay:"<<ChuyenBay.MaChuyenBay<<endl;
            cout<<"Noi Khoi Hanh:"<<ChuyenBay.KhoiDau<<endl;
            cout<<"Noi Den:"<<ChuyenBay.Dich<<endl;
            cout<<"Ngay Bay:"<<ChuyenBay.ThoiGianDi<<endl;
            cout<<"Ngay Den:"<<ChuyenBay.ThoiGianDen<<endl;
            return;
        }
    }
    cout<<"Khong tim thay chuyen bay co ma:"<<MaChuyenBay;
}

// Ham sua thong tin chuyen bay
void ChinhSuaChuyenBay(char MaChuyenBay[]) {
    for (int i = 0; i < SoChuyenBay; i++) {
        class ChuyenBay ChuyenBay = CacChuyenBay[i];
        if (strcmp(ChuyenBay.MaChuyenBay, MaChuyenBay) == 0) {
            cout<<"Nhap thong tin moi cho chuyen bay:\n";
            cout<<"Ma chuyen bay: ";
            cin>> ChuyenBay.MaChuyenBay;

            cout<<"Noi Khoi Hanh: ";
            cin>> ChuyenBay.KhoiDau;

            cout<<"Noi Den: ";
            cin>> ChuyenBay.Dich;

            cout<<"Ngay Bay: ";
            cin>> ChuyenBay.ThoiGianDi;
            cout<<"Ngay Den: ";
            cin>> ChuyenBay.ThoiGianDen;

            CacChuyenBay[i] = ChuyenBay;
            cout<<"Da cap nhat thong tin chuyen bay!\n";
            return;
        }
    }
    cout<<"Khong tim thay chuyen bay co ma"<<MaChuyenBay;
}
int main2(){
    char MaChuyenBay[10];
    int choice;
    do {
        cout<<("====== He Thong Dat Ve May Bay ======\n");
        cout<<("1. Nhap thong tin chuyen bay\n");
        cout<<("2. Hien thi thong tin cac chuyen bay\n");
        cout<<("3. Tim kiem thong tin cac chuyen bay\n");
        cout<<("4. Sua thong tin cac chuyen bay\n");
        cout<<("0. Thoat. \n");
        cout<<("======================================\n");
        cout<<("Nhap lua chon cua ban: ");
        cin>>choice;

        switch (choice) {
            case 1:
                NhapChuyenBay();
                break;
            case 2:
                HienThiChuyenBay();
                break;
            case 3:
                cout<<"Nhap Ma chuyen bay can tim: ";
                cin>>MaChuyenBay;
                TimKiemChuyenBay(MaChuyenBay);
                break;
            case 4:
                cout<<"Nhap Ma chuyen bay can sua: ";
                cin>> MaChuyenBay;
                ChinhSuaChuyenBay(MaChuyenBay);
                break;
            case 0:
                cout<<"Tam biet!\n";
                break;
            default:
                cout<<"lua chon khong hop le. Vui long thu lai!\n";
                break;
        }
    } while (choice != 0);

    return 0;
}



