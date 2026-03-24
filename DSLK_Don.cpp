#include "DSLK_Don.h"
#include <iostream>
#include <fstream>
using namespace std;

void DSLK_Don::init() {
    //  Khởi tạo danh sách rỗng
}

NodeSinhVien* DSLK_Don::taoNode(const SinhVien& sv) {
    // Tạo node mới
    return nullptr;
}

void DSLK_Don::themDau(const SinhVien& sv) {
    //  Thêm node vào đầu danh sách
}

void DSLK_Don::themCuoi(const SinhVien& sv) {
    // Thêm node vào cuối danh sách
}

void DSLK_Don::nhapDanhSach() {
    //  Nhập nhiều sinh viên
}

void DSLK_Don::inDanhSach() {
    //  In danh sách sinh viên
}

void DSLK_Don::xoaTheoMa(const string& maSV) {
    // Xóa sinh viên theo mã
}

NodeSinhVien* DSLK_Don::timTheoTen(const string& tenSV) {
    // Tìm sinh viên theo tên
    return nullptr;
}

void DSLK_Don::sapXepTheoHocPhi() {
    // Sắp xếp danh sách theo học phí
}

void DSLK_Don::luuFile(const string& filename) {
    // Lưu danh sách vào file
}

void DSLK_Don::docFile(const string& filename) {
    // Đọc danh sách từ file
}