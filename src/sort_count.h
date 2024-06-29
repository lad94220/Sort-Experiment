/*count experiments*/
int maxVal_count(int* start, int* end, unsigned int& count_compare);
int minVal_count(int* start, int* end, unsigned int& count_compare);

//selection sort
void selectionSort_count(int* src, int n, unsigned int& count_compare);
unsigned int selectionSort_countV2(int* src, int n);

//insertion sort
void insertionSort_count(int* src, int n, unsigned int& count_compare);


void bubbleSort_count(int* src, int n, unsigned int& count_compare);

//heap sort
void minHeapRebuild_count(int* src, int n, int pos, unsigned int& count_compare);
void minHeapBuild_count(int* src, int n, unsigned int& count_compare);
void heapSort_count(int* src, int n, unsigned int& count_compare);


//merge sort
void mergeSort_count(int* src, int n, unsigned int& count_compare);
void mergeSortHelper_count(int* src, int start, int end, unsigned int& count_compare);
void mergeArrays_count(int* src, int start, int mid, int end, unsigned int& count_compare);


//quick sort
void quickSort_count(int* src, int n, unsigned int& count_compare);
void quickSortHelper_count(int* src, int left, int right, unsigned int& count_compare);
int partitionForQuickSort_count(int* src, int left, int right, unsigned int& count_compare);

//radix sort
void digitSort_count(int* src, int n, int exp, unsigned int& count_compare);
void radixSort_count(int* src, int n, unsigned int& count_compare);

void shakerSort_count(int* src, int n, unsigned int& count_compare);

//shell sort
void shellSort_count(int* src, int n, unsigned int& count_compare);

//counting sort
void countingSort_count(int* src, int n, unsigned int& count_compare);

//flash sort
void flashSort_count(int* src, int n, unsigned int& count_compare);