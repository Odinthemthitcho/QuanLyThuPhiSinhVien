#include "HoaDon.h"
#include <iostream>
#include <fstream>
using namespace std;

// Nhập hóa đơn
HoaDon nhapHoaDon() {
    HoaDon hd;
    //Nhập maHD, maSV, ngayLap, soTien
    return hd;
}

// In hóa đơn
void inHoaDon(const HoaDon& hd) {
    // In maHD, maSV, ngayLap, soTien
}

// Lưu danh sách hóa đơn vào file
void luuFileHoaDon(HoaDon* head, const string& filename) {
    //Duyệt danh sách, ghi vào file

// Đọc danh sách hóa đơn từ file
HoaDon* docFileHoaDon(const string& filename) {
    // Đọc file, tạo linked list, trả về head
    return nullptr;
}

// Tìm hóa đơn theo mã
HoaDon* timTheoMaHD(HoaDon* head, const string& maHD) {
    //  Duyệt danh sách, trả về node đầu tiên khớp
    return nullptr;
}

// Sửa hóa đơn theo mã
void suaHoaDon(HoaDon* head, const string& maHD) {
    // Duyệt danh sách, tìm node khớp maHD, sửa thông tin
}

// Xóa hóa đơn theo mã
void xoaHoaDon(HoaDon*& head, const string& maHD) {
    //Duyệt danh sách, tìm node khớp maHD, xóa node đó
}