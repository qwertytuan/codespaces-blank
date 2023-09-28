#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Bac1
{
    private:
    float a,b;
     public:
        
        Bac1(float x, float y) {
            a = x;
            b = y;
        }

  void giaipt()
  {
    cout << "Phuong trinh: " << a << "x^2 + " << b<<"x + " << c << " = 0" << endl;
            if (a == 0) {
                if (b == 0) 
                {
                    cout << "Phuong trinh vo so nghiem" << endl;
                } 
                else 
                {
                    cout << "Phuong trinh vo nghiem" << endl;
                }
            } 
            else 
            {
                float x = -b / a;
                cout << "Phuong trinh co nghiem duy nhat: x = " << x << endl;
            }
            cout << endl;
        }
};

int main()
{
    // khởi tạo số ngẫu nhiên
    srand(time(0));
    // tạo 10 đối tượng Bac1 với các giá trị a và b ngẫu nhiên từ -10 đến 10
    for (int i = 0; i < 10; i++) {
        float a = rand() % 21 - 10; // số ngẫu nhiên từ -10 đến 10
        float b = rand() % 21 - 10; // số ngẫu nhiên từ -10 đến 10
        Bac1 pt(a, b); // tạo đối tượng pt thuộc lớp Bac1
        pt.giaipt(); // gọi hàm giải phương trình cho đối tượng pt
    }
}
