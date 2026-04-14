#include <iostream>
using namespace std;

   //GIẢ LẬP STRUCT


struct SinhVien {
    string maSV;
    string ten;
};

struct HoaDon {
    string maHD;
    double soTien;
};


  // HÀM IN (giả lập)


void inSinhVien(SinhVien sv) {
    cout << "Ma SV: " << sv.maSV << " | Ten: " << sv.ten << endl;
}

void inHoaDon(HoaDon hd) {
    cout << "Ma HD: " << hd.maHD << " | So tien: " << hd.soTien << endl;
}

   //STACK (HÓA ĐƠN)


struct NodeStack {
    HoaDon data;
    NodeStack* next;
};

struct Stack {
    NodeStack* top;
};

void initStack(Stack &s) {
    s.top = NULL;
}

bool isEmptyStack(Stack s) 
{
    return s.top == NULL;
}

void push(Stack &s, HoaDon x) 
{
    NodeStack* p = new NodeStack;
    p->data = x;
    p->next = s.top;
    s.top = p;
}

HoaDon pop(Stack &s) 
{
    if (isEmptyStack(s)) 
    {
        cout << "Stack rong!\n";
        return HoaDon();
    }

    NodeStack* p = s.top;
    HoaDon x = p->data;
    s.top = p->next;
    delete p;
    return x;
}

HoaDon peek(Stack s) 
{
    if (isEmptyStack(s)) 
    {
        cout << "Stack rong!\n";
        return HoaDon();
    }
    return s.top->data;
}

void printStack(Stack s) 
{
    NodeStack* p = s.top;
    cout << "\n=== Lich su hoa don ===\n";
    while (p != NULL)
    {
        inHoaDon(p->data);
        p = p->next;
    }
}


  // QUEUE (SINH VIÊN)


struct NodeQueue 
{
    SinhVien data;
    NodeQueue* next;
};

struct Queue 
{
    NodeQueue* front;
    NodeQueue* rear;
};

void initQueue(Queue &q) 
{
    q.front = q.rear = NULL;
}

bool isEmptyQueue(Queue q) 
{
    return q.front == NULL;
}

void enqueue(Queue &q, SinhVien x) 
{
    NodeQueue* p = new NodeQueue;
    p->data = x;
    p->next = NULL;

    if (isEmptyQueue(q)) 
    {
        q.front = q.rear = p;
    } 
    else 
    {
        q.rear->next = p;
        q.rear = p;
    }
}

SinhVien dequeue(Queue &q) 
{
    if (isEmptyQueue(q)) 
    {
        cout << "Queue rong!\n";
        return SinhVien();
    }

    NodeQueue* p = q.front;
    SinhVien x = p->data;

    q.front = p->next;
    if (q.front == NULL) q.rear = NULL;

    delete p;
    return x;
}

void printQueue(Queue q) 
{
    NodeQueue* p = q.front;
    cout << "\n=== Sinh vien cho dong hoc phi ===\n";
    while (p != NULL) 
    {
        inSinhVien(p->data);
        p = p->next;
    }
}


   //MAIN TEST


int main() 
{
    Stack st;
    Queue q;

    initStack(st);
    initQueue(q);

    // TEST Queue (SinhVien)
    SinhVien sv1 = {"SV01", "Tung"};
    SinhVien sv2 = {"SV02", "Nam"};

    enqueue(q, sv1);
    enqueue(q, sv2);

    printQueue(q);

    cout << "\nXu ly 1 sinh vien:\n";
    SinhVien sv = dequeue(q);
    inSinhVien(sv);

    printQueue(q);

    // TEST Stack (HoaDon)
    HoaDon hd1 = {"HD01", 1000};
    HoaDon hd2 = {"HD02", 2000};

    push(st, hd1);
    push(st, hd2);

    printStack(st);

    cout << "\nPop 1 hoa don:\n";
    HoaDon hd = pop(st);
    inHoaDon(hd);

    printStack(st);

    return 0;
}