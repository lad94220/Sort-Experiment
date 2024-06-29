#include "sort_runtime.h"


// selection sort
void selectionSort(int* src, int n) {
    for (int i = 0; i < n; ++i) {
		int mind_idex = i;
        for (int j = i + 1; j < n; ++j) {
            if (src[j] < src[mind_idex]) mind_idex = j;
        }
		if (mind_idex != i) swap(src[mind_idex], src[i]);
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


//bubble sort
void bubbleSort(int* src, int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (src[j] > src[j + 1]) swap(src[j], src[j + 1]);
		}
	}

}


//heap sort
void heapSort(int* src, int n) {
	int m = n;
	for (int* tmp = src; tmp < src + n; tmp++)
		minHeapBuild(tmp, m--);
}
void minHeapBuild(int* src, int n) {
	for (int i = (n - 2) / 2; i >= 0; i--)
		minHeapRebuild(src, n, i);
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


// merge sort
void mergeSort(int* src, int n) {
	mergeSortHelper(src, 0, n-1);
}
void mergeSortHelper(int* src, int start, int end) {
	if (start >= end) return;
	int mid = (start + end) / 2;
	mergeSortHelper(src, start, mid);
	mergeSortHelper(src, mid+1, end);
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
void quickSort(int* src, int n) {
	quickSortHelper(src, 0, n - 1);
}
void quickSortHelper(int* src, int left, int right) {
    if (left < right) {
        int pivot_position = partitionForQuickSort(src, left, right);
        quickSortHelper(src, left, pivot_position-1);
        quickSortHelper(src, pivot_position+1, right);
    }
}
int partitionForQuickSort(int* src, int left, int right) {
	srand(time(NULL));
    int random = left + rand()%(right - left);
    swap(src[random], src[right]);

    int pivot = src[right];
    int first_larger = left - 1;

    for (int i = left; i < right; i++) {
        if (src[i] <= pivot) {
			++first_larger;
            swap(src[first_larger], src[i]);
        }
    }
    swap(src[first_larger + 1], src[right]);
    return first_larger + 1;
}


//radix sort
void radixSort(int* src, int n) {
	int mx = maxVal(src, src + n);
	for (int exp = 1; mx / exp > 0; exp *= 10)
		digitSort(src, n, exp);
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


//shaker sort
void shakerSort(int* src, int n)
{
	int left = 0, right = n - 1;
	int last = right;
	while (left < right) {
		for (int i = right; i > left; i--) {
			if (src[i] < src[i - 1]) {
				swap(src[i], src[i - 1]);
				last = i;
			}
		}
		left = last;
		for (int i = left; i < right; i++) {
			if (src[i] > src[i + 1]) {
				swap(src[i], src[i + 1]);
				last = i;
			}
		}
		right = last;
	}
}


// shell sort
void shellSort(int* src, int n) {
	for (int gap = n/2; gap >= 1; gap /= 2) {
		for (int i = gap; i < n; ++i) {
			int key = src[i];
			int j = i - gap;
			while (j > 0 && src[j] > key) {
				src[j + gap] = src[j];
				j -= gap;
			}
			src[j + gap] = key;
		}
	}
}


//counting sort
void countingSort(int* src, int n) {
	int mx = maxVal(src, src + n);
	int* pos = new int[mx + 1]();
	int* dst = new int[n];

	for (int i = 0; i < n; i++)
		pos[src[i]]++;
	for (int i = 1; i <= mx; i++)
		pos[i] += pos[i - 1];
	for (int i = n - 1; i >= 0; i--)
		dst[--pos[src[i]]] = src[i];
	for (int i = 0; i < n; i++)
		src[i] = dst[i];

	delete[]dst;
	delete[]pos;
}


//flash sort
void flashSort(int* src, int n) {
	int mx = maxVal(src, src + n);
	int mn = minVal(src, src + n);

	int bucketNum = (int)(0.45 * n);
	int* bucket = new int[bucketNum]();
	int* dst = new int[n];
	int* pos = new int[bucketNum];

	for (int i = 0; i < n; i++)
		bucket[(bucketNum - 1) * (src[i] - mn) / (mx - mn)]++;
	pos[0] = bucket[0];
	for (int i = 1; i < bucketNum; i++)
		pos[i] = bucket[i] + pos[i - 1];
	for (int i = n - 1; i >= 0; i--)
		dst[--pos[(bucketNum - 1) * (src[i] - mn) / (mx - mn)]] = src[i];
	for (int i = 0; i < n; i++)
		src[i] = dst[i];
	int ind = 0;
	int* run = src;
	while (run < src + n) {
		int len = bucket[ind];
		selectionSort(run, len);
		run += bucket[ind++];
	}

	delete[]pos;
	delete[]dst;
	delete[]bucket;
}

//subroutines for counting/flash sort
int maxVal(int* start, int* end) {
	int mx = *start;
	for (int* run = start; run < end; run++)
		if (*run > mx) mx = *run;
	return mx;
}
int minVal(int* start, int* end) {
	int mn = *start;
	for (int* run = start; run < end; run++)
		if (*run < mn) mn = *run;
	return mn;
}