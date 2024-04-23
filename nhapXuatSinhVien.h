#pragma once

#include "structSinhVien.h"
#include <string.h>
#include <algorithm>
#include "danh_sach_lien_ket_don.h"

SV nhapThongTinSinhVien()
{
    SV sv;
    cin.ignore(); // CHỖ NÀY IGNORE Ở SAU KHI NHẬP SỐ

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
    cout << left << setw(30) << "| MSSV" << setw(30) << "| Ho va Ten" << setw(20) << "| Lop" << setw(10) << "| Diem" << endl;
    cout << setfill('-') << setw(90) << "" << setfill(' ') << endl;
}

void xuat(SV sv)
{
    cout << left << setw(32) << sv.maSV << setw(30) << sv.ho + " " + sv.ten << setw(20) << sv.lop << setw(10) << sv.diem << endl;
}

void themSinhVienMang(SV sv[], int &soLuongSinhVienMang, int index)
{

    SV x = nhapThongTinSinhVien();
    if (index >= 0 && index <= soLuongSinhVienMang)
    {
        for (int i = soLuongSinhVienMang; i > index; i--)
            sv[i] = sv[i - 1];
        sv[index] = x;
        soLuongSinhVienMang++;
    }
}

void xuatSinhVienMang(SV LIST_MANG[], int &soLuongSinhVienMang, int index)
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