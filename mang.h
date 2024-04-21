#pragma once

#include "nhapXuatSinhVien.h"
#include "structSinhVien.h"
#define max 100

SV LIST_MANG[max];

void themSinhVienMang(SV a[], int &soLuongSinhVienMang)
{

    nhapThongTinSinhVien(a[soLuongSinhVienMang]);
    soLuongSinhVienMang++;
}

void xuatSinhVienMang(SV LIST_MANG[], int &soLuongSinhVienMang, int index)
{
    for (int i = 0; i < soLuongSinhVienMang; i++)
    {
        xuat(LIST_MANG[i], index++);
        cout << endl;
    }
}