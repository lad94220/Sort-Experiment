#include "sort.h"

// selection sort
void selectionSort_count(int* src, int n, int& count_compare) {
    for (int i = 0; ++count_compare && i < n; ++i) {
        for (int j = i + 1; ++count_compare && j < n; ++j) {
            if (src[j] < src[i]) swap(src[i], src[j]);
        }
    }
}

// insertion sort
void insertionSort_count(int* src, int n, int& count_compare) {
	for (int i = 1; ++count_compare && i < n; ++i) {
		int key = src[i];
		int j = i - 1;
		while (++count_compare && j > 0 && ++count_compare && src[j] > key) {
			src[j + 1] = src[j];
			--j;
		}
		src[j + 1] = key;
	}
}



// heap sort
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


// merge sort
void mergeSort_count(int* src, int n, int& count_compare) {
	mergeSortRecursive_count(src, 0, n - 1, count_compare);
}
void mergeSortRecursive_count(int* src, int start, int end, int& count_compare) {
	if (++count_compare && start > end) return;
	int mid = (start + end) / 2;
	mergeSortRecursive(src, start, mid);
	mergeSortRecursive(src, mid+1, end);
	mergeArrays(src, start, mid, end);
}
void mergeArrays_count(int* src, int start, int mid, int end, int& count_compare) {
	int left_size = mid - start + 1;
	int right_size = end - mid;
	int *src_left = new int[left_size];
	int *src_right = new int[right_size];
	for (int i = 0;++count_compare && i < left_size; i++) src_left[i] = src[start + i];
	for (int i = 0;++count_compare && i < right_size; i++) src_right[i] = src[mid + 1 + i];
	int left_taken = 0, right_taken = 0, fill_location = start;

	while (++count_compare && left_taken < left_size && ++count_compare && right_taken < right_size) {
		if (++count_compare && src_left[left_taken] < src_right[right_taken]) {
			src[fill_location] = src_left[left_taken];
			left_taken++;
		} else {
			src[fill_location] = src_right[right_taken];
			right_taken++;
		}
		fill_location++;
	}
	
	while (++count_compare && left_taken < left_size) {
		src[fill_location] = src_left[left_taken];
		left_taken++;
		fill_location++;
	}

	while (++count_compare && right_taken < right_size) {
		src[fill_location] = src_right[right_taken];
		right_taken++;
		fill_location++;
	}

	delete src_left;
	delete src_right;
}


// radix sort
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