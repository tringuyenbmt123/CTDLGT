#pragma once
#include "struct_sinh_vien.h"

typedef struct node
{
    SV data;
    node *pNext;
} NODE;
typedef NODE *pNODE;

typedef struct listVong
{
    pNODE pTail; // Con tro pTail tham chiếu đến phần tử cuối cùng của danh sách
} LIST_VONG;

// ----------------- tu them
void khoiTaoDSLK(LIST_VONG &listVong)
{
    listVong.pTail = NULL; // Khởi tạo pTail là NULL khi danh sách rỗng
}
