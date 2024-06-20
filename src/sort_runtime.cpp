#include "sort.h"


void selectionSort(int* src, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (src[j] < src[i]) swap(src[i], src[j]);
        }
    }
}