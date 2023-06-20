#include<iostream>
#include<fstream>
#include<string.h>
#include"ham-admin.hpp"
#include"y2.hpp"
#include "778.hpp"
using namespace std;

void DangNhap();
void DangKy();
void QuenMK();

int main()
{
	int c;
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl; 
	cout<<"\t\t\t______________________________________________________________\n\n\n";
	cout<<"\t\t\t________________Chao mung den voi trang dang nhap_____________\n\n";
	cout<<"\t\t\t_________________________    Menu   __________________________\n\n\n";
	cout<<"                                                                       \n\n";
	cout<<"\t|=====================================|"<<endl;
	cout<<"\t|   chon 1 de dang nhap               |"<<endl;
	cout<<"\t|   chon 2 de dang ky                 |"<<endl;
	cout<<"\t|   chon 3 neu ban quen mat khau      |"<<endl;
	cout<<"\t|   chon 4 de thoat                   |"<<endl;
	cout<<"\t|   chon 5 de muc vao muc dat ve      |"<<endl;
	cout<<"\t|=====================================|"<<endl;
	cout<<"\n\t\t\t Vui long nhap lua chon cua ban : ";
	cin>>c;
	cout<<endl;
	
	switch(c)
	{
		case 1 :
			DangNhap();
			break;
		case 2 :
		    QuenMK();
			break;	
		case 3 :
		    cout<<"\t\t\t Cam on!   \n\n";
			break;
		default:
		    cout<<"\t\t\t Vui long chon cac tuy chon da cung cap tren \n"<<endl;
			main();
			 	
	 } 
	
}
// Ham DangNhap() dung file LuuTru.txt de luu tai khoan va mat khau theo dang "ten tk" "mat khau".
    void DangNhap()
    {
    	int count;
    	string userId, password, Id, pass;
    	system("cls");
    	cout<<"\t\t\t Vui long nhap ten tai khoan va mat khau: "<<endl;
    	cout<<"\t\t\t Ten tai khoan : ";
    	cin>>userId;
    	cout<<"\t\t\t Mat khau :" ;
		echo( false );
        cin>>password;
        echo( true );
    	ifstream input("LuuTru.txt");
    	
    	while(input>>Id>>pass)
    	{
			// neu userId ta nhap trung voi Id da luu trong LuuTru.txt thi cho bien count=1
    		if(Id==userId && pass==password)
    		{
    			count=1;
    			system("cls");
    			
			}
		}
		input.close();
		// neu count=1 thi ta xac nhan da dang nhap thanh cong
		if(count==1)
		{
			cout<<userId<<"\n Dang nhap cua ban thanh cong! \n Cam on vi da dang nhap! \n";
			main3();
			
		}
		// neu count khac 1 thi quay lai menu
		else{
			cout<<"\n Loi dang nhap! \n Vui long kiem tra ten dang nhap va mat khau! \n";
			main();
			
		}
	}
	// ham DangKy() doc dau vao cua nguoi dung va luu vào file LuuTru.txt de ham DangNhap() dung
	void DangKy()
	{
		string ruserId, rpassword, rId, rpass, rcccd;
		system("cls");
		cout<<"\t\t\t Nhap ten nguoi dung : ";
		cin>>ruserId;
		cout<<"\t\t\t Nhap mat khau : ";
		cin>>rpassword;
		cout<<"\n";
		cout<<"\t\t\t Nhap can cuoc cong dan : ";
		cin>>rcccd;
		//nhap du lieu cua nguoi dung vao file txt 
		ofstream f1("LuuTru.txt", ios::app);
		f1<<ruserId<<' '<<rpassword<<' '<<rcccd<<endl;
		system("cls");
		cout<<"\n\t\t\t  Dang ky cua ban thanh cong! \n";
		main();
		
	}
	// ham QuenMK kiem tra xem userId nguoi dung nhap co trung voi Id da luu trong LuuTru.txt khong
	void QuenMK()
	{
		int option;
		system("cls");
		cout<<"\t\t|==================================================|"<<endl;
		cout<<"\t\t|\tBan quen mat khau ? Dung lo lang!               |"<<endl; 
		cout<<"\t\t|Chon 1 de tim kiem id cua ban theo ten nguoi dung.|"<<endl;
		cout<<"\t\t|Chon 2 de quay lai menu chinh.                    |"<<endl;
		cout<<"\t\t|==================================================|"<<endl;
		cout<<"\t\t\t Nhap lua chon cua ban : ";
		cin>>option;
		switch(option)
		{
			
			case 1 :
			{
				int count=0;
				string suserId, sId, spass, spassword;
				cout<<"\n\t\t\tNhap ten nguoi dung ma ban da nho : ";
				cin>>suserId;
				
				ifstream f2("LuuTru.txt");
				while(f2>>sId>>spass)
				{
					// neu trung thi cho count =1
					if(suserId==sId)
					{
						count=1;
						
					}
				}
				f2.close();
				// neu count =1 thi hien thi mk
				if(count==1)
				{
					cout<<"\n\n Tai khoan cua ban da tim thay! \n"<<endl;
					cout<<"\n\n Mat khau cua ban la :"<<spass<<endl;
					main();
					
				}
				else{
					cout<<"\n\t Xin loi! Tai khoan cua ban khong duoc tim thay! \n";
					main();
					
				}
				break;
				
			}
		    case 2 :
			    {
				    main();
				
		         	}
			default:
				cout<<"\t\t\t Su lua chon sai lam! Vui long thu lai! \n"<<endl;
				main();
				
		}
}
