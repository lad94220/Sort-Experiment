#include "command.h"

int isNum(char* str) {
    int num = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            num = num * 10 + str[i] + '0';
        }
        if (str[i] == '.') return 0;
    }
    cout << num;
}

int* readFile(char* file_name, int& n) {
    FILE* f = fopen(file_name, "r");
    if (!f) {
        cout << "Cannot open file\n";
        return;
    }
    fscanf(f, "%d\n", &n);
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d ", array[i]);
    }
    fclose(f); 
    return array;
}