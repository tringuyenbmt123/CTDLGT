#pragma once


#include <iostream>
#include <string>
#include<iomanip>
#include <stdexcept> // thư viện dùng cho template
#include<windows.h>
#include<algorithm>
#include <time.h>
#include <chrono>

using namespace std;
enum class Field { MaSV, Ho, Ten, Lop, Diem };

typedef struct sinhVien
{
    string ho;
    string ten;
    string maSV;
    float diem;
    string lop;
} SINHVIEN;

typedef SINHVIEN SV;

