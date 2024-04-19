#include "danh_sach_lien_ket_don.h"
#include "danh_sach_lien_ket_kep.h"
#include "danh_sach_lien_ket_vong.h"
#include "mang.h"
#include "nhapXuatSinhVien.h"

// anh tris check push lene nhen
// ------------------------------ tu them---------------------------
pNODE_DON khoiTaoNodeDon(SV sv) // ----------- ĐƠN
{
    pNODE_DON p = new NODE_DON;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext = NULL;

    return p;
}

pNODE_KEP khoiTaoNodeKep(SV sv) // ------------ kép
{
    pNODE_KEP p = new NODE_KEP;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext = NULL;
    p->pPrev = NULL;

    return p;
}

pNODE_VONG khoiTaoNodeVong(SV sv) // ----------- vòng
{
    pNODE_VONG p = new NODE_VONG;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext = NULL;

    return p;
}

// ---------------------------- CODE CHÍNH ------------------------------

// sắp xếp

// Hàm tìm kiếm nhị phân
// ---- > mảng :

template <typename T>
T getValue(const SV &sv, const string &field)
{
    if (field == "maSV")
        return sv.maSV;
    if (field == "ho")
        return sv.ho;
    if (field == "ten")
        return sv.ten;
    if (field == "lop")
        return sv.lop;
    if (field == "diem")
        return sv.diem;
    throw invalid_argument("Field name is invalid");
}

template <typename T>
int Binary_Search(SV listMang[], int left, int right, const T &x, const string &input)
{
    if (left > right)
    {
        return -1;
    }
    int mid = (left + right) / 2;
    T midValue = getValue<T>(listMang[mid], input);

    if (midValue == x)
    {
        return mid;
    }
    else if (midValue < x)
    {
        return Binary_Search(listMang, mid + 1, right, x, input);
    }
    else
    {
        return Binary_Search(listMang, left, mid - 1, x, input);
    }
}

// Hàm cho người dùng chọn muốn đảo ngược tên
void chonDaoNguocTen(void *list, const char *type)
{
    int lc = 0;
    cout << "\n\t======================= ";
    cout << "\n\t -- Bạn có muốn đảo ngược tên các sinh viên vừa tìm được không ? ";
    cout << "\n\t 1. Có.";
    cout << "\n\t 2. Không.";
    cout << "\n\t======================= ";
    cout << "\n\n\t - Nhap lua chon: ";
    cin >> lc;

    switch (lc)
    {
    case 1:
        xuatDanhSachVoiDaoNguocTen(list, type, 0, 0);
        break;
    case 2:
        xuatDanhSach(list, type, 0, 0);
        break;
    default:
        break;
    }
}

void timKiemSinhVienMang(SV LIST_MANG[]) //  ---------- MẠNG
{
    int soLuongSinhVien = sizeof(LIST_MANG) / sizeof(LIST_MANG[0]);
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
            // tìm
            int result_str = Binary_Search<string>(LIST_MANG, 0, soLuongSinhVien - 1, mssvCanTim, "maSV");
            if (result_str != -1)
            {
                chonDaoNguocTen(LIST_MANG, "mang");
            }
            else
            {
                cout << "Not found" << endl;
            }
            break;
        }

        case 2:
        {
            cin.ignore();
            cout << "\n\tNhap ho sinh vien can tim : ";
            string hoCanTim = "";
            getline(cin, hoCanTim);
            // tìm
            int result_str = Binary_Search<string>(LIST_MANG, 0, soLuongSinhVien - 1, hoCanTim, "ho");
            if (result_str != -1)
            {
                chonDaoNguocTen(LIST_MANG, "mang");
            }
            else
            {
                cout << "Not found" << endl;
            }
            break;
        }

        case 3:
        {
            cin.ignore();
            cout << "\n\tNhap ten sinh vien can tim : ";
            string tenCanTim = "";
            getline(cin, tenCanTim);
            // tìm
            int result_str = Binary_Search<string>(LIST_MANG, 0, soLuongSinhVien - 1, tenCanTim, "ten");
            if (result_str != -1)
            {
                chonDaoNguocTen(LIST_MANG, "mang");
            }
            else
            {
                cout << "Not found" << endl;
            }
            break;
        }

        case 4:
        {
            cin.ignore();
            cout << "\n\tNhap lop sinh vien can tim : ";
            string lopCanTim = "";
            getline(cin, lopCanTim);
            // tìm
            int result_str = Binary_Search<string>(LIST_MANG, 0, soLuongSinhVien - 1, lopCanTim, "lop");
            if (result_str != -1)
            {
                chonDaoNguocTen(LIST_MANG, "mang");
            }
            else
            {
                cout << "Not found" << endl;
            }
            break;
        }

        case 5:
        {
            cout << "\n\tNhap diem sinh vien can tim : ";
            float diemCanTim;
            cin >> diemCanTim;
            // tìm
            int result_str = Binary_Search<float>(LIST_MANG, 0, soLuongSinhVien - 1, diemCanTim, "diem");
            if (result_str != -1)
            {
                chonDaoNguocTen(LIST_MANG, "mang");
            }
            else
            {
                cout << "Not found" << endl;
            }
            break;
        }

        default:
            break;
        }
        system("pause");
    }
}

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
void themVaoCuoiDSLKDon(LIST_DON &listDon, pNODE_DON p)
{
    if (listDon.pHead == NULL)
    {
        listDon.pHead = p;
    }
    else
    {
        pNODE_DON temp = listDon.pHead;
        while (temp->pNext != NULL)
        {
            temp = temp->pNext;
        }
        temp->pNext = p;
    }
}

// Hàm thêm vào cuối DSLK Vòng
void themVaoCuoiDSLKVong(LIST_VONG &listVong, pNODE_VONG p)
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
void themVaoCuoiDSLKKep(LIST_KEP &listKep, pNODE_KEP p)
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
    pNODE_DON p = khoiTaoNodeDon(sv);
    themVaoCuoiDSLKDon(listDon, p);
}

void themSinhVienDSLKVong(LIST_VONG &listVong)
{
    cout << "- Them sinh vien tiep theo: ";
    SV sv = nhapThongTinSinhVien();
    pNODE_VONG p = khoiTaoNodeVong(sv);
    themVaoCuoiDSLKVong(listVong, p);
}

void themSinhVienDSLKKep(LIST_KEP &listKep)
{
    cout << "- Them sinh vien tiep theo: ";
    SV sv = nhapThongTinSinhVien();
    pNODE_KEP p = khoiTaoNodeKep(sv);
    themVaoCuoiDSLKKep(listKep, p);
}

void themSinhVienVaoMang(SV LIST_MANG[], int &soSinhVien, SV &sv)
{
    cout << "- Them sinh vien tiep theo: ";
    SV sv = nhapThongTinSinhVien();
    LIST_MANG[soSinhVien++] = sv;
}

int main()
{

    return 0;
}

// Comand nday