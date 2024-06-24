#include "sort.h"

//selection sort implementation
void selectionSort(int* src, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (src[j] < src[i]) swap(src[i], src[j]);
        }
    }
}

//insertion sort implementation
void insertionSort(int* src, int n) {
	for (int i = 1; i < n; i++) {
		int key = src[i];
		int j = i - 1;
		while (j > 0 && src[j] > key) {
			src[j + 1] = src[j];
			j--;
		}
		src[j + 1] = key;
	}
}


void minHeapRebuild(int* src, int n, int pos) {
	int _pos = pos;

	while (2 * _pos + 1 < n) {
		int child = 2 * _pos + 1;

		if (child < n - 1)
			if (src[child] > src[child + 1]) child += 1;
		if (src[_pos] > src[child]) {
			swap(src[_pos], src[child]);
			_pos = child;
		}
		else break;
	}
}
void minHeapBuild(int* src, int n) {
	for (int i = (n - 2) / 2; i >= 0; i--)
		minHeapRebuild(src, n, i);
}
void heapSort(int* src, int n) {
	int m = n;
	for (int* tmp = src; tmp < src + n; tmp++)
		minHeapBuild(tmp, m--);
}


void digitSort(int* src, int n, int exp) {
	int* pos = new int[10]();
	int* dst = new int[n];

	for (int i = 0; i < n; i++)
		pos[(src[i] / exp) % 10]++;
	for (int i = 1; i < 10; i++)
		pos[i] += pos[i - 1];
	for (int i = n - 1; i >= 0; i--)
		dst[--pos[(src[i] / exp) % 10]] = src[i];
	for (int i = 0; i < n; i++)
		src[i] = dst[i];

	delete[]dst;
	delete[]pos;
}
void radixSort(int* src, int n) {
	int mx = *max_element(src, src + n);
	for (int exp = 1; mx / exp > 0; exp *= 10)
		digitSort(src, n, exp);
}