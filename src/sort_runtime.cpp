#include "sort.h"

// selection sort
void selectionSort(int* src, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (src[j] < src[i]) swap(src[i], src[j]);
        }
    }
}

// insertion sort
void insertionSort(int* src, int n) {
	for (int i = 1; i < n; ++i) {
		int key = src[i];
		int j = i - 1;
		while (j > 0 && src[j] > key) {
			src[j + 1] = src[j];
			--j;
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



// merge sort
void mergeSort(int* src, int n) {
	mergeSortRecursive(src, 0, n-1);
}
void mergeSortRecursive(int* src, int start, int end) {
	if (start > end) return;
	int mid = (start + end) / 2;
	mergeSortRecursive(src, start, mid);
	mergeSortRecursive(src, mid+1, end);
	mergeArrays(src, start, mid, end);
}
void mergeArrays(int* src, int start, int mid, int end) {
	int left_size = mid - start + 1;
	int right_size = end - mid;
	int *src_left = new int[left_size];
	int *src_right = new int[right_size];
	for (int i = 0; i < left_size; i++) src_left[i] = src[start + i];
	for (int i = 0; i < right_size; i++) src_right[i] = src[mid + 1 + i];
	int left_taken = 0, right_taken = 0, fill_location = start;

	while (left_taken < left_size && right_taken < right_size) {
		if (src_left[left_taken] < src_right[right_taken]) {
			src[fill_location] = src_left[left_taken];
			left_taken++;
		} else {
			src[fill_location] = src_right[right_taken];
			right_taken++;
		}
		fill_location++;
	}
	
	while (left_taken < left_size) {
		src[fill_location] = src_left[left_taken];
		left_taken++;
		fill_location++;
	}

	while (right_taken < right_size) {
		src[fill_location] = src_right[right_taken];
		right_taken++;
		fill_location++;
	}

	delete src_left;
	delete src_right;
}



// quick sort


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