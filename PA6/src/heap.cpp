#include "heap.hpp"

Heap::Heap(int maxSize) : tamanho(0), data(new int[maxSize]) {};

Heap::~Heap() {
  delete[] data;
}

void Heap::Inserir(int x) {
  data[tamanho] = x;
  int i = tamanho;
  int p = GetAncestral(i); 

  while (i > 0 && data[i] < data[p]) {
    int temp = data[i];
    data[i] = data[p];
    data[p] = temp;
    i = p;
    p = GetAncestral(i);
  }

  tamanho++;
}

int Heap::Remover() {
  int x = data[0];
  data[0] = data[tamanho - 1];
  tamanho--;

  int i = 0;

  while (true) {
    int esq = GetSucessorEsq(i);
    int dir = GetSucessorDir(i);

    if (esq >= tamanho) break;

    int s = esq;
    if (dir < tamanho && data[dir] < data[esq])
      s = dir;

    if (data[i] <= data[s]) break;

    int temp = data[i];
    data[i] = data[s];
    data[s] = temp;

    i = s;
  }

  return x;
}

bool Heap::Vazio() {
  return tamanho == 0 ? true : false;
}

int Heap::GetAncestral(int posicao) {
  return (posicao-1)/2;
}

int Heap::GetSucessorEsq(int posicao) {
  return 2*posicao+1;
}

int Heap::GetSucessorDir(int posicao) {
  return 2*posicao+2;
}