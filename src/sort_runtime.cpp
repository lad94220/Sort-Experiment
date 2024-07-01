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
	for (int i = 1; i < n; i++) {
		int key = src[i];
		int j = i - 1;
		while (j >= 0 && src[j] > key) {
			src[j + 1] = src[j];
			j--;
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
	maxHeapBuild(src, n);
	for (int i = n - 1; i > 0; i--) {
		swap(src[0], src[i]);
		maxHeapRebuild(src, i, 0);
	}
}
void maxHeapRebuild(int* src, int n, int pos) {
	int _pos = pos;

	while (2 * _pos + 1 < n) {
		int child = 2 * _pos + 1;
		if (child < n - 1)
			if (src[child] < src[child + 1]) child++;
		if (src[_pos] < src[child]) {
			swap(src[_pos], src[child]);
			_pos = child;
		}
		else break;
	}
}
void maxHeapBuild(int* src, int n) {
	for (int i = (n - 2) / 2; i >= 0; i--)
		maxHeapRebuild(src, n, i);
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

void flashSort(int* src, int n) {
    if (n <= 1) return;

    int Mn = src[0];
    int Mx = src[0];
    for (int i = 1; i < n; ++i) {
        if (src[i] < Mn) Mn = src[i];
        if (src[i] > Mx) Mx = src[i];
    }
    if (Mx == Mn) return;

    int bucketNum = static_cast<int>(0.45 * n);
    int* pos = new int[bucketNum]();
    double c = static_cast<double>(bucketNum - 1) / (Mx - Mn);

    for (int i = 0; i < n; ++i)
        pos[static_cast<int>(c * (src[i] - Mn))]++;
    for (int i = 1; i < bucketNum; ++i)
        pos[i] += pos[i - 1];

    int count = 0;
    int i = 0;
    while (count < n) {
        int k = static_cast<int>(c * (src[i] - Mn));
        while (i >= pos[k])
            k = static_cast<int>(c * (src[++i] - Mn));
        int tmp = src[i];
        while (i != pos[k]) {
            k = static_cast<int>(c * (tmp - Mn));
            std::swap(tmp, src[--pos[k]]);
            ++count;
        }
    }

    delete[] pos;
    insertionSort(src, n);
}


//subroutines for counting sort
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