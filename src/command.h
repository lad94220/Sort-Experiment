#include <iostream>
#include <string.h>
#include <time.h>
#include "sort.h"
#include <chrono>
#include <cstddef> //library for size_t
using namespace std;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

int isNum(char* str);
int* readFile(char* file_name, int& n);
void writeFile(char* file_name, int* array, int n);
size_t count_comparisons(int* array, int n, string algro);
double runtime(int* array, int n, string algro);
