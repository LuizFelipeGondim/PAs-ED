#ifndef SORTUTILS_H
#define SORTUTILS_H

typedef struct sortperf {
    int cmp;
    int move;
    int calls;
} sortperf_t;

void resetcounter(sortperf_t *s);
void inccmp(sortperf_t *s, int num);
void incmove(sortperf_t *s, int num);
void inccalls(sortperf_t *s, int num);
void swap(int *xp, int *yp, sortperf_t *s);
void initVector(int *vet, int size);
void printVector(int *vet, int size);

#endif
