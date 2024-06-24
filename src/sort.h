#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

/*runtime*/

//selection sort
void selectionSort(int* src, int n);

//insertion sort
void insertionSort(int* src, int n);


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

void shakerSort(int* src, int n);

//shell sort
void shellSort(int* src, int n);



void countingSort(int* src, int n);
void flashSort(int* src, int n);

/*-----------------------------------------------------------*/

/*count experiments*/

//selection sort
void selectionSort_count(int* src, int n, int& count_compare);

//insertion sort
void insertionSort_count(int* src, int n, int& count_compare);


void bubbleSort_count(int* src, int n, int& count_compare);

//heap sort
void minHeapRebuild_count(int* src, int n, int pos, int& count_compare);
void minHeapBuild_count(int* src, int n, int& count_compare);
void heapSort_count(int* src, int n, int& count_compare);


//merge sort
void mergeSort_count(int* src, int n, int& count_compare);
void mergeSortHelper_count(int* src, int start, int end, int& count_compare);
void mergeArrays_count(int* src, int start, int mid, int end, int& count_compare);


//quick sort
void quickSort_count(int* src, int n, int& count_compare);
void quickSortHelper_count(int* src, int left, int right, int& count_compare);
int partitionForQuickSort_count(int* src, int left, int right, int& count_compare);

//radix sort
void digitSort_count(int* src, int n, int exp, int& count_compare);
void radixSort_count(int* src, int n, int& count_compare);

void shakerSort_count(int* src, int n, int& count_compare);
void shellSort_count(int* src, int n, int& count_compare);
void countingSort_count(int* src, int n, int& count_compare);
void flashSort_count(int* src, int n, int& count_compare);