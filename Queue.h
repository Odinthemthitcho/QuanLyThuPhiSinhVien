#ifndef QUEUE_H
#define QUEUE_H

#include "SinhVien.h"

struct QueueNode {
    SinhVien data;
    QueueNode* next;
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    void init();
    bool isEmpty();
    void enqueue(const SinhVien& sv);
    SinhVien dequeue();
    void inQueue();
    void clear(); 
};

#endif