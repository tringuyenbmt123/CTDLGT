#pragma once

#include "structSinhVien.h"
#include <string.h>
#include <algorithm>
#include "danh_sach_lien_ket_don.h"

SV nhapThongTinSinhVien()
{
    SV sv;
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

    return sv;
}


// Hàm in tiêu đề
void inTieuDe()
{
    cout << setw(20) << left << "Ma SV";
    cout << setw(30) << left << "| Ho va Ten";
    cout << setw(20) << left << "| Lop";
    cout << setw(10) << left << "| Diem" << endl;
    cout << setfill('-');
    cout << setw(90) << "-" << endl;
}

void xuat(SV sv)
{
    cout << setfill(' ');
    cout << setw(22) << left << sv.maSV;
    cout << setw(0) << left << sv.ho << " " << sv.ten;
    cout << setw(25) << left << " ";
    cout << setw(25) << left << sv.lop;
    cout << setw(10) << left << sv.diem << endl;
}

void themSinhVienMang(SV sv[], int& soLuongSinhVienMang)
{

    sv[soLuongSinhVienMang] = nhapThongTinSinhVien();
    soLuongSinhVienMang++;
}


void xuatSinhVienMang(SV LIST_MANG[], int& soLuongSinhVienMang, int index)
{
    for (int i = 0; i < soLuongSinhVienMang; i++)
    {
        xuat(LIST_MANG[i]);
        cout << endl;
    }
}

void xuatDSLKDon(LIST_DON listDon)
{
    int index = 0;
    for (pNODE_DON p = listDon.pHead_Don; p != NULL; p = p->pNext_Don)
    {
        xuat(p->data);
    }
}