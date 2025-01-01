#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

struct Node {
  int key;
  int height;
  Node* left;
  Node* right;

  Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class Tree {
private:
  Node* root;

  int getHeight(Node* node);
  int getBalance(Node* node);
  void updateHeight(Node* node);
  Node* rotateRight(Node* y);
  Node* rotateLeft(Node* x);
  Node* balance(Node* node);
  Node* insert(Node* node, int key);
  Node* remove(Node* node, int key);
  Node* findMin(Node* node);
  void preOrder(Node* node);
  void inOrder(Node* node);
  void postOrder(Node* node);
  void clear(Node* node);

public:
  Tree();
  ~Tree();
  void insert(int key);
  void remove(int key);
  void printPreOrder();
  void printInOrder();
  void printPostOrder();
};

#endif
