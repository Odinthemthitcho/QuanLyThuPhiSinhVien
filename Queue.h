#ifndef QUEUE_H
#define QUEUE_H

#include "SinhVien.h"

struct QueueNode {
    SinhVien data;
    QueueNode* next;
};

class Queue {
private:
    QueueNode* front; // đầu hàng đợi
    QueueNode* rear;  // cuối hàng đợi

public:
    void init(); // Khởi tạo hàng đợi rỗng
    void enqueue(const SinhVien& sv); // Thêm sinh viên vào cuối queue
    SinhVien dequeue(); // Lấy sinh viên từ đầu queue
    void inQueue(); // In danh sách sinh viên trong queue
};

