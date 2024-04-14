#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//
class chuyenbay
{
public:
    string MaMayBay;
    string NoiDi;
    string NoiDen;
    string ThoiGianDi;
    string ThoiGianDen;
};

// ham hien thi menu
void HienThiMenu()
{
    cout << ("=============== He Thong Quan Ly Dat Ve May Bay ===============\n");
    cout << ("\t\t1. Nhap thong tin chuyen bay\n");
    cout << ("\t\t2. Hien thi thong tin cac chuyen bay\n");
    cout << ("\t\t3. Tim kiem thong tin cac chuyen bay\n");
    cout << ("\t\t4. Sua thong tin cac chuyen bay\n");
    cout << ("\t\t5. Thoat. \n");
    cout << ("===============================================================\n");
    cout << ("\t\tNhap lua chon cua ban: ");
}

// ham nhap du lieu vao LuuTruMayBay.txt
void ThemChuyenBay()
{
    // tao 1 class la f,viet cho ngan gon
    class chuyenbay f;

    // nguoi dung dien cac thong tin chuyen bay vao
    cout << "\t\tThem Ma Chuyen Bay: ";
    cin >> f.MaMayBay;
    cout << "\t\tThem Noi Di: ";
    cin >> f.NoiDi;
    cout << "\t\tThem Noi Den: ";
    cin >> f.NoiDen;
    cout << "\t\tThem thoi gian di: ";
    cin >> f.ThoiGianDi;
    cout << "\t\tThem thoi gian den: ";
    cin >> f.ThoiGianDen;

    // Mo file
    ofstream file("LuuTruMayBay.txt", ios::app);

    // kiem tra file co mo duoc ko
    if (file.is_open())
    {
        // viet cac chi tiet ve chuyen bay vao LuuTruMayBay.txt
        file << f.MaMayBay << " "
             << f.NoiDi << " "
             << f.NoiDen << " "
             << f.ThoiGianDi << " "
             << f.ThoiGianDen << "\n";

        // dong file txt
        file.close();

        // hien thi them thanh cong
        cout << "\t\tThem chi tiet chuyen bay thanh cong.\n";
    }
    else
    {
        // hien thi loi
        cout << "\t\tLoi. Khong The Mo File.\n";
    }
}

// ham hien thi thong tin chuyen bay, doc tu LuuTruMayBay.txt
void HienThiThongTinChuyenBay()
{
    // tao 1 strct la f viet cho ngan gon
    class chuyenbay f;

    // mo file LuuTruMayBay.txt de doc
    ifstream file("LuuTruMayBay.txt", ios::in);

    // kiem tra xem file da mo thanh cong chua
    if (file.is_open())
    {
        // hien thi thong tin
        cout <<"\t\tDanh sach cac chuyen bay\n";
        cout << "Ma May Bay\tNoi Di\t\tNoi Den\t\tThoi Gian Di\t\tThoi Gian Den\n";

        // doc den khi den dong cuoi cua file
        while (file >> f.MaMayBay >> f.NoiDi >> f.NoiDen >> f.ThoiGianDi >> f.ThoiGianDen)
        {
            // hien thi thong tin chuyen bay
            cout << "\n";
            cout << f.MaMayBay << "\t\t"
                 << f.NoiDi << "\t\t"
                 << f.NoiDen << "\t\t"
                 << f.ThoiGianDi << "\t\t"
                 << f.ThoiGianDen << "\n";
            cout << "\n";
        }

        // dong file
        file.close();
    }
    else
    {
        // hien thi loi
        cout << "\t\tLoi. Khong The Mo File.\n";
    }
}

// ham tim kiem thong tin chuyen bay tu file LuuTruMayBay.txt
void TimMaChuyenBay()
{
    // tao 1 strct la f viet cho ngan gon
    class chuyenbay f;

    // khai bao 1 bien lua ma may bay
    string TimMaChuyenBay;

    // nguoi dung nhap vao ma may bay
    cout << "\t\tThem Ma Chuyen Bay Muon Tim: ";
    cin >> TimMaChuyenBay;

    // khai bao 1 cai co de xem co tim thay hay khong
    bool found = false;

    // mo file LuuTruMayBay.txt de ghi
    ifstream file("LuuTruMayBay.txt", ios::in);

    // kiem tra xem file da mo thanh cong chua
    if (file.is_open())
    {
        // doc den khi den dong cuoi cua file or the class chuyenbay is found
        while (file >> f.MaMayBay >> f.NoiDi >> f.NoiDen >> f.ThoiGianDi >> f.ThoiGianDen && !found)
        {
            // kiem tra ma may bay co trung hay khong
            if (f.MaMayBay == TimMaChuyenBay)
            {
                // neu trung thi la true
                found = true;

                // hien thi la da tim thay
                cout << "\t\tDa tim thay.\n";
                cout << "\t\tMa may bay: " << f.MaMayBay << "\n";
                cout << "\t\tNoiDi: " << f.NoiDi << "\n";
                cout << "\t\tNoiDen: " << f.NoiDen << "\n";
                cout << "\t\tThoi gian di: " << f.ThoiGianDi << "\n";
                cout << "\t\tThoi gian den: " << f.ThoiGianDen << "\n";
            }
        }

        // dong file
        file.close();

        // kiem tra xem co tim duoc khong
        if (!found)
        {
            // hien thi ko tim thay
            cout << "\t\tKhong tim thay chuyen bay.\n";
        }
    }
    else
    {
        // hien thi loi
        cout << "\t\tLoi. Khong The Mo File.\n";
    }
}

