#include "tree.hpp"
#include <algorithm>

Tree::Tree() : root(nullptr) {}

Tree::~Tree() {
  clear(root);
}

void Tree::clear(Node* node) {
  if(node) {
    clear(node->left);
    clear(node->right);
    delete node;
  }
}

int Tree::getHeight(Node* node) { return node ? node->height : 0; }

int Tree::getBalance(Node* node) {
  return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

void Tree::updateHeight(Node* node) {
  if (node)
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

Node* Tree::rotateRight(Node* y) {
  Node* x = y->left;
  Node* T2 = x->right;

  x->right = y;
  y->left = T2;

  updateHeight(y);
  updateHeight(x);

  return x;
}

Node* Tree::rotateLeft(Node* x) {
  Node* y = x->right;
  Node* T2 = y->left;

  y->left = x;
  x->right = T2;

  updateHeight(x);
  updateHeight(y);

  return y;
}

Node* Tree::balance(Node* node) {
  updateHeight(node);

  int balanceFactor = getBalance(node);

  if (balanceFactor > 1) {
    if (getBalance(node->left) < 0) 
      node->left = rotateLeft(node->left);
  
    return rotateRight(node);
  }
  if (balanceFactor < -1) {
    if (getBalance(node->right) > 0) 
      node->right = rotateRight(node->right);
    
    return rotateLeft(node);
  }

  return node;
}


Node* Tree::insert(Node* node, int key) {
  if (!node) return new Node(key);

  if (key < node->key) {
    node->left = insert(node->left, key);
  } else if (key > node->key) {
    node->right = insert(node->right, key);
  } else {
    return node;
  }

  return balance(node);
}

void Tree::insert(int key) { root = insert(root, key); }

Node* Tree::findMin(Node* node) {
  while (node->left) node = node->left;
  return node;
}

Node* Tree::remove(Node* node, int key) {
  if (!node) return nullptr;

  if (key < node->key) {
    node->left = remove(node->left, key);
  } else if (key > node->key) {
    node->right = remove(node->right, key);
  } else {
    if (!node->left || !node->right) {
      Node* temp = node->left ? node->left : node->right;
      delete node;
      return temp;
    } else {
      Node* temp = findMin(node->right);
      node->key = temp->key;
      node->right = remove(node->right, temp->key);
    }
  }

  return balance(node);
}

void Tree::remove(int key) { root = remove(root, key); }

void Tree::preOrder(Node* node) {
  if (node) {
    std::cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
  }
}

void Tree::printPreOrder() {
  preOrder(root);
  std::cout << std::endl;
}

void Tree::inOrder(Node* node) {
  if (node) {
    inOrder(node->left);
    std::cout << node->key << " ";
    inOrder(node->right);
  }
}

void Tree::printInOrder() {
  inOrder(root);
  std::cout << std::endl;
}

void Tree::postOrder(Node* node) {
  if (node) {
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->key << " ";
  }
}

void Tree::printPostOrder() {
  postOrder(root);
  std::cout << std::endl;
}
