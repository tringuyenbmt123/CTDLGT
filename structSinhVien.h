#pragma once

#include <iostream>
#include <string>
#include<string.h>
#include<iomanip>
#include <stdexcept> // thư viện dùng cho template
#include<windows.h>
#include<algorithm>
#include <time.h>
#include <chrono>
#include  <cctype>



using namespace std;

typedef struct sinhVien
{
    string maSV;
    string ho;
    string ten;
    string lop;
    float diem;
} SINHVIEN;

typedef SINHVIEN SV;
