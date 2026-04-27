#ifndef STACK_H
#define STACK_H

#include "HoaDon.h"

struct StackNode {
    HoaDon data;
    StackNode* next;
};

class Stack {
private:
    StackNode* top; 

public:
    void init();
    bool isEmpty(); 
    void push(const HoaDon& hd);
    HoaDon pop();
    int demStack();
    StackNode* timStack(const string& maHD);
    void inStack(); 
    void clear();
};

#endif