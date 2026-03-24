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

