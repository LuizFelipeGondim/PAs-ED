#include <iostream>
#include <vector>

struct Vertices {
  int vertice;
  std::vector<int> arestas;
  Vertices* proximo;

  Vertices(int vertice) : vertice(vertice){};
};


#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP 

class ListaAdjacencia{
  public:
    int quantVertices;
    int quantArestas;

    ListaAdjacencia();
    ~ListaAdjacencia();

    void InsereVertice();
    void InsereAresta(int v, int w);

    int GrauMinimo();
    int GrauMaximo();

    void ImprimeVizinhos(int v);
      
  private:
    Vertices* head;
};

#endif