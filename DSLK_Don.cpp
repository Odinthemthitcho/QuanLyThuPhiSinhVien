#include "DSLK_Don.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

// Khởi tạo
void DSLK_Don::init() {
    head = nullptr;
}

// Tạo node
NodeSinhVien* DSLK_Don::taoNode(const SinhVien& sv) {
    NodeSinhVien* newNode = new NodeSinhVien;
    newNode->data = sv;
    newNode->next = nullptr;
    return newNode;
}

// Thêm đầu
void DSLK_Don::themDau(const SinhVien& sv) {
    NodeSinhVien* newNode = taoNode(sv);
    newNode->next = head;
    head = newNode;
}

// Thêm cuối
void DSLK_Don::themCuoi(const SinhVien& sv) {
    NodeSinhVien* newNode = taoNode(sv);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    NodeSinhVien* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Nhập danh sách (🔥 dùng hàm global)
void DSLK_Don::nhapDanhSach() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nSinh vien thu " << i + 1 << ":\n";
        SinhVien sv = nhapSinhVien(); // ✅ FIX
        themCuoi(sv);
    }
}

// In danh sách (🔥 dùng hàm global)
void DSLK_Don::inDanhSach() {
    if (head == nullptr) {
        cout << "Danh sach rong!\n";
        return;
    }

    NodeSinhVien* temp = head;
    int i = 1;

    while (temp != nullptr) {
        cout << "\nSinh vien " << i++ << ":\n";
        inSinhVien(temp->data); // ✅ FIX
        temp = temp->next;
    }
}

// Xóa theo mã
void DSLK_Don::xoaTheoMa(const string& maSV) {
    if (head == nullptr) {
        cout << "Danh sach rong!\n";
        return;
    }

    if (head->data.maSV == maSV) {
        NodeSinhVien* temp = head;
        head = head->next;
        delete temp;
        cout << "Da xoa!\n";
        return;
    }

    NodeSinhVien* prev = head;
    NodeSinhVien* curr = head->next;

    while (curr != nullptr && curr->data.maSV != maSV) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Khong tim thay!\n";
        return;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Da xoa!\n";
}

// Tìm theo tên
NodeSinhVien* DSLK_Don::timTheoTen(const string& tenSV) {
    NodeSinhVien* temp = head;

    while (temp != nullptr) {
        if (temp->data.tenSV == tenSV)
            return temp;
        temp = temp->next;
    }

    return nullptr;
}

// Sắp xếp
void DSLK_Don::sapXepTheoHocPhi() {
    for (NodeSinhVien* i = head; i != nullptr; i = i->next) {
        for (NodeSinhVien* j = i->next; j != nullptr; j = j->next) {
            if (i->data.hocPhi > j->data.hocPhi) {
                swap(i->data, j->data);
            }
        }
    }
    cout << "Da sap xep!\n";
}

// Lưu file
void DSLK_Don::luuFile(const string& filename) {
    ofstream out(filename);

    if (!out.is_open()) {
        cout << "Loi mo file!\n";
        return;
    }

    NodeSinhVien* temp = head;

    while (temp != nullptr) {
        out << temp->data.maSV << "|"
            << temp->data.tenSV << "|"
            << temp->data.hocPhi << endl;
        temp = temp->next;
    }

    out.close();
    cout << "Luu file thanh cong!\n";
}

// Đọc file
void DSLK_Don::docFile(const string& filename) {
    ifstream in(filename);

    if (!in.is_open()) {
        cout << "Loi mo file!\n";
        return;
    }

    clear();

    string ma, ten;
    float hocPhi;

    while (getline(in, ma, '|') &&
           getline(in, ten, '|') &&
           in >> hocPhi) {

        in.ignore();

        SinhVien sv;
        sv.maSV = ma;
        sv.tenSV = ten;
        sv.hocPhi = hocPhi;

        themCuoi(sv);
    }

    in.close();
    cout << "Doc file thanh cong!\n";
}

// Xóa toàn bộ
void DSLK_Don::clear() {
    while (head != nullptr) {
        NodeSinhVien* temp = head;
        head = head->next;
        delete temp;
    }
}