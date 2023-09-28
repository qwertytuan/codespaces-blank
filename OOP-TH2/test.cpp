
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


class Bac2 {
    
    private:
        double a, b,c; 
    public:
        
        Bac2(double x, double y, double z) {
            a = x;
            b = y;
            c = z;
        }
       
        void giaipt() {
          
            double d = b * b - 4 * a * c;
            
            if (d == 0) {
                
                cout << "Pt co 1 nghiem " << endl;
                
                double x = -b / (2 * a);
                cout << "x1=x2= " << x << endl;
            }
           
            else {
                
                cout << "phuong trinh co 2 nghiem phan biet:" << endl;
                
                double x1 = (-b + sqrt(d)) / (2 * a);
                double x2 = (-b - sqrt(d)) / (2 * a);
                cout << "x1= " << x1 << endl;
                cout << "x2= " << x2 << endl;
            }
        }
};


int main() 
{
    srand(time(0));
    // tạo 10 đối tượng Bac1 với các giá trị a và b ngẫu nhiên từ -10 đến 10
    for (int i = 0; i < 10; i++) {
        double a = rand() % 21 - 10; // số ngẫu nhiên từ -10 đến 10
        double b = rand() % 21 - 10;
        double c = rand() % 21 - 10; 
        Bac2 pt(a,b,c); // tạo đối tượng pt thuộc lớp Bac1
        pt.giaipt(); // gọi hàm giải phương trình cho đối tượng pt
    }

}
 