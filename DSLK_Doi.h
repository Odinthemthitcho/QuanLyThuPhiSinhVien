#ifndef DSLK_DOI_H
#define DSLK_DOI_H

#include "HoaDon.h"

struct NodeHoaDon {
    HoaDon data;
    NodeHoaDon* prev;
    NodeHoaDon* next;
};

class DSLK_Doi {
private:
    NodeHoaDon* head; // đầu danh sách
    NodeHoaDon* tail; // cuối danh sách

public:
    void init(); // Khởi tạo danh sách rỗng

    // Thêm node vào đầu
    void themDau(const HoaDon& hd);

    // Thêm node vào cuối
    void themCuoi(const HoaDon& hd);

    // In toàn bộ danh sách
    void inDanhSach();

    // Xóa node theo mã hóa đơn
    void xoaNode(const string& maHD);

    // Sửa node theo mã hóa đơn
    void suaNode(const string& maHD);

    // Tìm node theo mã hóa đơn
    NodeHoaDon* timTheoMa(const string& maHD);

    // Lưu danh sách vào file
    void luuFile(const string& filename);

    // Đọc danh sách từ file
    void docFile(const string& filename);
};
