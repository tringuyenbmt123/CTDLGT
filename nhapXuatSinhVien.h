#pragma once

#include "structSinhVien.h"
#include <string.h>

void nhapThongTinSinhVien(SV &sv)
{
    
    /*cin.ignore();*/ // CHỖ NÀY IGNORE Ở SAU KHI NHẬP SỐ
    cout << "\n\t- Nhap ma SV: ";
    getline(cin, sv.maSV);

    cout << "\n\t- Nhap ho SV: ";
    getline(cin, sv.ho);

    cout << "\n\t- Nhap ten SV: ";
    getline(cin, sv.ten);


    cout << "\n\t- Nhap lop cua SV: ";
    getline(cin, sv.lop);

    cout << "\n\t- Nhap diem sinh cua SV: ";
    cin >> sv.diem;
    cin.ignore();
}

// Hàm in tiêu đề
void inTieuDe()
{
    cout << setw(20) << left << "Ma SV";
    cout << setw(20) << left << "| Ho";
    cout << setw(20) << left << "| Ten";
    cout << setw(20) << left << "| Lop";
    cout << setw(10) << left << "| Diem" << endl;
    cout << setfill('-');
    cout << setw(100) << "-" << endl;
}

void xuat(SV sv, int index)
{
    if (index == 0)
    {
        inTieuDe();
    }
    cout << setfill(' ');
    cout << setw(22) << left << sv.maSV;
    cout << setw(22) << left << sv.ho;
    cout << setw(20) << left << sv.ten;
    cout << setw(20) << left << sv.lop;
    cout << setw(10) << left << sv.diem << endl;
}


