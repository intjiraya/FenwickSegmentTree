#ifndef SEGMENTTREE
#define SEGMENTTREE

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	size_t SourceLen;
	size_t Len;

	int* internalArray;
} SegmentTree;

SegmentTree* SegmentTree_New(int* source, size_t len);

int SegmentTree_Query(SegmentTree* source, int l, int r);

void SegmentTree_Update(SegmentTree* source, int idx, int value);

#endif