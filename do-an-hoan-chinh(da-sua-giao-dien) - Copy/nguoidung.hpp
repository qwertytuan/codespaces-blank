#include<iostream>
#include<fstream>
#include<string.h>
#include"ham-admin.hpp"
#include"filephutro.hpp"
using namespace std;
class ve2
{
public:
    string loaive2;
    int so_luong_ve2;
    int gia_ve2;
    int tong_tien2;
};
class phiennguoidung
{
 public:
 string name;
 string pswd;
 string cccd;
 string phone;
 string email;
};
class chuyenbay3
{
public:
    string MaMayBay3;
    string NoiDi3;
    string NoiDen3;
    string ThoiGianDi3;
    string ThoiGianDen3;
};
void DangNhap();
void DangKy();
void ChinhSuaProfile();
void TimKiemChuyenBay();

void DangNhap()
    {
		ofstream file_out("temp1.txt", ios::app);
		class phiennguoidung u2;
		class ve2 ve2;
		class chuyenbay3 f3;
    	int count;
    	string userId, password, Id, pass,cccd,sdt,email2;
    	cout <<"================Trang Dang Nhap================\n";
    	cout <<"\t\tVui long nhap ten tai khoan va mat khau:\n";
    	cout <<"\t\tTen tai khoan: ";
    	cin >>userId;
    	cout <<"\t\tMat khau:" ;
	    echo(false);
        cin>>password;
        echo(true);
        
    	ifstream input("LuuTruNguoiDung.txt");
    	
    	while(input>>Id>>pass>>cccd>>sdt>>email2)
    	{
			// neu userId ta nhap trung voi Id da luu trong LuuTruNguoiDung.txt thi cho bien count=1
    		if(userId==Id && password==pass)
    		{
    			count=1;
    			
			}
	
		}
		input.close();
		// neu count=1 thi ta xac nhan da dang nhap thanh cong
		if(count==1)
{
         system("clear");
			cout<<"\t\t"<<userId<<"\n\t\tDang nhap cua ban thanh cong!\n\t\tCam on vi da dang nhap!\n"; 
			//////////////////////////////////////////////////
			 bool found1 = false;
    // mo file lua tru thong tin nguoi dung de doc
    ifstream fileuser("LuuTruNguoiDung.txt", ios::in);
     // kiem tra xem file da mo thanh cong chua
     if (fileuser.is_open()) 
     {
         // doc den khi den dong cuoi cua file 
         while (fileuser>>u2.name>>u2.pswd>>u2.cccd>>u2.phone>>u2.email && !found1)
          {
             // kiem tra ma may bay co trung hay khong
             if ( userId==u2.name)
			  {
                 // neu trung thi la true
                 found1 = true;
				 // viet vao 1 file tam temp1 de tao 1 phien dang nhap cho tung nguoi dung
				 if( file_out.is_open())
				 {
				 file_out<<u2.name<<" "<<u2.pswd<<" "<<u2.cccd<<" "<<u2.phone<<" "<<u2.email<<endl;
				 file_out.close();
				 }
              }
          }
	 }
///////////////////////////////////

 int LuaChon;
    do 
	{
        HienThi_Menu();
        cout <<"\t\tNhap lua chon cua ban: ";
        cin >> LuaChon;
        switch (LuaChon) 
		{
            // neu Lua chon cua nguoi dung la 1 thi chuyen den ham giu cho
            case 1:
			HienThiThongTinChuyenBay();
                Giu_cho_chuyen_bay();
                break;
            case 2:
            // neu Lua chon cua nguoi dung la 2 thi chuyen den ham dat cho
                Dat_Cho();
                break;
            // neu Lua chon cua nguoi dung la 3 thi chuyen den ham huy giu cho
            case 3: 
			HienThiThongTinChuyenBay;
                Huy_Dat_Cho();
                break;
			case 4:
			HienThiDatCho();
            break;
            // neu Lua chon cua nguoi dung la 4 thi thoat 
            case 5:
            ChinhSuaProfile();
            break;
            case 6:
            DangNhap();
            break;
            default:         
			 cout << "Loi.Vui long thu lai.\n";
        
	    }

    } while (LuaChon != 7);

}

		// neu count khac 1 thi quay lai menu
		else
		{
            int b;
			cout<<"\n\t\tLoi dang nhap!\n\t\tVui long kiem tra ten dang nhap va mat khau!\n";
            cout<<"Nhap 1 de tiep tuc";
            cin>>b;
            system("clear");
            DangNhap();
		}
	}
	// ham DangKy() doc dau vao cua nguoi dung va luu vào file LuuTruNguoiDung.txt de ham DangNhap() dung
