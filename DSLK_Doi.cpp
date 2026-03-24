#include "DSLK_Doi.h"
#include <iostream>
#include <fstream>
using namespace std;

void DSLK_Doi::init() {
    // Khởi tạo danh sách rỗng (head = tail = nullptr)
}

void DSLK_Doi::themDau(const HoaDon& hd) {
    // Tạo node mới, chèn vào đầu danh sách
}

void DSLK_Doi::themCuoi(const HoaDon& hd) {
    // Tạo node mới, chèn vào cuối danh sách
}

void DSLK_Doi::inDanhSach() {
    //  Duyệt từ head đến tail, in thông tin mỗi hóa đơn
}

void DSLK_Doi::xoaNode(const string& maHD) {
    //  Xóa node theo mã hóa đơn
}

void DSLK_Doi::suaNode(const string& maHD) {
    //  Tìm node theo mã, sửa thông tin hóa đơn
}

NodeHoaDon* DSLK_Doi::timTheoMa(const string& maHD) {
    //  Duyệt danh sách, trả về node đầu tiên có maHD khớp
    return nullptr;
}

void DSLK_Doi::luuFile(const string& filename) {
    //  Lưu danh sách hóa đơn vào file
}

void DSLK_Doi::docFile(const string& filename) {
    //  Đọc danh sách hóa đơn từ file, tạo linked list đôi
}