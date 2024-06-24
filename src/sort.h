#include <iostream>
#include<algorithm>
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

//quick sort
void quickSort(int* src, int n);

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

void selectionSort_count(int* src, int n, int& count_compare);
void insertionSort_count(int* src, int n, int& count_compare);
void bubbleSort_count(int* src, int n, int& count_compare);

//heap sort
void minHeapRebuild_count(int* src, int n, int pos, int& count_compare);
void minHeapBuild_count(int* src, int n, int& count_compare);
void heapSort_count(int* src, int n, int& count_compare);

void mergeSort_count(int* src, int n, int& count_compare);
void quickSort_count(int* src, int n, int& count_compare);

//radix sort
void digitSort_count(int* src, int n, int exp, int& count_compare);
void radixSort_count(int* src, int n, int& count_compare);

void shakerSort_count(int* src, int n, int& count_compare);
void shellSort_count(int* src, int n, int& count_compare);
void countingSort_count(int* src, int n, int& count_compare);
void flashSort_count(int* src, int n, int& count_compare);