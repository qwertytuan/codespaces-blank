#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string ma_may_bay;
    cout<<"NHap:";
    cin>>ma_may_bay;
  // Mở file input.txt để đọc
  ifstream infile;
  infile.open("LuuTruMayBay.txt");
  if (!infile.is_open())
  {
    cout << "Không thể mở file input.txt\n";
    return 1;
  }

  // Đọc từng dòng từ file và kiểm tra xem có chứa chuỗi tuan1 hay không
  string line;
  while (getline(infile, line))
  {
    if (line.find(ma_may_bay) != string::npos) // Nếu tìm thấy chuỗi tuan1 trong dòng
    {
      // Chuyển đổi dòng thành một stream
      stringstream ss(line);
      // Đọc từng phần tử từ stream
      string element;
      while (ss >> element)
      {
        // In ra phần tử
        cout << element << endl;
      }
    }
  }

  // Đóng file
  infile.close();
  return 0;
}