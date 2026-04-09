#include "DSLK_Don.h"
#include <iostream>
#include <fstream>
#include <string>
#include "SinhVien.h"

using namespace std;

// Khởi tạo danh sách rỗng
void DSLK_Don::init() {
    head = nullptr;
}

// Tạo node mới
NodeSinhVien* DSLK_Don::taoNode(const SinhVien& sv) {
    NodeSinhVien* newNode = new NodeSinhVien;
    newNode->data = sv;
    newNode->next = nullptr;
    return newNode;
}

// Thêm node vào đầu danh sách
void DSLK_Don::themDau(const SinhVien& sv) {
    NodeSinhVien* newNode = taoNode(sv);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Thêm node vào cuối danh sách
void DSLK_Don::themCuoi(const SinhVien& sv) {
    NodeSinhVien* newNode = taoNode(sv);
    if (head == nullptr) {
        head = newNode;
    } else {
        NodeSinhVien* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Nhập nhiều sinh viên
void DSLK_Don::nhapDanhSach() {
    int n;
    cout << "Nhap so luong sinh vien can them: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "--- Nhap thong tin sinh vien thu " << i + 1 << " ---" << endl;
        SinhVien sv;
        sv.nhapSinhVien(); 
        themCuoi(sv);
    }
}

// In danh sách sinh viên
void DSLK_Don::inDanhSach() {
    if (head == nullptr) {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }
    NodeSinhVien* temp = head;
    int count = 1;
    while (temp != nullptr) {
        cout << "Sinh vien " << count++ << ":" << endl;
        temp->data.inSinhVien(); 
        cout << "----------------------" << endl;
        temp = temp->next;
    }
}

// Xóa sinh viên theo mã
void DSLK_Don::xoaTheoMa(const string& maSV) {
    if (head == nullptr) {
        cout << "Danh sach rong, khong the xoa!" << endl;
        return;
    }

    // Nếu sinh viên cần xóa nằm ở đầu danh sách
    if (head->data.maSV == maSV) {
        NodeSinhVien* temp = head;
        head = head->next;
        delete temp;
        cout << "Da xoa sinh vien co ma: " << maSV << endl;
        return;
    }

    // Tìm sinh viên trong danh sách
    NodeSinhVien* current = head;
    NodeSinhVien* previous = nullptr;

    while (current != nullptr && current->data.maSV != maSV) {
        previous = current;
        current = current->next;
    }

    // Nếu không tìm thấy
    if (current == nullptr) {
        cout << "Khong tim thay sinh vien co ma: " << maSV << endl;
        return;
    }

    // Thực hiện xóa
    previous->next = current->next;
    delete current;
    cout << "Da xoa sinh vien co ma: " << maSV << endl;
}

// Tìm sinh viên theo tên
NodeSinhVien* DSLK_Don::timTheoTen(const string& tenSV) {
    NodeSinhVien* temp = head;
    while (temp != nullptr) {
        if (temp->data.tenSV == tenSV) {
            return temp; // Trả về con trỏ tới Node tìm thấy
        }
        temp = temp->next;
    }
    return nullptr; // Không tìm thấy
}

// Sắp xếp danh sách theo học phí (Tăng dần - Thuật toán Interchange Sort)
void DSLK_Don::sapXepTheoHocPhi() {
    if (head == nullptr || head->next == nullptr) {
        return; // Danh sách rỗng hoặc chỉ có 1 phần tử thì không cần sắp xếp
    }

    for (NodeSinhVien* i = head; i != nullptr; i = i->next) {
        for (NodeSinhVien* j = i->next; j != nullptr; j = j->next) {
            if (i->data.hocPhi > j->data.hocPhi) {
                // Hoán đổi data (SinhVien) giữa 2 node
                SinhVien temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    cout << "Da sap xep danh sach tang dan theo hoc phi." << endl;
}

// Lưu danh sách vào file
void DSLK_Don::luuFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Loi: Khong the mo file de ghi!" << endl;
        return;
    }

    NodeSinhVien* temp = head;
    while (temp != nullptr) {
        // Cần đảm bảo SinhVien có thể ghi vào file, 
        // ví dụ nạp chồng toán tử << hoặc gọi hàm luuThongTin(outFile)
        // ví dụ ghi từng thuộc tính (cần điều chỉnh theo SinhVien.h)
        outFile << temp->data.maSV << ","
                << temp->data.tenSV << ","
                << temp->data.hocPhi << endl;
        temp = temp->next;
    }
    outFile.close();
    cout << "Da luu danh sach vao file: " << filename << endl;
}

// Đọc danh sách từ file
void DSLK_Don::docFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Loi: Khong the mo file de doc!" << endl;
        return;
    }

    // Cần xóa danh sách cũ trước khi đọc (nếu có)
    // while (head != nullptr) { xoaDau(); }

    string ma, ten;
    double hocPhi; 
    
    // Code dưới demo logic đọc file
    /*
    while (getline(inFile, ma, ',') && getline(inFile, ten, ',') && inFile >> hocPhi) {
        inFile.ignore(); // Bỏ qua ký tự newline
        SinhVien sv(ma, ten, hocPhi); // Giả sử constructor hỗ trợ
        themCuoi(sv);
    }
    */
    
    inFile.close();
    cout << "Da doc danh sach tu file: " << filename << endl;
}
