#pragma once
#include "struct_sinh_vien.h"
typedef struct node
{
    SV data;
    node *pNext;
} NODE;

typedef NODE *pNODE;

typedef struct listDon
{
    pNODE pHead;
} LIST_DON;

// ---------------------------------  tu them

void khoitaoDSLKDon(LIST_DON &listDon)
{
    listDon.pHead = NULL;
}
