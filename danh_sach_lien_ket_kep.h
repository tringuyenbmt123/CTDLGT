#pragma once
#include "struct_sinh_vien.h"

typedef struct node
{
    SV data;
    node *pNext;
    node *pPrev;
} NODE;
typedef NODE *pNODE;

typedef struct listKep
{
    pNODE pHead;
    pNODE pTail;
} LIST_KEP;

// ---------------------------------  tu them
void khoiTaoDSLKKep(LIST_KEP &listKep)
{
    listKep.pHead = NULL;
    listKep.pTail = NULL;
}
