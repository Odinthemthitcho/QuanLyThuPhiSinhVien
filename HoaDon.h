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

