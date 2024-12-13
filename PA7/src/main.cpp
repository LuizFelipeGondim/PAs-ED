#include <iostream>
#include <getopt.h>
#include "graph.hpp"

int main(int argc,char ** argv) {
  Grafo grafo;
  int c, n, quantAresta, aresta;

  if ((c = getopt(argc, argv, "d;n;k"))){
    std::cin >> n;

    for (int i = 0; i < n; i++)
      grafo.InsereVertice();

    for (int i = 0; i < n; i++) {
      std::cin >> quantAresta;

      for (int j = 0; j < quantAresta; j++){
        std::cin >> aresta;
        grafo.InsereAresta(i, aresta);
      }
    }

    if (c == 'd') {
      std::cout << grafo.QuantidadeVertices() << std::endl;
      std::cout << grafo.QuantidadeArestas() << std::endl;
      std::cout << grafo.GrauMinimo() << std::endl;
      std::cout << grafo.GrauMaximo() << std::endl;

    } else if (c == 'n') {

      for (int i = 0; i < n; i++)
        grafo.ImprimeVizinhos(i);
        
    } else if (c == 'k') {

      int arestasK = n*(n-1)/2;

      if (grafo.QuantidadeArestas() < arestasK) {
        std::cout << "0" << std::endl;
      } else {
        std::cout << "1" << std::endl;
      }
    }
  }

  return 0;
}