#include <iostream>
#include <vector>
using namespace std;

struct SINHVIEN
{
    int id;
    string name;
    double score;
};

vector<SINHVIEN> SinhVien; // Sử dụng vector để lưu trữ danh sách sinh viên

// Khởi tạo danh sách rỗng
void TaoDanhSach()
{
    SinhVien.clear();
}

// Thêm sinh viên vào danh sách
void ThemSV(SINHVIEN SINHVIEN)
{
    SinhVien.push_back(SINHVIEN);
}

// Xóa sinh viên khỏi danh sách dựa trên ID
void XoaSV(int id)
{
    for (size_t i = 0; i < SinhVien.size(); i++)
    {
        if (SinhVien[i].id == id)
        {
            SinhVien.erase(SinhVien.begin() + i);
            return;
        }
    }
}

// Tìm sinh viên dựa trên ID
SINHVIEN* TimSINHVIEN(int id)
{
    for (size_t i = 0; i < SinhVien.size(); i++)
    {
        if (SinhVien[i].id == id)
        {
            return &SinhVien[i];
        }
    }
    return nullptr;
}

// In danh sách sinh viên ra màn hình
void HienThiDanhSach()
{
    if (SinhVien.empty())
    {
        cout << "-Danh sách rỗng";
    }
    else
    {
        for (const SINHVIEN& SINHVIEN : SinhVien)
        {
            cout << "ID: " << SINHVIEN.id << ", Name: " << SINHVIEN.name << ", Score: " << SINHVIEN.score << endl;
        }
    }
}

int main()
{
    int n, id;
    string name;
    double score;
    cout << "-Số lượng sinh viên cần nhập n = ";
    cin >> n;

    TaoDanhSach();
    for (int i = 1; i <= n; i++)
    {
        cout << "--Nhập thông tin sinh viên thứ " << i << ":\n";
        cout << "  - ID: ";
        cin >> id;
        cout << "  - Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "  - Score: ";
        cin >> score;
        SINHVIEN SINHVIEN = {id, name, score};
        ThemSV(SINHVIEN);
    }

    cout << "-Danh sách sinh viên được tạo là:\n";
    HienThiDanhSach();

    cout << "\n--Nhập ID của sinh viên cần xóa: ";
    cin >> id;
    SINHVIEN* foundSINHVIEN = TimSINHVIEN(id);
    if (foundSINHVIEN != nullptr)
    {
        XoaSV(id);
        cout << "-Sinh viên có ID " << id << " đã được xóa.\n";
    }
    else
    {
        cout << "-Không tồn tại sinh viên có ID " << id << "\n";
    }

    cout << "-Danh sách sinh viên sau khi xóa là:\n";
    HienThiDanhSach();

    return 0;
}
