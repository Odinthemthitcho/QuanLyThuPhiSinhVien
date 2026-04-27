#include "Queue.h"
#include <iostream>
using namespace std;

// Khởi tạo
void Queue::init() {
    front = rear = nullptr;
}

// Kiểm tra rỗng
bool Queue::isEmpty() {
    return front == nullptr;
}

// Thêm vào queue
void Queue::enqueue(const SinhVien& sv) {
    QueueNode* node = new QueueNode;
    node->data = sv;
    node->next = nullptr;

    if (isEmpty()) {
        front = rear = node;
    } else {
        rear->next = node;
        rear = node;
    }
}

// Lấy ra khỏi queue
SinhVien Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue rong!\n";
        return SinhVien();
    }

    QueueNode* temp = front;
    SinhVien sv = temp->data;

    front = front->next;
    if (front == nullptr)
        rear = nullptr;

    delete temp;
    return sv;
}

// In queue (🔥 dùng hàm global)
void Queue::inQueue() {
    if (isEmpty()) {
        cout << "Queue rong!\n";
        return;
    }

    QueueNode* temp = front;
    cout << "\n=== Sinh vien cho dong hoc phi ===\n";

    while (temp != nullptr) {
        inSinhVien(temp->data); // 🔥 dùng hàm global
        temp = temp->next;
    }
}

// Xóa toàn bộ
void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}