#ifndef HOADON_H
#define HOADON_H

#include <string>
using namespace std;

struct HoaDon {
    string maHD;
    string maSV;
    string ngayLap;
    float soTien;
    HoaDon* prev;
    HoaDon* next;
};

// Nhập / xuất
HoaDon nhapHoaDon();
void inHoaDon(const HoaDon& hd);

// File
void luuFileHoaDon(HoaDon* head, const string& filename);
HoaDon* docFileHoaDon(const string& filename);

// Xử lý
HoaDon* timTheoMaHD(HoaDon* head, const string& maHD);
void xoaHoaDon(HoaDon*& head, const string& maHD);

#endif