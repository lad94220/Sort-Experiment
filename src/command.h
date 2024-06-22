#include <iostream>
#include <string.h>
#include <time.h>
#include "sort.h"
using namespace std;

int isNum(char* str);
int* readFile(char* file_name, int& n);
int count_comparisons(int* array, int n, string algro);
long long runtime(int* array, int n, string algro);