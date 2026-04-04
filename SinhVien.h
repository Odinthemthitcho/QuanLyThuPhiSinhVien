#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <string>
using namespace std;

struct SinhVien {
    string maSV;
    string tenSV;
    float hocPhi;
    SinhVien* next; // Dùng cho DSLK_Don
};

// Khai báo
SinhVien nhapSinhVien();
void inSinhVien(const SinhVien& sv);
void luuFileSinhVien(SinhVien* head, const string& filename);
SinhVien* docFileSinhVien(const string& filename);
SinhVien* timTheoTen(SinhVien* head, const string& ten);

#endif