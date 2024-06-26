#include "sort.h"

int maxVal_count(int* start, int* end, long long& count_compare) {
	int mx = *start;
	for (int* run = start; ++count_compare && run < end; run++)
		if (++count_compare && *run > mx) mx = *run;
	return mx;
}

int minVal_count(int* start, int* end, long long& count_compare) {
	int mn = *start;
	for (int* run = start; ++count_compare && run < end; run++)
		if (++count_compare && *run < mn) mn = *run;
	return mn;
}

// selection sort
void selectionSort_count(int* src, int n, long long& count_compare) {
    for (int i = 0;++count_compare && i < n; ++i) {
		int mind_idex = i;
        for (int j = i + 1;++count_compare && j < n; ++j) {
            if (++count_compare && src[j] < src[mind_idex]) mind_idex = j;
        }
		if (++count_compare && mind_idex != i) swap(src[mind_idex], src[i]);
    }
}

// insertion sort
void insertionSort_count(int* src, int n, long long& count_compare) {
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

// bubble sort
void bubbleSort_count(int* src, int n, long long& count_compare) {
	for (int i = 0; ++count_compare && i < n; ++i) {
		for (int j = 0; ++count_compare && j < n - i - 1; ++j) {
			if (++count_compare && src[j] > src[j + 1]) swap(src[j], src[j + 1]);
		}
	}
}

// heap sort
void minHeapRebuild_count(int* src, int n, int pos, long long& count_compare) {
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
void minHeapBuild_count(int* src, int n, long long& count_compare) {
	for (int i = (n - 2) / 2; ++count_compare && i >= 0; i--)
		minHeapRebuild_count(src, n, i, count_compare);
}
void heapSort_count(int* src, int n, long long& count_compare) {
	int m = n;
	for (int* tmp = src; ++count_compare && tmp < src + n; tmp++)
		minHeapBuild_count(tmp, m--, count_compare);
}


// merge sort
void mergeSort_count(int* src, int n, long long& count_compare) {
	mergeSortHelper_count(src, 0, n - 1, count_compare);
}
void mergeSortHelper_count(int* src, int start, int end, long long& count_compare) {
	if (++count_compare && start >= end) return;
	int mid = (start + end) / 2;
	mergeSortHelper(src, start, mid);
	mergeSortHelper(src, mid+1, end);
	mergeArrays(src, start, mid, end);
}
void mergeArrays_count(int* src, int start, int mid, int end, long long& count_compare) {
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

//quick sort
void quickSort_count(int* src, int n, long long& count_compare) {
	quickSortHelper_count(src, 0, n - 1, count_compare);
}
void quickSortHelper_count(int* src, int left, int right, long long& count_compare) {
	if (++count_compare && left < right) {
        int pivot_position = partitionForQuickSort(src, left, right);
        quickSortHelper(src, left, pivot_position-1);
        quickSortHelper(src, pivot_position+1, right);
    }
}
int partitionForQuickSort_count(int* src, int left, int right, long long& count_compare) {
	srand(time(NULL));
    int random = left + rand()%(right - left);
    swap(src[random], src[right]);
    int pivot = src[right];
    int first_larger = left;
	
    for (int i = left;++count_compare && i <= right-1; i++) {
        if (++count_compare && src[i] < pivot) {
			++first_larger;
            swap(src[first_larger], src[i]);
        }
    }
    swap(src[first_larger], src[right]);
    return first_larger;
}


// radix sort
void digitSort_count(int* src, int n, int exp, long long& count_compare) {
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
void radixSort_count(int* src, int n, long long& count_compare) {
	int mx = maxVal_count(src, src + n, count_compare);
	for (int exp = 1; ++count_compare && mx / exp > 0; exp *= 10)
		digitSort_count(src, n, exp, count_compare);
}

// shaker sort
void shakerSort_count(int* src, int n, long long& count_compare) {
	int left = 0, right = n - 1;
	while (++count_compare && left < right) {
		for (int i = left; ++count_compare && i < right; i++) {
			if (++count_compare && src[i] > src[i + 1]) swap(src[i], src[i + 1]);
		}
		right--;
		for (int i = right; ++count_compare && i > left; i--) {
			if (++count_compare && src[i] < src[i - 1]) swap(src[i], src[i - 1]);
		}
		left++;
	}
}

// shell sort
void shellSort_count(int* src, int n, long long& count_compare) {
	for (int gap = n/2;++count_compare && gap >= 1; gap /= 2) {
		for (int i = gap; i < n; ++i) {
			int key = src[i];
			int j = i - gap;
			while (++count_compare && j > 0 && ++count_compare && src[j] > key) {
				src[j + gap] = src[j];
				j -= gap;
			}
			src[j + gap] = key;
		}
	}
}

//counting sort
void countingSort_count(int* src, int n, long long& count_compare) {
	int mx = maxVal_count(src, src + n, count_compare);
	int* pos = new int[mx + 1]();
	int* dst = new int[n];

	for (int i = 0; ++count_compare && i < n; i++)
		pos[src[i]]++;
	for (int i = 1; ++count_compare && i <= mx; i++)
		pos[i] += pos[i - 1];
	for (int i = n - 1; ++count_compare && i >= 0; i--)
		dst[--pos[src[i]]] = src[i];
	for (int i = 0; ++count_compare && i < n; i++)
		src[i] = dst[i];

	delete[]dst;
	delete[]pos;
}

//flash sort
void flashSort_count(int* src, int n, long long& count_compare) {
	int mx = maxVal_count(src, src + n, count_compare);
	int mn = minVal_count(src, src + n, count_compare);

	int bucketNum = (int)(0.45 * n);
	int* bucket = new int[bucketNum]();
	int* dst = new int[n];
	int* pos = new int[bucketNum];

	for (int i = 0; ++count_compare && i < n; i++)
		bucket[(bucketNum - 1) * (src[i] - mn) / (mx - mn)]++;
	pos[0] = bucket[0];
	for (int i = 1; ++count_compare && i < bucketNum; i++)
		pos[i] = bucket[i] + pos[i - 1];
	for (int i = n - 1; ++count_compare && i >= 0; i--)
		dst[--pos[(bucketNum - 1) * (src[i] - mn) / (mx - mn)]] = src[i];
	for (int i = 0; ++count_compare && i < n; i++)
		src[i] = dst[i];
	int ind = 0;
	int* run = src;
	while (++count_compare && run < src + n) {
		int len = bucket[ind];
		selectionSort_count(run, len, count_compare);
		run += bucket[ind++];
	}

	delete[]pos;
	delete[]dst;
	delete[]bucket;
}