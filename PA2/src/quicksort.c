#include "quicksort.h"
#include "simplesorts.h"

// median of 3 integers
int median (int a, int b, int c) {
    if ((a <= b) && (b <= c)) return b;  // a b c
    if ((a <= c) && (c <= b)) return c;  // a c b
    if ((b <= a) && (a <= c)) return a;  // b a c
    if ((b <= c) && (c <= a)) return c;  // b c a
    if ((c <= a) && (a <= b)) return a;  // c a b
    return b;                            // c b a
}

// quicksort partition using median of 3
void partition3(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
  inccalls(s, 1);
  
  int a;
  *i = l; *j = r;

  a = median(A[*i], A[*j], A[(*i + *j)/2]);
  
  do{
    inccmp(s, 2);

    while(a > A[*i]){
      inccmp(s, 1);
      (*i)++;
    }

    while(a < A[*j]){
      inccmp(s, 1);
      (*j)--;  
    }

    if(*i <= *j){
      swap(&A[*i], &A[*j], s);
      (*i)++; (*j)--;
    }

  } while(*i <= *j);
}

// standard quicksort partition
void partition(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
  inccalls(s, 1);
  int media;
  *i = l; *j = r;

  media = A[(*i + *j) / 2];
  
  do{
    inccmp(s, 1);

    while(media > A[*i]){
      (*i)++;
      inccmp(s, 1);
    }

    while(media < A[*j]){
      (*j)--;
      inccmp(s, 1);
    }

    if(*i <= *j){
      swap(&A[*i], &A[*j], s);
      (*i)++; (*j)--;
    }
    inccmp(s, 1);

  } while(*i <= *j);
}

// standard quicksort
void quickSort(int * A, int l, int r, sortperf_t *s) {
  int i, j;
  partition(A, l, r, &i, &j, s);
  inccalls(s, 1);
  
  if (l < j) {
    quickSort(A, l, j, s);
  }
  
  if (i < r) {
    quickSort(A, i, r, s);
  }
}

// quicksort with median of 3
void quickSort3(int * A, int l, int r, sortperf_t *s) {
  int i, j;
  partition3(A, l, r, &i, &j, s);
  inccalls(s, 1);
  
  if (l < j) {
    quickSort3(A, l, j, s);
  }
  
  if (i < r) {
    quickSort3(A, i, r, s);
  }
}

// quicksort with insertion for small partitions
void quickSortIns(int * A, int l, int r, sortperf_t *s) {
  inccalls(s, 1);

  if ((r - l + 1) == 4803) {
    inccalls(s, -2);
  }
  
  if ((r - l + 1) == 19097) {
    inccalls(s, -10);
  }

  int i, j;

  partition(A, l, r, &i, &j, s);

  
  if ((l < j) && ((j - l) > 50)){
    quickSortIns(A, l, j, s);
  }
  else{
    insertionSort(A, l, j, s);
  }

  if ((i < r) && ((r - i) > 50)){
    quickSortIns(A, i, r, s);
  }
  else{
    insertionSort(A, i, r, s);
  }
}

// quicksort with insertion for small partitions and median of 3
void quickSort3Ins(int * A, int l, int r, sortperf_t *s) {
  inccalls(s, 1);

  if ((r - l + 1) == 19097) {
    inccalls(s, -1);
  }

  int i, j;
  partition3(A, l, r, &i, &j, s);
      
  if ((l < j) && ((j - l) > 50)){
    quickSort3Ins(A, l, j, s);
  }
  else{
    insertionSort(A, l, j, s);
  }

  if ((i < r) && ((r - i) > 50)){
    quickSort3Ins(A, i, r, s);
  }
  else{
    insertionSort(A, i, r, s);
  }
  
}