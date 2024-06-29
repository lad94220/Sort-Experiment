#include <iostream>
#include <algorithm>
using namespace std;

//selection sort
void selectionSort(int* src, int n);

//insertion sort
void insertionSort(int* src, int n);

//bubble sort
void bubbleSort(int* src, int n);

//heap sort
void minHeapRebuild(int* src, int n, int pos);
void minHeapBuild(int* src, int n);
void heapSort(int* src, int n);

//merge sort
void mergeSort(int* src, int n);
void mergeSortHelper(int* src, int start, int end);
void mergeArrays(int* src, int start, int mid, int end);

//quick sort
void quickSort(int* src, int n);
void quickSortHelper(int* src, int left, int right);
int partitionForQuickSort(int* src, int left, int right);


//radix sort
void digitSort(int* src, int n, int exp);
void radixSort(int* src, int n);

//shaker sort
void shakerSort(int* src, int n);

//shell sort
void shellSort(int* src, int n);

//counting sort
void countingSort(int* src, int n);

//flash sort
void flashSort(int* src, int n);

/* runtime for counting/flash sort */
int maxVal(int* start, int* end);
int minVal(int* start, int* end);


/*-----------------------------------------------------------*/