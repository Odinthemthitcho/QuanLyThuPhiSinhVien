#ifndef DSLK_DON_H
#define DSLK_DON_H

#include "SinhVien.h"

struct NodeSinhVien {
    SinhVien data;
    NodeSinhVien* next;
};

class DSLK_Don {
private:
    NodeSinhVien* head;

public:
    void init();
    NodeSinhVien* taoNode(const SinhVien& sv);
    void themDau(const SinhVien& sv);
    void themCuoi(const SinhVien& sv);
    void nhapDanhSach();
    void inDanhSach();
    void xoaTheoMa(const string& maSV);
    NodeSinhVien* timTheoTen(const string& tenSV);
    void sapXepTheoHocPhi();
    void luuFile(const string& filename);
    void docFile(const string& filename);
};

