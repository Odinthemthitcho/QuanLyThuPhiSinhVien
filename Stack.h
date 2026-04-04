#ifndef STACK_H
#define STACK_H

#include "HoaDon.h"

struct StackNode {
    HoaDon data;
    StackNode* next;
};

class Stack {

private:
    StackNode* top; // Node đỉnh của stack

public:
    void init(); // Khởi tạo stack rỗng
    void push(const HoaDon& hd); // Thêm hóa đơn lên stack
    HoaDon pop(); // Lấy hóa đơn từ stack
    int demStack(); // Đếm số node trong stack
    StackNode* timStack(const string& maHD); // Tìm node theo mã hóa đơn
};

