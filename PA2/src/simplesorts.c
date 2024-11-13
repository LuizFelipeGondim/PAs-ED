#include "simplesorts.h"

//insertion sort
void insertionSort(int v[], int l, int r, sortperf_t * s) {
  inccalls(s, 1);
  int j, aux;

  for (l++; l < r + 1; l++) {
    aux = v[l];
    incmove(s, 1);

    j = l - 1;
    
    inccmp(s, 1);
    while ((j >= 0) && (aux < v[j])) {
      inccmp(s, 1);

      v[j + 1] = v[j];
      j--;
      incmove(s, 1);
    }

    v[j + 1] = aux;
    incmove(s, 1);
  }

  return;
}

// recursive selection sort
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t * s){
  // find the minimum element in the unsorted subarray `[i…n-1]`
  // and swap it with `arr[i]`
  int min = l;
  inccalls(s,1);
  for (int j = l + 1; j <= r; j++)
  {
      // if `arr[j]` is less, then it is the new minimum
inccmp(s,1);
    if (arr[j] < arr[min]) {
      min = j;    // update the index of minimum element
    }
  }

  // swap the minimum element in subarray `arr[i…n-1]` with `arr[i]`
  if (min!=l)
    swap(&arr[min], &arr[l], s);

  if (l + 1 < r) {
    recursiveSelectionSort(arr, l + 1, r, s);
  }
}

// selection sort
void selectionSort(int arr[], int l, int r, sortperf_t * s) { 
  inccalls(s, 1);
  int min, j;

  for (; l < r; l++) {
    min = l;

    for (j = l + 1; j < r + 1; j++) {
      inccmp(s, 1);
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    if (l != min) {
      swap(&arr[l], &arr[min], s);
    }
  }

  return;
}

// shellsort
void shellSort(int *A, int n, sortperf_t * s) {
  inccalls(s, 1);
  int aux;
  
  for (int h = n/2; h > 0; h /= 2) {
    for (int i = h; i < n; i += 1) {
      aux = A[i];
      incmove(s, 1);
      
      int j;
      inccmp(s, 1);
      for (j = i; j >= h && A[j - h] > aux; j -= h) {
        inccmp(s, 1);
        
        A[j] = A[j - h];
        incmove(s, 1);
      }
      
      A[j] = aux;
      incmove(s, 1);
    }
  }
}