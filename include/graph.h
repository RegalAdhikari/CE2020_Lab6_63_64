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
  int indegree(int vertex);
  int outdegree(int vertex);
  int degree(int vertex);
  void neighbours(int vertex);
  bool neighbour(int vertex1, int vertex2);
  void printGraph();

  Node *head;
};

#endif