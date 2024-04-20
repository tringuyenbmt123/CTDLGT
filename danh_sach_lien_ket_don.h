#pragma once
#include "struct_sinh_vien.h"
typedef struct node_Don
{
    SV data;
    node_Don*pNext_Don;
} NODE_DON;

typedef NODE_DON *pNODE_DON;

typedef struct listDon
{
    pNODE_DON pHead_Don;
} LIST_DON;

// ---------------------------------  tu them

void khoitaoDSLKDon(LIST_DON &listDon)
{
    listDon.pHead_Don = NULL;
}
