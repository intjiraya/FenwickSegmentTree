#ifndef FENWICKTREE
#define FENWICKTREE

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	size_t Len;
	int* internalArr;
} FenwickTree;

FenwickTree* Fenwick_New(int* arr, size_t len);

void Fenwick_Add(FenwickTree* source, int index, int value);

int Fenwick_GetRangeSum(FenwickTree* source, int l, int r);

#endif 