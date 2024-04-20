#include "danh_sach_lien_ket_don.h"
#include "danh_sach_lien_ket_kep.h"
#include "danh_sach_lien_ket_vong.h"
#include "mang.h"
#include "nhapXuatSinhVien.h"
#define max 10000
SV LIST_MANG[max]; // THAY DOI LIST -> LIST_MANG
// ------------------------------ tu them---------------------------
pNODE_DON khoiTaoNodeDon(SV sv) // ----------- ĐƠN
{
    pNODE_DON p = new NODE_DON;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext_Don = NULL;

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
    p->pNext_Kep = NULL;
    p->pPrev_Kep = NULL;

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
    p->pNext_Vong = NULL;

    return p;
}

// ------------------------------------
enum class Field
{
    MaSV,
    Ho,
    Ten,
    Lop,
    Diem
};
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
    //    if (field == "diem")
    //        return sv.diem;
    throw invalid_argument("Field name is invalid");
}

string getValue(const SV &sv, const string &field)
{
    if (field == "maSV")
        return sv.maSV;
    if (field == "ho")
        return sv.ho;
    if (field == "ten")
        return sv.ten;
    if (field == "lop")
        return sv.lop;
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
    string midValue = getValue(listMang[mid], input);

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
//----------------
void timKiemSinhVienMang(SV LIST_MANG[], int soLuongSinhVien) //  ---------- MẠNG
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

            
            int result_str = Binary_Search<string>(LIST_MANG, 0, soLuongSinhVien - 1, mssvCanTim, "maSV");
            if (result_str != -1)
            {
                xuatThongTinSinhVien(LIST_MANG[result_str]);
                system("pause");
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
            int result_str = Binary_Search<string>(LIST_MANG, 0, soLuongSinhVien - 1, hoCanTim, "ho");
            if (result_str != -1)
            {
                xuatThongTinSinhVien(LIST_MANG[result_str]);
                system("pause");
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

            break;
        }

        case 4:
        {
            cin.ignore();
            cout << "\n\tNhap lop sinh vien can tim : ";
            string lopCanTim = "";
            getline(cin, lopCanTim);
            // tìm

            break;
        }

        case 5:
        {
            // cout << "\n\tNhap diem sinh vien can tim : ";
            // float diemCanTim;
            // cin >> diemCanTim;
            //// tìm
            // int result_str = Binary_Search<float>(LIST_MANG, 0, soLuongSinhVien - 1, diemCanTim, "diem");
            // if (result_str != -1)
            //{
            //    // chonDaoNguocTen(LIST_MANG, "mang");
            // }
            // else
            //{
            //     cout << "Not found" << endl;
            // }
            // break;
        }

        default:
            break;
        }
        system("pause");
    }
}

int main()
{
    // test chuong trinh
    SV listMang[7] = {{"123", "Hung", "An", "12A", 8.5},
                      {"456", "Le", "Binh", "12B", 7.0},
                      {"111", "Nguyen", "Binh", "19B", 9.0},
                      {"222", "Tinh", "Binh", "18B", 8.0},
                      {"333", "La", "Binh", "15B", 7.0},
                      {"444", "Tinh", "Binh", "13B", 5.0},
                      {"789", "Nguyen", "Cuong", "11C", 8.1}};

    timKiemSinhVienMang(listMang, 7);
    return 0;
}

// Comand nday
