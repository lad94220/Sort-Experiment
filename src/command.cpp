#include "command.h"

int isNum(char* str) {
    int num = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            num = num * 10 + str[i] + '0';
        }
        if (str[i] == '.') return 0;
    }
    return num;
}

int* readFile(char* file_name, int& n) {
    FILE* f = fopen(file_name, "r");
    if (!f) {
        cout << "Cannot open file\n";
        return NULL;
    }
    fscanf(f, "%d\n", &n);
    int* array = new int[n];
    cout << n;
    for (int i = 0; i < n; i++) {
        int temp;
        fscanf(f, "%d ", &temp);
        array[i] = temp;
    }
    fclose(f); 
    return array;
}

void writeFile(char* file_name, int* array, int n) {
    FILE* f = fopen(file_name, "a");
    if (!f) {
        cout << "Cannot open file\n";
        return;
    }
    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d ", array[i]);
    }
    fprintf(f, "\n");
    fclose(f);
}

int count_comparisons(int* array, int n, string algro) {
    int count_compare = 0;
    if (algro == "selection-sort") selectionSort_count(array, n, count_compare);
    if (algro == "insertion-sort") insertionSort_count(array, n, count_compare);
    if (algro == "bubble-sort") bubbleSort_count(array, n, count_compare);
    if (algro == "heap-sort") heapSort_count(array, n, count_compare);
    if (algro == "merge-sort") mergeSort_count(array, n, count_compare);
    if (algro == "quick-sort") quickSort_count(array, n, count_compare);
    if (algro == "radix-sort") radixSort_count(array, n, count_compare);
    if (algro == "shaker-sort") shakerSort_count(array, n, count_compare);
    if (algro == "shell-sort") shellSort_count(array, n, count_compare);
    //if (algro == "counting-sort") countingSort_count(array, n, count_compare);
    //if (algro == "flash-sort"); flashSort_count(array, n, count_compare);
    return count_compare;
}

double runtime(int* array, int n, string algro) {
    clock_t start, end;
    double duration;
    if (algro == "selection-sort") {start = clock(); selectionSort(array, n); end = clock();}
    if (algro == "insertion-sort") {start = clock(); insertionSort(array, n); end = clock();}
    if (algro == "bubble-sort") {start = clock(); bubbleSort(array, n); end = clock();}
    if (algro == "heap-sort") {start = clock(); heapSort(array, n); end = clock();}
    if (algro == "merge-sort") {start = clock(); mergeSort(array, n); end = clock();}
    if (algro == "quick-sort") {start = clock(); quickSort(array, n); end = clock();}
    if (algro == "radix-sort") {start = clock(); radixSort(array, n); end = clock();}
    if (algro == "shaker-sort") {start = clock(); shakerSort(array, n); end = clock();}
    if (algro == "shell-sort") {start = clock(); shellSort(array, n); end = clock();}
    //if (algro == "counting-sort") {start = clock(); countingSort(array, n); end = clock();}
    //if (algro == "flash-sort"); {start = clock(); flashSort(array, n); end = clock();}
    duration = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    return duration;
}