void DangKy()
	{
		string ruserId, rpassword, rId, rpass, rcccd,rsodienthoai,remail;
		string checktentk,cpswd,Ccccd,csodienthoai,cemail;
		cout <<"================Trang Dang Ky================\n";
		cout<<"\t\tNhap ten nguoi dung : ";
		cin>>ruserId;
		cout<<"\t\tNhap mat khau : ";
		cin>>rpassword;
		cout<<"\t\tNhap can cuoc cong dan : ";
		cin>>rcccd;
		cout<<"\t\tNhap so dien thoai :";
		cin>>rsodienthoai;
		cout<<"\t\tNhap email :";
		cin>>remail;
		bool checkttk=false;
        // KIỂM TRA CÓ TRÙNG 
		ifstream checktk("LuuTruNguoiDung.txt");
		while(checktk>>checktentk>>cpswd>>Ccccd>>csodienthoai>>cemail && !checkttk)
    	{
			// neu userId ta nhap trung voi Id da luu trong LuuTruNguoiDung.txt thi cho bien count=1
    		if(ruserId==checktentk && rcccd==Ccccd )
    		{
    			checkttk=true;
				cout<<"\t\tTen tai khoan hoac can cuoc cong dan da bi trung. Vui long thu lai\n";
                DangKy();
			}
		
	
		}
		if(!checkttk)
		{
		//nhap du lieu cua nguoi dung vao file txt 
		ofstream f1("LuuTruNguoiDung.txt", ios::app);
		f1<<ruserId<<' '<<rpassword<<' '<<rcccd<<' '<<rsodienthoai<<' '<<remail<<endl;
		cout<<"\n\t\tDang ky cua ban thanh cong!\n";
        int i;
        cin>>i;
        system("clear");
        DangNhap();
		}
       

	}