// ham de chinh sua chi tiet chuyen bay
void ChinhSuaChiTiet()
{
    // tao 1 strct la f viet cho ngan gon
    class chuyenbay f;

    // khai bao ham de chua ma may bay can chinh sua
    string ChinhSuaMaMayBay;

    // Prompt the user to Them Ma Chuyen Bay to be edited
    cout << "\t\tThem Ma Chuyen Bay cần sửa: ";
    cin >> ChinhSuaMaMayBay;

    // khai bao de xem ma may bay co ton tai hay khong
    bool found = false;

    // mo file LuuTruMayBay.txt de ghi
    ifstream file_in("LuuTruMayBay.txt", ios::in);

    // kiem tra xem file da mo thanh cong chua
    if (file_in.is_open())
    {
        // mo 1 file temp tam thoi
        ofstream file_out("temp.txt", ios::out);

        // kiem tra xem file da mo thanh cong chua
        if (file_out.is_open())
        {
            // doc chi tiet chuyen bay den dong cuoi
            while (file_in >> f.MaMayBay >> f.NoiDi >> f.NoiDen >> f.ThoiGianDi >> f.ThoiGianDen)
            {
                // kiem tra xem ma may bay co trung voi ma may bay can duoc sua
                if (f.MaMayBay == ChinhSuaMaMayBay)
                {
                    // neu dung thi cho la true
                    found = true;

                    // ghi cac chi tiet moi vao
                    cout << "\t\tThem Noi Di Moi: ";
                    cin >> f.NoiDi;
                    cout << "\t\tThem Noi Den Moi: ";
                    cin >> f.NoiDen;
                    cout << "\t\tThem thoi gian Di Moi: ";
                    cin >> f.ThoiGianDi;
                    cout << "\t\tThem thoi gian Den Moi: ";
                    cin >> f.ThoiGianDen;
                }

                // ghi lai vao file
                file_out << f.MaMayBay << " "
                         << f.NoiDi << " "
                         << f.NoiDen << " "
                         << f.ThoiGianDi << " "
                         << f.ThoiGianDen << "\n";
            }

            // dong ca 2 file temp va LuuTruMayBay.txt
            file_in.close();
            file_out.close();

            // kiem tra xem co true khong
            if (found)
            {
                // thay ten cua file temp = LuuTruMayBay.txt va xoa file cu di
                remove("LuuTruMayBay.txt");
                rename("temp.txt", "LuuTruMayBay.txt");

                // hien thi da thanh cong
                cout << "\t\tChi tiet chuyen bay da sua thanh cong.\n";
            }
            else
            {
                // hien thi loi va xoa file temp
                cout << "\t\tKhong tim thay chuyen bay.\n";
                remove("temp.txt");
            }
        }
        else
        {
            // hien thi loi and close the input file
            cout << "\t\tLoi.Khong the mo file output.\n";
            file_in.close();
        }
    }
    else
    {
        // hien thi loi
        cout << "\t\tLoi.Khong the mo file input.\n";
    }
}

// ham chinh cua chuong trinh
void ham_admin()
{
    // khai bao bien lua chon cua nguoi dung
    int choice;

    // hien thi menu va nhap lua chon
    do
    {
        HienThiMenu();
        cin >> choice;

        // doi case dua theo lua chon ma nguoi dung nhap
        switch (choice)
        {
        // neu nhap 1 thi chay ham them chuyen bay
        case 1:
            ThemChuyenBay();
            break;
        // neu nhap 2 thi chay ham hien thi thong tin chuyen bay
        case 2:
            HienThiThongTinChuyenBay();
            break;
            // neu nhap 3 thi chay ham tim chuyen bay theo ma chuyen bay
        case 3:
            TimMaChuyenBay();
            break;
        case 4:
            // neu nhap 4 thi chay ham chinh sua thong tin chuyen bay
            ChinhSuaChiTiet();
            break;
        // neu nhap 5 thi thoat
        case 5:
            cout << "\t\tCam on da dung dich vu cua chung toi.\n";
            break;
        default:
            cout << "\t\tLua chon khong phu hop.Vui long thu lai\n";
        }
    } while (choice != 5);
}