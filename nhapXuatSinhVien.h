#include "struct_sinh_vien.h"
#ifndef NHAP_XUAT_SINH_VIEN_H
#define NHAP_XUAT_SINH_VIEN_H


void  nhapThongTinSinhVien(SV &sv)
{
   
   
    cout << "\nNhap ma sinh vien: ";
    getline(cin, sv.maSV);
    cout << "Nhap ho: ";
    getline(cin, sv.ho);
    cout << "Nhap ten SV: ";
    getline(cin, sv.ten);
    cout << "Nhap lop cua SV: ";
    getline(cin, sv.lop);
    cout << "Nhap diem sinh cua SV: ";
    cin >> sv.diem;
    cin.ignore();  // Clear the input buffer after reading a float
}

void xuatThongTinSinhVien(const SV &sv) {
    cout << sv.maSV << " " << sv.ho << " " << sv.ten << " " << sv.lop << " " << sv.diem << endl;
}
#endif // NHAP_XUAT_SINH_VIEN_H


