#include "danh_sach_lien_ket_don.h"
#include "danh_sach_lien_ket_kep.h"
#include "danh_sach_lien_ket_vong.h"
#include "mang.h"
#include "nhapXuatSinhVien.h"


// anh tris check push lene nhen
// ------------------------------ tu them---------------------------
pNODE khoiTaoNodeDon(SV sv) // ----------- ĐƠN
{
    pNODE p = new NODE;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext = NULL;

    return p;
}

pNODE khoiTaoNodeKep(SV sv) // ------------ kép
{
    pNODE p = new NODE;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext = NULL;
    p->pPrev = NULL;

    return p;
}

// ---------------------------- CODE CHÍNH ------------------------------

// có thể sắp xếp rồi tìm

void timKiemSinhVienDanhSachLkDon(LIST_DON listDon) //  ---------- ĐƠN
{
    int lc;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=== CHUONG TRINH TIM KIEM SINH VIEN ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t  1. Tim theo ma sinh vien.";
        cout << "\n\t  2. Tim theo ho.";
        cout << "\n\t  3. Tim theo ten.";
        cout << "\n\t  4. Tim theo lop.";
        cout << "\n\t  5. Tim theo diem.";

        cout << "\n\t======================= END =======================";
        cout << "\n\n\t - Nhap lua chon: ";
        cin >> lc;

        switch (lc)
        {
        case 1:
        {
            cin.ignore();
            cout << "\n\tNhap ma sinh vien can tim : ";
            string mssvCanTim = "";
            getline(cin, mssvCanTim);
            break;
        }

        case 2:
        {
            cin.ignore();
            cout << "\n\tNhap ho sinh vien can tim : ";
            string hoCanTim = "";
            getline(cin, hoCanTim);
            break;
        }

        case 3:
        {
            cin.ignore();
            cout << "\n\tNhap ten sinh vien can tim : ";
            string tenCanTim = "";
            getline(cin, tenCanTim);
            break;
        }

        case 4:
        {
            cin.ignore();
            cout << "\n\tNhap lop sinh vien can tim : ";
            string lopCanTim = "";
            getline(cin, lopCanTim);
            break;
        }

        case 5:
        {
            cout << "\n\tNhap diem sinh vien can tim : ";
            float diemCanTim;
            cin >> diemCanTim;
            break;
        }

        default:
            break;
        }
        system("pause");
    }
}

void timKiemSinhVienDanhSachLkVong(LIST_VONG listVong) // --------- VÒNG
{
    int lc;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=== CHUONG TRINH TIM KIEM SINH VIEN ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t  1. Tim theo ma sinh vien.";
        cout << "\n\t  2. Tim theo ho.";
        cout << "\n\t  3. Tim theo ten.";
        cout << "\n\t  4. Tim theo lop.";
        cout << "\n\t  5. Tim theo diem.";

        cout << "\n\t======================= END =======================";
        cout << "\n\n\t - Nhap lua chon: ";
        cin >> lc;

        switch (lc)
        {
        case 1:
        {
            cin.ignore();
            cout << "\n\tNhap ma sinh vien can tim : ";
            string mssvCanTim = "";
            getline(cin, mssvCanTim);
            break;
        }

        case 2:
        {
            cin.ignore();
            cout << "\n\tNhap ho sinh vien can tim : ";
            string hoCanTim = "";
            getline(cin, hoCanTim);
            break;
        }

        case 3:
        {
            cin.ignore();
            cout << "\n\tNhap ten sinh vien can tim : ";
            string tenCanTim = "";
            getline(cin, tenCanTim);
            break;
        }

        case 4:
        {
            cin.ignore();
            cout << "\n\tNhap lop sinh vien can tim : ";
            string lopCanTim = "";
            getline(cin, lopCanTim);
            break;
        }

        case 5:
        {
            cout << "\n\tNhap diem sinh vien can tim : ";
            float diemCanTim;
            cin >> diemCanTim;
            break;
        }

        default:
            break;
        }
        system("pause");
    }
}

// Hàm thêm vào cuối DSLK Dơn
void themVaoCuoiDSLKDon(LIST_DON &listDon, pNODE p)
{
    if (listDon.pHead == NULL)
    {
        listDon.pHead = p;
    }
    else
    {
        pNODE temp = listDon.pHead;
        while (temp->pNext != NULL)
        {
            temp = temp->pNext;
        }
        temp->pNext = p;
    }
}

// Hàm thêm vào cuối DSLK Vòng
void themVaoCuoiDSLKVong(LIST_VONG &listVong, pNODE p)
{
    // Danh sach rong
    if (listVong.pTail == NULL)
    {
        listVong.pTail = p;
        p->pNext = p; // Khi danh sách rỗng, pNext của phần tử đầu tiên trỏ lại chính nó
    }
    else
    {
        p->pNext = listVong.pTail->pNext; // Liên kết phần tử mới với phần tử đầu tiên
        listVong.pTail->pNext = p;        // Liên kết phần tử cuối cùng với phần tử mới
        listVong.pTail = p;               // Cập nhật pTail để trỏ đến phần tử mới
    }
}

// Hàm thêm vào cuối DSLK kép
void themVaoCuoiDSLKKep(LIST_KEP &listKep, pNODE p)
{
    // Danh sach rong
    if (listKep.pHead == NULL)
    {
        listKep.pHead = listKep.pTail = p;
    }
    else
    {
        listKep.pTail->pNext = p;
        p->pPrev = listKep.pTail;
        listKep.pTail = p;
    }
}

void themSinhVienDSLKDon(LIST_DON &listDon)
{
    cout << "- Them sinh vien tiep theo: ";
    SV sv = nhapThongTinSinhVien();
    pNODE p = khoiTaoNodeDon(sv);
    themVaoCuoiDSLKDon(listDon, p);
}

void themSinhVienDSLKVong(LIST_VONG &listVong)
{
    cout << "- Them sinh vien tiep theo: ";
    SV sv = nhapThongTinSinhVien();
    pNODE p = khoiTaoNodeDon(sv); // CHỖ NÀY KHOI TAO NODE DON = KEP
    themVaoCuoiDSLKVong(listVong, p);
}

void themSinhVienDSLKKep(LIST_KEP &listKep)
{
    cout << "- Them sinh vien tiep theo: ";
    SV sv = nhapThongTinSinhVien();
    pNODE p = khoiTaoNodeKep(sv);
    themVaoCuoiDSLKKep(listKep, p);
}

void themSinhVienVaoMang(SV LIST_MANG[], int &soSinhVien, SV &sv)
{
    cout << "- Them sinh vien tiep theo: ";
    SV sv = nhapThongTinSinhVien();
    LIST[soSinhVien++] = sv;
}

int main()
{


    return 0;
}


/// ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc