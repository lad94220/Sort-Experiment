#include "sort_count.h"

// selection sort
void selectionSort_count(int* src, int n, size_t& count_compare) {
    for (int i = 0; ++count_compare && i < n; ++i) {
		int mind_idex = i;
        for (int j = i + 1; ++count_compare && j < n; ++j) {
            if (++count_compare && src[j] < src[mind_idex]) mind_idex = j;
        }
		if (++count_compare && mind_idex != i) swap(src[mind_idex], src[i]);
    }
}

// insertion sort
void insertionSort_count(int* src, int n, size_t& count_compare) {
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
void bubbleSort_count(int* src, int n, size_t& count_compare) {
	for (int i = 0; ++count_compare && i < n; ++i) {
		for (int j = 0; ++count_compare && j < n - i - 1; ++j) {
			if (++count_compare && src[j] > src[j + 1]) swap(src[j], src[j + 1]);
		}
	}
}


// heap sort
void heapSort_count(int* src, int n, size_t& count_compare) {
	maxHeapBuild_count(src, n, count_compare);
	for (int i = n - 1; ++count_compare && i > 0; i--) {
		swap(src[0], src[i]);
		maxHeapRebuild_count(src, i, 0, count_compare);
	}
}
void maxHeapRebuild_count(int* src, int n, int pos, size_t& count_compare) {
	int _pos = pos;

	while (++count_compare && 2 * _pos + 1 < n) {
		int child = 2 * _pos + 1;
		if (++count_compare && child < n - 1)
			if (++count_compare && src[child] < src[child + 1]) child++;
		if (++count_compare && src[_pos] < src[child]) {
			swap(src[_pos], src[child]);
			_pos = child;
		}
		else break;
	}
}
void maxHeapBuild_count(int* src, int n, size_t& count_compare) {
	for (int i = (n - 2) / 2; ++count_compare && i >= 0; i--)
		maxHeapRebuild_count(src, n, i, count_compare);
}

// merge sort
void mergeSort_count(int* src, int n, size_t& count_compare) {
	mergeSortHelper_count(src, 0, n - 1, count_compare);
}
void mergeSortHelper_count(int* src, int start, int end, size_t& count_compare) {
	if (++count_compare && start >= end) return;
	int mid = (start + end) / 2;
	mergeSortHelper_count(src, start, mid, count_compare);
	mergeSortHelper_count(src, mid+1, end, count_compare);
	mergeArrays_count(src, start, mid, end, count_compare);
}
void mergeArrays_count(int* src, int start, int mid, int end, size_t& count_compare) {
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
void quickSort_count(int* src, int n, size_t& count_compare) {
	quickSortHelper_count(src, 0, n - 1, count_compare);
}
void quickSortHelper_count(int* src, int left, int right, size_t& count_compare) {
	if (++count_compare && left < right) {
        int pivot_position = partitionForQuickSort_count(src, left, right, count_compare);
        quickSortHelper_count(src, left, pivot_position-1, count_compare);
        quickSortHelper_count(src, pivot_position+1, right, count_compare);
    }
}
int partitionForQuickSort_count(int* src, int left, int right, size_t& count_compare) {
	srand(time(NULL));
    int random = left + rand()%(right - left);
    swap(src[random], src[right]);

    int pivot = src[right];
    int first_larger = left - 1;
	
    for (int i = left;++count_compare && i < right; i++) {
        if (++count_compare && src[i] <= pivot) {
			++first_larger;
            swap(src[first_larger], src[i]);
        }
    }
    swap(src[first_larger + 1], src[right]);
    return first_larger + 1;
}


// radix sort
void digitSort_count(int* src, int n, int exp, size_t& count_compare) {
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
void radixSort_count(int* src, int n, size_t& count_compare) {
	int mx = maxVal_count(src, src + n, count_compare);
	for (int exp = 1; ++count_compare && mx / exp > 0; exp *= 10)
		digitSort_count(src, n, exp, count_compare);
}

// shaker sort
void shakerSort_count(int* src, int n, size_t& count_compare) {
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
void shellSort_count(int* src, int n, size_t& count_compare) {
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
void countingSort_count(int* src, int n, size_t& count_compare) {
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

void flashSort_count(int* src, int n, size_t& count_compare) {
	int Mn = *src;
	int mxInd = 0;
	for (int* run = src; ++count_compare && run < src + n; run++) {
		if (++count_compare && *run < Mn) Mn = *run;
		if (++count_compare && *run > *(src + mxInd)) mxInd = run - src;
	}
	if (++count_compare && *(src + mxInd) == Mn) return;

	int bucketNum = int(0.45 * n);

	int c = (int)(bucketNum - 1) / (*(src + mxInd) - Mn);

	int* pos = new int[bucketNum]();
	for (int i = 0; ++count_compare && i < n; i++)
		pos[c * (src[i] - Mn)]++;
	for (int i = 1; ++count_compare && i < bucketNum; i++)
		pos[i] += pos[i - 1];

	swap(src[mxInd], src[0]);
	int nmove = 0;
	int j = 0;
	int k = bucketNum - 1;
	int t = 0;
	while (++count_compare && nmove < n - 1)
	{
		while (++count_compare && j > pos[k] - 1)
		{
			j++;
			k = c * (src[j] - Mn);
		}
		int tmp = src[j];
		if (++count_compare && k < 0) break;
		while (++count_compare && j != pos[k])
		{
			k = c * (tmp - Mn);
			int hold = src[t = --pos[k]];
			src[t] = tmp;
			tmp = hold;
			++nmove;
		}
	}

	delete[]pos;
	insertionSort_count(src, n, count_compare);
}

//subroutines for counting/flash sort
int maxVal_count(int* start, int* end, size_t& count_compare) {
	int mx = *start;
	for (int* run = start; ++count_compare && run < end; run++)
		if (++count_compare && *run > mx) mx = *run;
	return mx;
}
int minVal_count(int* start, int* end, size_t& count_compare) {
	int mn = *start;
	for (int* run = start; ++count_compare && run < end; run++)
		if (++count_compare && *run < mn) mn = *run;
	return mn;
}