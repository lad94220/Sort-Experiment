#include <iostream>
using namespace std;

//runtime
void selectionSort(int* src, int n);



//count experiments
void selectionSort_count(int* src, int n, int& count_compare);
void insertionSort_count(int* src, int n, int& count_compare);
void bubbleSort_count(int* src, int n, int& count_compare);
void heapSort_count(int* src, int n, int& count_compare);
void mergeSort_count(int* src, int n, int& count_compare);
void quickSort_count(int* src, int n, int& count_compare);
void radixSort_count(int* src, int n, int& count_compare);
void shakerSort_count(int* src, int n, int& count_compare);
void shellSort_count(int* src, int n, int& count_compare);
void countingSort_count(int* src, int n, int& count_compare);
void flashSort_count(int* src, int n, int& count_compare);