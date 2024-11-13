#ifndef SIMPLESORTS_H
#define SIMPLESORTS_H

#include "sortutils.h"

void insertionSort(int v[], int l, int r, sortperf_t *s);
void selectionSort(int arr[], int l, int r, sortperf_t *s);
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s);
void shellSort(int *A, int n, sortperf_t *s);

#endif