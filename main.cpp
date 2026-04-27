#include <iostream>
#include "DSLK_Don.h"
#include "DSLK_Doi.h"
#include "Stack.h"
#include "Queue.h"
#include "SinhVien.h"
#include "HoaDon.h"

using namespace std;

int main() {
    DSLK_Don dsSV;
    DSLK_Doi dsHD;
    Stack st;
    Queue q;

    dsSV.init();
    dsHD.init();
    st.init();
    q.init();

    int choice;

    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. In danh sach sinh vien\n";
        cout << "3. Xoa sinh vien theo ma\n";
        cout << "4. Tim sinh vien theo ten\n";
        cout << "5. Sap xep theo hoc phi\n";
        cout << "6. Luu file sinh vien\n";
        cout << "7. Doc file sinh vien\n";

        cout << "8. Nhap hoa don\n";
        cout << "9. In danh sach hoa don\n";
        cout << "10. Xoa hoa don\n";

        cout << "11. Push hoa don (Stack)\n";
        cout << "12. Pop hoa don (Stack)\n";
        cout << "13. In Stack\n";

        cout << "14. Enqueue sinh vien (Queue)\n";
        cout << "15. Dequeue sinh vien (Queue)\n";
        cout << "16. In Queue\n";

        cout << "0. Thoat\n";
        cout << "========================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {

        case 1:
            dsSV.nhapDanhSach();
            break;

        case 2:
            dsSV.inDanhSach();
            break;

        case 3: {
            string ma;
            cout << "Nhap ma SV can xoa: ";
            getline(cin, ma);
            dsSV.xoaTheoMa(ma);
            break;
        }

        case 4: {
            string ten;
            cout << "Nhap ten SV: ";
            getline(cin, ten);
            NodeSinhVien* kq = dsSV.timTheoTen(ten);
            if (kq != nullptr)
                inSinhVien(kq->data);
            else
                cout << "Khong tim thay!\n";
            break;
        }

        case 5:
            dsSV.sapXepTheoHocPhi();
            break;

        case 6:
            dsSV.luuFile("sinhvien.txt");
            break;

        case 7:
            dsSV.docFile("sinhvien.txt");
            break;

        case 8: {
            HoaDon hd = nhapHoaDon();
            dsHD.themCuoi(hd);
            break;
        }

        case 9:
            dsHD.inDanhSach();
            break;

        case 10: {
            string ma;
            cout << "Nhap ma hoa don: ";
            getline(cin, ma);
            dsHD.xoaNode(ma);
            break;
        }

        case 11: {
            HoaDon hd = nhapHoaDon();
            st.push(hd);
            break;
        }

        case 12: {
            HoaDon hd = st.pop();
            inHoaDon(hd);
            break;
        }

        case 13:
            st.inStack();
            break;

        case 14: {
            SinhVien sv = nhapSinhVien();
            q.enqueue(sv);
            break;
        }

        case 15: {
            SinhVien sv = q.dequeue();
            inSinhVien(sv);
            break;
        }

        case 16:
            q.inQueue();
            break;

        case 0:
            cout << "Thoat chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}