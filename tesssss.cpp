#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct SinhVien
{
    int masv;
    char hoten[50];
    float diemtb;
    char diachi[100];
    struct SinhVien *next;
};

struct DanhSach
{
    SinhVien *head;
    SinhVien *tail;
};
DanhSach ds;

void khoiTao(DanhSach *ds)
{
    ds->head = NULL;
    ds->tail = NULL;
}

SinhVien *taoSinhVien(int masv, char *hoten, float diemtb, char *diachi)
{
    SinhVien *sv = (SinhVien *)malloc(sizeof(SinhVien)); // Cap phat bo nho dong cho sinh vien
    sv->masv = masv;
    strcpy(sv->hoten, hoten);
    sv->diemtb = diemtb;
    strcpy(sv->diachi, diachi);
    sv->next = NULL; // Gan gia tri NULL cho con tro next cua sinh vien
    return sv;
}

void themSinhVien(DanhSach *ds, SinhVien *sv)
{
    if (ds->head == NULL)
    {
        ds->head = sv;
        ds->tail = sv;
    }
    else
    {
        ds->tail->next = sv;
        ds->tail = sv;
    }
}

SinhVien *xoaSinhVien(DanhSach *ds)
{
    if (ds->head == NULL)
    {
        return NULL;
    }
    else
    {
        SinhVien *sv = ds->head;
        ds->head = ds->head->next;
        if (ds->head == NULL)
        {
            ds->tail = NULL;
        }
        return sv;
    }
}

int isEmpty(DanhSach *ds)
{
    return (ds->head == NULL);
}

SinhVien *front(DanhSach *ds)
{
    return ds->head;
}

void inSinhVien(SinhVien *sv)
{
    cout << "Ma so: " << sv->masv << endl;
    cout << "Ho ten:" << sv->hoten << endl;
    cout << "Diem trung binh:" << sv->diemtb << endl;
    cout << "Dia chi:" << sv->diachi << endl;
    cout << "\n";
}

void inDanhSach(DanhSach *ds)
{
    SinhVien *sv = ds->head; // Gan con tro sv bang con tro head cua danh sach lien ket
    while (sv != NULL)
    {
        inSinhVien(sv);
        sv = sv->next; // Cap nhat lai con tro sv bang con tro next cua sinh vien hien tai
    }
}

int tinhSoSinhVienDiemTBtren8(DanhSach *ds)
{
    int dem = 0;
    SinhVien *sv = ds->head; // Gan con tro sv bang con tro head cua danh sach lien ket
    while (sv != NULL)
    {
        if (sv->diemtb > 8)
        {
            dem++;
        }
        sv = sv->next; // Cap nhat lai con tro sv bang con tro next cua sinh vien hien tai
    }
    return dem; // Tra ve gia tri cua bien dem
}

void nhapDanhSach(DanhSach *ds, int n)
{
    khoiTao(ds); // Goi ham khoiTao de khoi tao danh sach rong
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin sinh vien thu :" << i + 1 << endl;
        int masv;
        char hoten[50];
        float diemtb;
        char diachi[100];
        cout << "Nhap ma so: ";
        cin >> masv;
        cout << "Nhap ho ten: ";
        cin >> hoten;
        cout << "Nhap diem trung binh: ";
        cin >> diemtb;
        cout << "Nhap dia chi: ";
        cin >> diachi;

        SinhVien *sv = taoSinhVien(masv, hoten, diemtb, diachi);
        themSinhVien(ds, sv);
        cout << "\n";
    }
}


SinhVien *xoaSinhVienTheoMa(DanhSach *ds, int masv)
{
    if (ds->head == NULL)
    {               
        return NULL;
    }
    else
    {                           
        SinhVien *sv = ds->head; // Gan con tro sv bang con tro head cua danh sach lien ket
        SinhVien *prev = NULL;   // Gan con tro prev bang NULL de luu lai con tro tro den phan tu truoc sv
        while (sv != NULL)
        { 
            if (sv->masv == masv)
            { 
                if (prev == NULL)
                {                        // Neu sv la phan tu dau tien cua danh sach
                    ds->head = sv->next; // Cap nhat lai con tro head bang con tro next cua sv
                    if (ds->head == NULL)
                    {                    // Neu danh sach chi co mot phan tu
                        ds->tail = NULL; // Cap nhat lai con tro tail bang NULL
                    }
                }
                else
                {                          // Neu sv khong phai la phan tu dau tien cua danh sach
                    prev->next = sv->next; // Cap nhat lai con tro next cua prev bang con tro next cua sv
                    if (sv == ds->tail)
                    {                    // Neu sv la phan tu cuoi cung cua danh sach
                        ds->tail = prev; // Cap nhat lai con tro tail bang prev
                    }
                }
                return sv; // Tra ve con tro sv
            }
            prev = sv;     // Cap nhat lai con tro prev bang con tro sv
            sv = sv->next; // Cap nhat lai con tro sv bang con tro next cua sv
        }
        return NULL; 
    }
}

/*void XoaSV(int masv)
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
*/

int main()
{
    DanhSach ds;
    int n, masv;
    cout<<"-----------------------------------------"<<endl;
    cout << "Nhap so SV can them:";
    cin >> n;
    nhapDanhSach(&ds, n);
    cout<<"-----------------------------------------"<<endl;
    inDanhSach(&ds);
    cout<<"-----------------------------------------"<<endl;
    cout << "Nhap ma sv can xoa:";
    cin >> masv;
    xoaSinhVienTheoMa(&ds, masv);
    cout<<"-----------------------------------------"<<endl;
    cout << "Danh Sach sau khi xoa la:\n";
    inDanhSach(&ds);
    cout<<"-----------------------------------------"<<endl;
}
