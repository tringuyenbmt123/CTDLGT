#pragma once
#include "struct_sinh_vien.h"

SV nhapThongTinSinhVien()
{
    SV sv;
    /*cin.ignore();*/ // CHỖ NÀY IGNORE Ở SAU KHI NHẬP SỐ
    cout << "\n\t- Nhap ho ten SV: ";
    getline(cin, sv.hoTen);

    cout << "\t- Nhap ma SV: ";
    getline(cin, sv.maSV);

    cout << "\t- Nhap lop cua SV: ";
    getline(cin, sv.lop);

    cout << "\t- Nhap nam sinh cua SV: ";
    getline(cin, sv.namSinh);

    return sv;
}

void xuat(SV sv, int index)
{
    if (index == 0)
    {
        // In tieu de
        cout << setw(20) << left << "Ho va ten";
        cout << setw(20) << left << "| Ma SV";
        cout << setw(20) << left << "| Lop";
        cout << setw(10) << left << "| Nam sinh" << endl;
        cout << setfill('-');
        cout << setw(80) << "-" << endl;
    }
    cout << setfill(' ');
    cout << setw(25) << left << sv.hoTen;
    cout << setw(20) << left << sv.maSV;
    cout << setw(25) << left << sv.lop;
    cout << setw(10) << left << sv.namSinh << endl;
}