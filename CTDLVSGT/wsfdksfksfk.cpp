#include <iostream>
#include<string.h>
using namespace std;

struct SinhVien
{
    int data;
    int id;
    string HoTen;
    int Diem;
    SinhVien *next;
};

struct List
{
    SinhVien *first;
    SinhVien *last;
};

List L;

// Khoi tao 1 danh sach rong
void createList(List &L)
{
    L.first = L.last = NULL;
}

// Tao 1 nut moi
SinhVien *getSinhVien(int x,int Id,string HoTen,int diem)
{
    SinhVien *p;
    p = new SinhVien;
    p->data = x;
    p->id=Id;
    p->HoTen=HoTen;
    p->Diem=diem;
    p->next = NULL;
    return p;
}

// Bo sung 1 nut vao dau danh sach
void addFirst(List &L, SinhVien *p)
{
    if (L.first == NULL && L.last == NULL)
        L.last = p;
    else
        p->next = L.first;

    L.first = p;
}

// Bo sung 1 nut vao cuoi danh sach
void addLast(List &L, SinhVien *p)
{
    if (L.first == NULL && L.last == NULL)
        L.first = p;
    else
        L.last->next = p;
    L.last = p;
}

void deleteSinhVien(List &L, SinhVien *p)
{
    if (p == L.first)
    {
        // Xoa nut dau tien
        L.first = p->next;

        // Trường hợp danh sach chỉ có 1 nút
        if (p == L.last)
            L.last = NULL;
        delete p;
    }
    else
    {
        SinhVien *q = L.first;
        while (q->next != p)
            q = q->next;
        q->next = p->next;
        if (p == L.last)
            L.last = q;
        delete p;
    }
}

// Tim nut co data = x
SinhVien *searchSinhVien(List L, int x)
{
    SinhVien *p = L.first;
    while (p != NULL && p->data != x)
        p = p->next;
    return p;
}

// In danh sach ra man hinh
void displayList(List L)
{
    if (L.first == NULL && L.last == NULL)
        cout << "Danh sách rỗng";
    else
        for (SinhVien *p = L.first; p != NULL; p = p->next)
            cout << p->data << " "<<p->id<<" "<<p->HoTen;
}

int main()
{
    
    int n, x,Id,diem;
    string HoTen;
    cout << "Số lượng số nguyên cần nhập n = ";
    cin >> n;

    createList(L);
    for (int i = 1; i <= n; i++)
    {
        cout << "+ Nhập số nguyên thứ " << i << ": ";
        cin >> x;
        // addFirst(L, getSinhVien(x));
        addLast(L, getSinhVien(x,Id,HoTen,diem));
    }

    cout << "Danh sách được tạo là:\n";
    displayList(L);

    cout << "\nNhập giá trị cần xóa: ";
    cin >> x;
    SinhVien *p = searchSinhVien(L, x);
    if (p == NULL)
        cout
            << "Không tồn tại giá trị\n";
    else
        deleteSinhVien(L, p);
    cout << "Danh sách sau khi xóa là:\n";
    displayList(L);
}
