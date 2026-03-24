#include "SinhVien.h"
#include <iostream>
#include <fstream>
using namespace std;

// Nhập thông tin sinh viên
SinhVien nhapSinhVien() {
    SinhVien sv;
    //  Nhập mã, tên, số tiền
    return sv;
}

// In thông tin sinh viên
void inSinhVien(const SinhVien& sv) {
    // In ra console: maSV, tenSV, hocPhi
}

// Lưu danh sách sinh viên vào file
void luuFileSinhVien(SinhVien* head, const string& filename) {
    //Duyệt danh sách, ghi vào file
}

// Đọc danh sách sinh viên từ file
SinhVien* docFileSinhVien(const string& filename) {
    //Đọc file, tạo linked list, trả về head
    return nullptr;
}

// Tìm sinh viên theo tên
SinhVien* timTheoTen(SinhVien* head, const string& ten) {
    //Duyệt danh sách, trả về node đầu tiên khớp
    return nullptr;
}