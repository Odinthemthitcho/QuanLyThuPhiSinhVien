#include "Stack.h"
#include <iostream>
using namespace std;

// Khởi tạo
void Stack::init() {
    top = nullptr;
}

// Kiểm tra rỗng
bool Stack::isEmpty() {
    return top == nullptr;
}

// Thêm vào stack (push)
void Stack::push(const HoaDon& hd) {
    StackNode* node = new StackNode;
    node->data = hd;
    node->next = top;
    top = node;
}

// Lấy ra khỏi stack (pop)
HoaDon Stack::pop() {
    if (isEmpty()) {
        cout << "Stack rong!\n";
        return HoaDon(); // trả về rỗng
    }

    StackNode* temp = top;
    HoaDon hd = temp->data;

    top = top->next;
    delete temp;

    return hd;
}

// Đếm số phần tử
int Stack::demStack() {
    int count = 0;
    StackNode* temp = top;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Tìm theo mã hóa đơn
StackNode* Stack::timStack(const string& maHD) {
    StackNode* temp = top;

    while (temp != nullptr) {
        if (temp->data.maHD == maHD)
            return temp;
        temp = temp->next;
    }

    return nullptr;
}

// In stack (🔥 dùng hàm global)
void Stack::inStack() {
    if (isEmpty()) {
        cout << "Stack rong!\n";
        return;
    }

    cout << "\n=== Lich su giao dich ===\n";
    StackNode* temp = top;

    while (temp != nullptr) {
        inHoaDon(temp->data); // 🔥 hàm global của bạn
        temp = temp->next;
    }
}

// Xóa toàn bộ
void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}