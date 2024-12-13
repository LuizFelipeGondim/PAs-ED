#include "listaAdjacencia.hpp"

ListaAdjacencia::ListaAdjacencia() : 
  quantVertices(0), 
  quantArestas(0), 
  head(nullptr){};

ListaAdjacencia::~ListaAdjacencia(){
  while (head != nullptr) {
    Vertices* temp = head;
    head = head->proximo;
    delete temp;
  }
};

void ListaAdjacencia::InsereVertice() {

  if (head == nullptr) {
    Vertices* novoVertice = new Vertices(quantVertices);
    quantVertices++;
    head = novoVertice;
    return;
  }

  Vertices* atual = head;

  while (atual->proximo != nullptr) {
    atual = atual->proximo;
  }

  Vertices* novoVertice = new Vertices(quantVertices);
  quantVertices++;
  atual->proximo = novoVertice;
}

void ListaAdjacencia::InsereAresta(int v, int w) {
  Vertices* atual = head;

  while (atual != nullptr) {
    if (atual->vertice == v) {
      atual->arestas.push_back(w);

      if (v < w)
        quantArestas++;

      break;
    }

    atual = atual->proximo;
  }
}

int ListaAdjacencia::GrauMinimo() {
  Vertices* atual = head;
  int gmin = quantVertices;

  while (atual != nullptr) {
    if ((int) atual->arestas.size() < gmin)
      gmin = atual->arestas.size();

    atual = atual->proximo;
  }

  return gmin;
}

int ListaAdjacencia::GrauMaximo() {
  Vertices* atual = head;
  int gmax = 0;

  while (atual != nullptr) {
    if ((int) atual->arestas.size() > gmax)
      gmax = atual->arestas.size();

    atual = atual->proximo;
  }

  return gmax;
}

void ListaAdjacencia::ImprimeVizinhos(int v) {
  Vertices* atual = head;

  while (atual != nullptr) {
    if (atual->vertice == v)
      for (const auto& aresta : atual->arestas)
        std::cout << aresta << " ";

    atual = atual->proximo;
  }

  std::cout << std::endl;
}