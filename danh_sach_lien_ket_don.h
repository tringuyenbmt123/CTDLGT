#pragma once
#include "struct_sinh_vien.h"
typedef struct node
{
    SV data;
    node *pNext;
} NODE_DON;

typedef NODE_DON *pNODE_DON;

typedef struct listDon
{
    pNODE_DON pHead;
} LIST_DON;

// ---------------------------------  tu them

void khoitaoDSLKDon(LIST_DON &listDon)
{
    listDon.pHead = NULL;
}
