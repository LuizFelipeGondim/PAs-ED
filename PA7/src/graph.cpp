#include "graph.hpp"

Grafo::Grafo(){};

Grafo::~Grafo(){};

void Grafo::InsereVertice() {
  vertices.InsereVertice();
}

void Grafo::InsereAresta(int v, int w) {
  vertices.InsereAresta(v, w);
}

int Grafo::QuantidadeVertices() {
  return vertices.quantVertices;
}

int Grafo::QuantidadeArestas() {
  return vertices.quantArestas;
}

int Grafo::GrauMinimo() {
  return vertices.GrauMinimo();
}

int Grafo::GrauMaximo() {
  return vertices.GrauMaximo();
}

void Grafo::ImprimeVizinhos(int v) {
  vertices.ImprimeVizinhos(v);
};