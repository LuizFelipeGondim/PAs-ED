#include <iostream>
#include "tree.hpp"

int main () {
  Tree tree;
  int n, value;
  char operation;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> operation >> value;

    if (operation == 'i') {
      tree.insert(value);
    } else {
      tree.remove(value);
    }
  }

  tree.printPreOrder();
  tree.printInOrder();
  tree.printPostOrder();
  
  return 0;
}