#include "SinhVien.h"
#include <iostream>
#include <fstream>
using namespace std;

// Nhập thông tin sinh viên
SinhVien nhapSinhVien() {
    SinhVien sv;

    cout << "Nhap ma SV: ";
    getline(cin, sv.maSV);

    cout << "Nhap ten SV: ";
    getline(cin, sv.tenSV);

    cout << "Nhap hoc phi: ";
    cin >> sv.hocPhi;
    cin.ignore();

    sv.next = nullptr;
    return sv;
}

// In thông tin 
void inSinhVien(const SinhVien& sv) {
    cout << "Ma SV: " << sv.maSV << endl;
    cout << "Ten SV: " << sv.tenSV << endl;
    cout << "Hoc phi: " << sv.hocPhi << endl;
    cout << "------------------" << endl;
}

// Lưu danh sách
void luuFileSinhVien(SinhVien* head, const string& filename) {
    ofstream out(filename);

    SinhVien* p = head;
    while (p != nullptr) {
        out << p->maSV << endl;
        out << p->tenSV << endl;
        out << p->hocPhi << endl;
        p = p->next;
    }

    out.close();
}

// Đọc danh sách
SinhVien* docFileSinhVien(const string& filename) {
    ifstream in(filename);

    SinhVien* head = nullptr;
    SinhVien* tail = nullptr;

    while (true) {
        SinhVien* sv = new SinhVien;

        getline(in, sv->maSV);
        if (sv->maSV == "") {
            delete sv;
            break;
        }

        getline(in, sv->tenSV);
        in >> sv->hocPhi;
        in.ignore();

        sv->next = nullptr;

        if (head == nullptr) {
            head = tail = sv;
        } else {
            tail->next = sv;
            tail = sv;
        }
    }

    in.close();
    return head;
}

// Tìm sinh viên theo tên
SinhVien* timTheoTen(SinhVien* head, const string& ten) {
    SinhVien* p = head;

    while (p != nullptr) {
        if (p->tenSV.find(ten) != string::npos) {
            return p;
        }
        p = p->next;
    }

    return nullptr;
}