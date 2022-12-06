// test program to test the graph

#include <iostream>
#include <vector>
#include "../include/graph.h"
#include "../include/graph.cpp"

int main()
{
  // new graph
  Graph graph(true);

  // add vertices
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);
  graph.addVertex(4);

  // add edges
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);
}