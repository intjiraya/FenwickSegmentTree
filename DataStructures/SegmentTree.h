#ifndef SEGMENTTREE
#define SEGMENTTREE

#include <stdio.h>

typedef struct
{
	size_t SourceLen;
	size_t Len;

	int* internalArray;
} SegmentTree;

SegmentTree* SegmentTree_New(int* source, size_t len);

int SegmentTree_Query(int* source, int l, int r);

#endif