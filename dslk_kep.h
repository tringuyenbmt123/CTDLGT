#pragma once
#include "structSinhVien.h"

typedef struct node_Kep
{
    SV data;
    node_Kep *pNext_Kep;
    node_Kep *pPrev_Kep;
} NODE_KEP;
typedef NODE_KEP *pNODE_KEP;

typedef struct listKep
{
    pNODE_KEP pHead_Kep;
    pNODE_KEP pTail_Kep;
} LIST_KEP;

// ---------------------------------  tu them
void khoiTaoDSLKKep(LIST_KEP &listKep)
{
    listKep.pHead_Kep = NULL;
    listKep.pTail_Kep = NULL;
}