#include "SegmentTree.h"

void BuildTreeInternal(int* source, int* internalArr, int node, int l, int r)
{
	if (l == r)
	{
		internalArr[node] = source[l];

		return;
	}

	int midPoint = (l + r) / 2;
	BuildTreeInternal(source, internalArr, node*2, l, midPoint);
	BuildTreeInternal(source, internalArr, node*2+1, midPoint + 1, r);

	internalArr[node] = internalArr[node*2] + internalArr[node*2+1];
}

void UpdateNodeInternal(SegmentTree* source, int node, int tl, int tr, int idx, int delta)
{
	if (tl == tr)
	{
		source->internalArray[node] += delta;

		return;
	}

	int mid = (tl + tr) / 2;
	
	if (idx <= mid)
		UpdateNodeInternal(source, node * 2, tl, mid, idx, delta);
	else
		UpdateNodeInternal(source, node * 2 + 1, mid + 1, tr, idx, delta);

	source->internalArray[node] = source->internalArray[node * 2] + source->internalArray[node * 2 + 1];
}

int RangeQueryInternal(SegmentTree* source, int node, int tl, int tr, int l, int r)
{
	if (r < tl || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return source->internalArray[node];

	int tm = (tl + tr) / 2;
	int left = RangeQueryInternal(source, node * 2, tl, tm, l, r);
	int right = RangeQueryInternal(source, node * 2 + 1, tm + 1, tr, l, r);

	return left + right;
}

SegmentTree* SegmentTree_New(int* source, size_t len)
{
	SegmentTree* newTree = calloc(1, sizeof(SegmentTree));

	newTree->SourceLen = len;
	newTree->Len = len*4;
	newTree->internalArray = calloc(len*4, sizeof(int));

	BuildTreeInternal(source, newTree->internalArray, 1, 0, len-1);

	return newTree;
}

int SegmentTree_Query(SegmentTree* source, int l, int r)
{
	return RangeQueryInternal(source, 1, 0, source->SourceLen - 1, l, r);
}

void SegmentTree_Update(SegmentTree* source, int idx, int value)
{
	UpdateNodeInternal(source, 1, 0, source->SourceLen - 1, idx, value);
}