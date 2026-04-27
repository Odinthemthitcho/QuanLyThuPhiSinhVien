#include "HoaDon.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

// Nhập hóa đơn
HoaDon nhapHoaDon() {
    HoaDon hd;

    cout << "Nhap ma hoa don: ";
    getline(cin, hd.maHD);
    while (hd.maHD.empty()) {
        cout << "Ma hoa don khong duoc de trong. Nhap lai: ";
        getline(cin, hd.maHD);
    }

    cout << "Nhap ma sinh vien: ";
    getline(cin, hd.maSV);
    while (hd.maSV.empty()) {
        cout << "Ma sinh vien khong duoc de trong. Nhap lai: ";
        getline(cin, hd.maSV);
    }

    cout << "Nhap ngay lap (dd/mm/yyyy): ";
    getline(cin, hd.ngayLap);
    while (hd.ngayLap.empty()) {
        cout << "Ngay lap khong duoc de trong. Nhap lai: ";
        getline(cin, hd.ngayLap);
    }

    cout << "Nhap so tien: ";
    while (!(cin >> hd.soTien) || hd.soTien < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "So tien khong hop le. Nhap lai: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    hd.prev = nullptr;
    hd.next = nullptr;

    return hd;
}

// In hóa đơn
void inHoaDon(const HoaDon& hd) {
    cout << "----------------------------" << endl;
    cout << "Ma hoa don: " << hd.maHD << endl;
    cout << "Ma sinh vien: " << hd.maSV << endl;
    cout << "Ngay lap: " << hd.ngayLap << endl;
    cout << "So tien: " << hd.soTien << endl;
    cout << "----------------------------" << endl;
}

// Lưu file
void luuFileHoaDon(HoaDon* head, const string& filename) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cerr << "Loi: Khong the mo file!" << endl;
        return;
    }

    for (HoaDon* p = head; p != nullptr; p = p->next) {
        fout << p->maHD << "|"
             << p->maSV << "|"
             << p->ngayLap << "|"
             << p->soTien << endl;
    }

    fout.close();
}

// Đọc file
HoaDon* docFileHoaDon(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Loi: Khong the mo file!" << endl;
        return nullptr;
    }

    HoaDon* head = nullptr;
    HoaDon* tail = nullptr;

    string maHD, maSV, ngayLap;
    float soTien;

    while (getline(fin, maHD, '|') &&
           getline(fin, maSV, '|') &&
           getline(fin, ngayLap, '|') &&
           fin >> soTien) {

        fin.ignore(); // bỏ newline

        HoaDon* node = new HoaDon{maHD, maSV, ngayLap, soTien, nullptr, nullptr};

        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    fin.close();
    return head;
}

// Tìm
HoaDon* timTheoMaHD(HoaDon* head, const string& maHD) {
    for (HoaDon* p = head; p != nullptr; p = p->next) {
        if (p->maHD == maHD)
            return p;
    }
    return nullptr;
}

// Xóa
void xoaHoaDon(HoaDon*& head, const string& maHD) {
    HoaDon* p = timTheoMaHD(head, maHD);

    if (p == nullptr) {
        cout << "Khong tim thay!" << endl;
        return;
    }

    if (p->prev)
        p->prev->next = p->next;
    else
        head = p->next;

    if (p->next)
        p->next->prev = p->prev;

    delete p;
    cout << "Da xoa thanh cong!" << endl;
}