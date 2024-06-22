#include <iostream>
#include <string.h>
#include <time.h>
#include "sort.h"
using namespace std;

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

int isNum(char* str);
int* readFile(char* file_name, int& n);
void writeFile(char* file_name, int* array, int n);
int count_comparisons(int* array, int n, string algro);
long long runtime(int* array, int n, string algro);