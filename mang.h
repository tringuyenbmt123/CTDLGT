#pragma once


#include "nhapXuatSinhVien.h"


void themSinhVienMang(SV a[], int &soLuongSinhVienMang)
{

	nhapThongTinSinhVien(a[soLuongSinhVienMang]);
    soLuongSinhVienMang++;
}

void xuatSinhVienMang(SV a[], int &soLuongSinhVienMang)
{
    for(int i=0;i<soLuongSinhVienMang;i++)
    {
        xuatThongTinSinhVien(a[i]) ;
        cout << endl;
    }
}