#ifndef COMMAND_H
#define COMMAND_H


#include <iostream>
#include <string.h>
#include <time.h>
#include "sort.h"
#include <chrono>
using namespace std;
using std::chrono::high_resolution_clock;
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
long long count_comparisons(int* array, int n, string algro);
double runtime(int* array, int n, string algro);


#endif