#include "sort.h"

void minHeapRebuild_count(int* src, int n, int pos, int& count_compare) {
	int _pos = pos;

	while (++count_compare && 2 * _pos + 1 < n) {
		int child = 2 * _pos + 1;

		if (++count_compare && child < n - 1)
			if (++count_compare && src[child] > src[child + 1]) child += 1;
		if (++count_compare && src[_pos] > src[child]) {
			swap(src[_pos], src[child]);
			_pos = child;
		}
		else break;
	}
}
void minHeapBuild_count(int* src, int n, int& count_compare) {
	for (int i = (n - 2) / 2; ++count_compare && i >= 0; i--)
		minHeapRebuild_count(src, n, i, count_compare);
}
void heapSort_count(int* src, int n, int& count_compare) {
	int m = n;
	for (int* tmp = src; ++count_compare && tmp < src + n; tmp++)
		minHeapBuild_count(tmp, m--, count_compare);
}

void digitSort_count(int* src, int n, int exp, int& count_compare) {
	int* pos = new int[10]();
	int* dst = new int[n];

	for (int i = 0; ++count_compare && i < n; i++)
		pos[(src[i] / exp) % 10]++;
	for (int i = 1; ++count_compare && i < 10; i++)
		pos[i] += pos[i - 1];
	for (int i = n - 1; ++count_compare && i >= 0; i--)
		dst[--pos[(src[i] / exp) % 10]] = src[i];
	for (int i = 0; ++count_compare && i < n; i++)
		src[i] = dst[i];

	delete[]dst;
	delete[]pos;
}
void radixSort_count(int* src, int n, int& count_compare) {
	int mx = *max_element(src, src + n);
	for (int exp = 1; ++count_compare && mx / exp > 0; exp *= 10)
		digitSort_count(src, n, exp, count_compare);
}