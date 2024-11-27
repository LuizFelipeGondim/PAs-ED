#include <iostream>
#include "heap.hpp"

int main() {
  int n;
  
  std::cin >> n;
  Heap minHeap(n);

  for (int i = 0; i < n; ++i) {
    int number;
    std::cin >> number;
    minHeap.Inserir(number);
  }

  while (!minHeap.Vazio()) {
    std::cout << minHeap.Remover();
    if (!minHeap.Vazio()) std::cout << " ";
  }

  std::cout << std::endl;

  return 0;
}
