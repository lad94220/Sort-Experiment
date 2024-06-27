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

unsigned int count_comparisons(int* array, int n, string algro) {
    unsigned int count_compare = 0;
    if (algro == "selection-sort") selectionSort_count(array, n, count_compare);
    if (algro == "insertion-sort") insertionSort_count(array, n, count_compare);
    if (algro == "bubble-sort") bubbleSort_count(array, n, count_compare);
    if (algro == "heap-sort") heapSort_count(array, n, count_compare);
    if (algro == "merge-sort") mergeSort_count(array, n, count_compare);
    if (algro == "quick-sort") quickSort_count(array, n, count_compare);
    if (algro == "radix-sort") radixSort_count(array, n, count_compare);
    if (algro == "shaker-sort") shakerSort_count(array, n, count_compare);
    if (algro == "shell-sort") shellSort_count(array, n, count_compare);
    if (algro == "counting-sort") countingSort_count(array, n, count_compare);
    //if (algro == "flash-sort"); flashSort_count(array, n, count_compare);
    return count_compare;
}

double runtime(int* array, int n, string algro) {
    if (algro == "selection-sort") {
        auto start = std::chrono::high_resolution_clock::now();
        selectionSort(array, n);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();
        return duration;
    }
    if (algro == "insertion-sort") {
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(array, n);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();
        return duration;
    }
    if (algro == "bubble-sort") {
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(array, n);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();
        return duration;
        }
    if (algro == "heap-sort") {
        auto start = std::chrono::high_resolution_clock::now();
        heapSort(array, n);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();
        return duration;
        }
    if (algro == "merge-sort") {
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(array, n);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();
        return duration;
    }
    if (algro == "quick-sort") {
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(array, n);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();
        return duration;
    }
    if (algro == "radix-sort") {
        auto start = std::chrono::high_resolution_clock::now();
        radixSort(array, n);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();
        return duration;
    }
    if (algro == "shaker-sort") {
        auto start = std::chrono::high_resolution_clock::now();
        shakerSort(array, n);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();
        return duration;
    }
    if (algro == "shell-sort") {
        auto start = std::chrono::high_resolution_clock::now();
        shellSort(array, n);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();
        return duration;
    }
    if (algro == "counting-sort") {
        auto start = std::chrono::high_resolution_clock::now();
        countingSort(array, n);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();
        return duration;
    }
    if (algro == "flash-sort"); {
        auto start = std::chrono::high_resolution_clock::now();
        flashSort(array, n);
        auto end = std::chrono::high_resolution_clock::now();
        double duration = duration_cast<milliseconds>(end - start).count();
        return duration;
    }
}