void ChinhSuaProfile()
{ 
class phiennguoidung u3;
string tencanchinhsua;
string checkT,cHpswd,CHcccd,cHsodienthoai,cHemail;
// MỞ FILE CHỨA PHIÊN ĐĂNG NHẬP NGƯỜI DÙNG
 ifstream filechinhsuatk("temp1.txt");
 filechinhsuatk>>tencanchinhsua>>u3.pswd>>u3.cccd>>u3.phone>>u3.email;
 filechinhsuatk.close();
    // khai bao de xem ma may bay co ton tai hay khong
    bool found = false;

    // mo file LuuTruNguoiDung.txt de ghi
    ifstream file_in("LuuTruNguoiDung.txt", ios::in);

    // kiem tra xem file da mo thanh cong chua
    if (file_in.is_open()) 
    {
        // mo 1 file temp tam thoi
        ofstream file_out("temp.txt", ios::out);

        // kiem tra xem file da mo thanh cong chua
        if (file_out.is_open()) {
            // doc chi tiet 
            while (file_in >>u3.name>>u3.pswd>>u3.cccd>>u3.phone>>u3.email) 
            {
                // kiem tra xem ma may bay co trung voi ma may bay can duoc sua
                if ( tencanchinhsua == u3.name) {
                    // neu dung thi cho la true
                    found = true;
                    // ghi cac chi tiet moi vao
                    cout << "\t\tNhap mat khau moi: ";
                    cin >> u3.pswd;
                    cout << "\t\tNhap so dien thoai moi: ";
                    cin >>u3.phone;
                    cout << "\t\tNhap email moi: ";
                    cin>>u3.email;
        
                }

                // ghi lai vao file
                file_out << u3.name << " "
                         << u3.pswd << " "
                         << u3.cccd << " "
                         << u3.phone << " "
                         <<u3.email << "\n";
            }

            // dong ca 2 file temp va LuuTruNguoiDung.txt
            file_in.close();
            file_out.close();

            // kiem tra xem co true khong
            if (found) {
                // thay ten cua file temp = LuuTruNguoiDung.txt va xoa file cu di
                remove("LuuTruNguoiDung.txt");
                rename("temp.txt", "LuuTruNguoiDung.txt");

                // hien thi da thanh cong
                cout << "\t\tTai khoan da sua thanh cong.\n";
            }
            else {
                // hien thi loi va xoa file temp
                cout << "\t\tKhong tim thay tai khoan.\n";
                remove("temp.txt");
            }
        }
        else {
            // hien thi loi and close the input file
            cout << "\t\tLoi.Khong the mo file output.\n";
            file_in.close();
        }
    }

    else {
        // hien thi loi
        cout << "\t\tLoi.Khong the mo file input.\n";
    }

}
// pHẦN CỦA TRUNG NHÂN
void TimKiemChuyenBay()
{
    int chon;
    class chuyenbay3 f4;
    string noixuatphat,noiden;
    cout <<"================Trang Tim Kiem================\n";
    cout <<"\t\tChon 1: Tim kiem theo noi xuat phat.\n";
    cout <<"\t\tChon 2: Tim kiem theo noi den.\n";
    cout <<"==============================================\n";
    cout <<"\t\tNhap lua chon cua ban:";
    cin>>chon;
    switch (chon)
    {
    case 1:
    {
    cout<<"\t\tNhap noi xuat phat: ";
    cin>>noixuatphat;
    

    // mo file LuuTruMayBay.txt de ghi
    ifstream file("LuuTruMayBay.txt", ios::in);

     // kiem tra xem file da mo thanh cong chua
     if (file.is_open()) {
        cout <<"\n";
        cout << "Ma May Bay\tNoi Di\t\tNoi Den\t\tThoi Gian Di\t\tThoi Gian Den\n";
         // doc den khi den dong cuoi cua file 
         while (file >> f4.MaMayBay3 >> f4.NoiDi3 >> f4.NoiDen3 >> f4.ThoiGianDi3 >> f4.ThoiGianDen3 ) {
             // kiem tra ma may bay co trung hay khong
             if (f4.NoiDi3 == noixuatphat) 
             {
                 // hien thi la da tim thay
                  cout<<"\n";
            cout << f4.MaMayBay3 <<"\t\t"
                 << f4.NoiDi3 <<"\t\t"
                 << f4.NoiDen3 <<"\t\t"
                 << f4.ThoiGianDi3 <<"\t\t"
                 << f4.ThoiGianDen3 <<"\n";
                 cout<<"\n";
             }
             // neu trung thi la true
             
         }
         TimKiemChuyenBay();

         // dong file
         file.close();

         // kiem tra xem co tim duoc khong
         /*if (!founda) {
             // hien thi ko tim thay
             cout << "Khong tim thay chuyen bay.\n";
         }
         */
     }
     else {
         // hien thi loi
         cout << "\t\tLoi. Khong The Mo File.\n";
     }
     break;
    }

case 2:
{
    cout<<"\t\tNhap noi den: ";
    cin>>noiden;
    // mo file LuuTruMayBay.txt de ghi
    ifstream filef("LuuTruMayBay.txt", ios::in);

     // kiem tra xem file da mo thanh cong chua
     if (filef.is_open()) {
        cout <<"\n";
        cout << "Ma May Bay\tNoi Di\t\tNoi Den\t\tThoi Gian Di\t\tThoi Gian Den\n";
         // doc den khi den dong cuoi cua file 
         while (filef >> f4.MaMayBay3 >> f4.NoiDi3 >> f4.NoiDen3 >> f4.ThoiGianDi3 >> f4.ThoiGianDen3 ) {
             // kiem tra ma may bay co trung hay khong
             if (f4.NoiDen3 == noiden) {
                 // hien thi la da tim thay
                  cout<<"\n";
            cout << f4.MaMayBay3 <<"\t\t"
                 << f4.NoiDi3 <<"\t\t"
                 << f4.NoiDen3 <<"\t\t"
                 << f4.ThoiGianDi3 <<"\t\t"
                 << f4.ThoiGianDen3 <<"\n";
                 cout<<"\n";
             }
             
            
         }
         
               TimKiemChuyenBay();
         // dong file
         filef.close();

         // kiem tra xem co tim duoc khong
        /* if (!foundf) {
             // hien thi ko tim thay
             cout << "Khong tim thay chuyen bay.\n";
         }
         */
     }
     else {
         // hien thi loi
         cout << "\t\tLoi. Khong The Mo File.\n";
     }
     break;
}
     default:
     break;
    }
    
}