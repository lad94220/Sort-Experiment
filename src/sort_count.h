#include <iostream>
#include <algorithm>
#include <cstddef> //library for size_t
using namespace std;

/*count experiments*/
int maxVal_count(int* start, int* end, size_t& count_compare);
int minVal_count(int* start, int* end, size_t& count_compare);

//selection sort
void selectionSort_count(int* src, int n, size_t& count_compare);

//insertion sort
void insertionSort_count(int* src, int n, size_t& count_compare);


void bubbleSort_count(int* src, int n, size_t& count_compare);

//heap sort
void maxHeapRebuild_count(int* src, int n, int pos, size_t& count_compare);
void maxHeapBuild_count(int* src, int n, size_t& count_compare);
void heapSort_count(int* src, int n, size_t& count_compare);


//merge sort
void mergeSort_count(int* src, int n, size_t& count_compare);
void mergeSortHelper_count(int* src, int start, int end, size_t& count_compare);
void mergeArrays_count(int* src, int start, int mid, int end, size_t& count_compare);


//quick sort
void quickSort_count(int* src, int n, size_t& count_compare);
void quickSortHelper_count(int* src, int left, int right, size_t& count_compare);
int partitionForQuickSort_count(int* src, int left, int right, size_t& count_compare);

//radix sort
void digitSort_count(int* src, int n, int exp, size_t& count_compare);
void radixSort_count(int* src, int n, size_t& count_compare);

void shakerSort_count(int* src, int n, size_t& count_compare);

//shell sort
void shellSort_count(int* src, int n, size_t& count_compare);

//counting sort
void countingSort_count(int* src, int n, size_t& count_compare);

//flash sort
void flashSort_count(int* src, int n, size_t& count_compare);