#include "FenwickTree.h"

FenwickTree* Fenwick_New(int* source, size_t len)
{
	FenwickTree* newTree = (FenwickTree*)calloc(1, sizeof(FenwickTree));

	newTree->Len = len;
	newTree->internalArr = calloc(len + 1, sizeof(int));

	for (int i = 0; i < len; i++)
		newTree->internalArr[i+1] = source[i];

	for (int j = 1; j <= len; j++)
	{
		int targetIndex = j + (j & -j);

		if (targetIndex <= len)
			newTree->internalArr[targetIndex] += newTree->internalArr[j];
	}

	return newTree;
}

void Fenwick_Add(FenwickTree* source, int index, int value)
{
	while (index <= source->Len)
	{
		source->internalArr[index] += value;
		
		index = index + (index & -index);
	}
}

int Fenwick_GetRangeSum(FenwickTree* source, int l, int r)
{
	r = r + 1;

	int prefixSumL = 0;
	while (l > 0)
	{
		prefixSumL += source->internalArr[l];

		l -= (l & -l);
	}

	int prefixSumR = 0;
	while (r > 0)
	{
		prefixSumR += source->internalArr[r];

		r -= (r & -r);
	}

	return prefixSumR - prefixSumL;
}