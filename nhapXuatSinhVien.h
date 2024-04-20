#pragma once

#include "struct_sinh_vien.h"
#include <string.h>

SV nhapThongTinSinhVien()
{
    SV sv;
    /*cin.ignore();*/ // CHỖ NÀY IGNORE Ở SAU KHI NHẬP SỐ
    cout << "\n\t- Nhap ho SV: ";
    getline(cin, sv.ho);

    cout << "\n\t- Nhap ten SV: ";
    getline(cin, sv.ten);

    cout << "\n\t- Nhap ma SV: ";
    getline(cin, sv.maSV);

    cout << "\n\t- Nhap lop cua SV: ";
    getline(cin, sv.lop);

    cout << "\n\t- Nhap diem sinh cua SV: ";
    cin >> sv.diem;

    return sv;
}

// Hàm in tiêu đề
void inTieuDe()
{
    cout << setw(20) << left << "Ho";
    cout << setw(20) << left << "| Ten";
    cout << setw(20) << left << "| Ma SV";
    cout << setw(20) << left << "| Lop";
    cout << setw(10) << left << "| Diem" << endl;
    cout << setfill('-');
    cout << setw(80) << "-" << endl;
}

void xuat(SV sv, int index)
{
    if (index == 0)
    {
        inTieuDe();
    }
    cout << setfill(' ');
    cout << setw(25) << left << sv.ho;
    cout << setw(25) << left << sv.ten;
    cout << setw(20) << left << sv.maSV;
    cout << setw(25) << left << sv.lop;
    cout << setw(10) << left << sv.diem << endl;
}

void xuatDanhSach(void *list, const char *type, int index, int soLuongSV)
{
    if (strcmp(type, "mang") == 0)
    {
        SV *sv = (SV *)list;
        for (int i = 0; i < soLuongSV; i++)
        {
            xuatDanhSach(sv[i], index++);
        }
    }
    else if (strcmp(type, "don") == 0 || strcmp(type, "vong") == 0 || strcmp(type, "kep") == 0)
    {
        if (strcmp(type, "don") == 0)
        {
            LIST_DON *donList = (LIST_DON *)list;
            for (pNODE_DON p = donList->pHead; p != NULL; p = p->pNext)
            {
                xuatDanhSach(p->data, index++);
            }
        }
        else if (strcmp(type, "vong") == 0)
        {
            LIST_KEP *kepList = (LIST_KEP *)list;
            for (pNODE_KEP p = kepList->pHead; p != NULL; p = p->pNext)
            {
                xuatDanhSach(p->data, index++);
            }
        }
        else if (strcmp(type, "kep") == 0)
        {
            LIST_VONG *vongList = (LIST_VONG *)list;
            if (vongList->pTail != NULL)
            {
                pNODE_VONG p = vongList->pTail->pNext; // Bắt đầu duyệt từ phần tử đầu tiên
                do
                {
                    xuatDanhSach(p->data, index++);
                    p = p->pNext;
                } while (p != vongList->pTail->pNext); // Duyệt từ đầu đến cuối danh sách
            }
        }

        // Sau khi xuất danh sách, cho người dùng chọn muốn đảo ngược tên hay không
        chonDaoNguocTen(list, type);
    }
    else
    {
        printf("Loai danh sach khong hop le.\n");
    }
}

// Hàm đảo ngược sting
string reverseString(string &str)
{
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

void xuatDaoNguocTen(SV sv, int index)
{
    if (index == 0)
    {inTieuDe();
    }
    cout << setfill(' ');
    cout << setw(25) << left << reverseString(sv.ten) << " " << reverseString(sv.ho);
    cout << setw(20) << left << sv.maSV;
    cout << setw(25) << left << sv.lop;
    cout << setw(10) << left << sv.diem << endl;
}

void xuatDanhSachVoiDaoNguocTen(void *list, const char *type, int index, int soLuongSV)
{
    if (strcmp(type, "mang") == 0)
    {
        SV *sv = (SV *)list;
        for (int i = 0; i < soLuongSV; i++)
        {
            xuatDaoNguocTen(sv[i], index++);
        }
    }
    else if (strcmp(type, "don") == 0 || strcmp(type, "vong") == 0 || strcmp(type, "kep") == 0)
    {
        if (strcmp(type, "don") == 0)
        {
            LIST_DON *donList = (LIST_DON *)list;
            for (pNODE_DON p = donList->pHead; p != NULL; p = p->pNext)
            {
                xuatDaoNguocTen(p->data, index++);
            }
        }
        else if (strcmp(type, "vong") == 0)
        {
            LIST_KEP *kepList = (LIST_KEP *)list;
            for (pNODE_KEP p = kepList->pHead; p != NULL; p = p->pNext)
            {
                xuatDaoNguocTen(p->data, index++);
            }
        }
        else if (strcmp(type, "kep") == 0)
        {
            LIST_VONG *vongList = (LIST_VONG *)list;
            if (vongList->pTail != NULL)
            {
                pNODE_VONG p = vongList->pTail->pNext; // Bắt đầu duyệt từ phần tử đầu tiên
                do
                {
                    xuatDaoNguocTen(p->data, index++);
                    p = p->pNext;
                } while (p != vongList->pTail->pNext); // Duyệt từ đầu đến cuối danh sách
            }
        }

        // Sau khi xuất danh sách, cho người dùng chọn muốn đảo ngược tên hay không
        chonDaoNguocTen(list, type);
    }
    else
    {
        printf("Loai danh sach khong hop le.\n");
    }
}
