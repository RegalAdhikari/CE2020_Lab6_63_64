#ifndef GRAPH_H
#define GRAPH_H
#include "node.h"

class Graph
{
public:
  // constructor
  Graph(bool isDirected);

  Graph();

  bool isDirected;
  bool isEmpty();
  void addVertex(int newVertex);
  void addEdge(int vertex1, int vertex2);
  void removeVertex(int vertex);
  void removeEdge(int vertex1, int vertex2);
  void numVertices();
  int numEdge();
  int inDegree(int vertex);
  int outDegree(int vertex);
  int degree(int vertex);
  void neighbors(int vertex);
  bool neighbor(int vertex1, int vertex2);
  void printGraph();

  Node *head;
};

#endif