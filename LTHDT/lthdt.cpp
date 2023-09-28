#include<iostream>
using namespace std;
class point{
private:
float x, y;
public:
//khai báo và đ/n hàm thành phần
void init(float x, float y){
this->x = x; this->y = y;
}
//khai báo nguyên mẫu các hàm
void move(float dx, float dy);
void display();
}; //kết thúc khai báo lớp
//đ/n các hàm chưa đ/n trong lớp
void point::move(float dx,float dy)
{
x += dx; y += dy;
}
void point::display()
{
cout<<"\n x= "<<x<<" y = "<<y;
}
int main() {
point p;

p.init(2,3);
p.display();
p.move(3,4);
p.display();
}
