#pragma once
#include "struct_sinh_vien.h"

typedef struct node
{
    SV data;
    node *pNext;
    node *pPrev;
} NODE_KEP;
typedef NODE_KEP *pNODE_KEP;

typedef struct listKep
{
    pNODE_KEP pHead;
    pNODE_KEP pTail;
} LIST_KEP;

// ---------------------------------  tu them
void khoiTaoDSLKKep(LIST_KEP &listKep)
{
    listKep.pHead = NULL;
    listKep.pTail = NULL;
}
