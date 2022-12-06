// test program to test the graph

#include <iostream>
#include <vector>
#include "./include/graph.h"
#include "./include/graph.cpp"

int main()
{
  // new graph
  Graph graph(false);

  // add vertices
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);
  graph.addVertex(4);
  graph.addVertex(5);
  graph.addVertex(6);
  graph.addVertex(7);
  graph.addVertex(8);
  graph.addVertex(9);
  graph.addVertex(10);
  cout << "--------------------------------" << endl;
  cout << "Vertices added" << endl;
  graph.numVertices();
  graph.numEdge();

  // add edges
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(1, 7);
  graph.addEdge(2, 5);
  graph.addEdge(2, 6);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);
  graph.addEdge(3, 5);
  graph.addEdge(4, 5);
  graph.addEdge(5, 6);
  graph.addEdge(5, 7);
  graph.addEdge(6, 7);
  graph.addEdge(7, 8);
  graph.addEdge(7, 9);

  // print the graph
  graph.printGraph();

  // remove edges
  cout << "--------------------------------" << endl;
  cout << "After removing: " << endl;
  graph.removeVertex(5);
  graph.removeVertex(3);
  graph.removeVertex(2);
  graph.removeEdge(6, 7);
  graph.printGraph();
  graph.numVertices();
  graph.numEdge();

  // get the degree of a vertex
  cout << "--------------------------------" << endl;
  cout << "Degree of vertices: " << endl;
  cout << "InDegree of vertex 1: " << graph.inDegree(1) << endl;
  cout << "OutDegree of vertex 1: " << graph.outDegree(1) << endl;
  cout << "Degree of vertex 1: " << graph.degree(1) << endl;
  cout << "InDegree of vertex 4: " << graph.inDegree(4) << endl;
  cout << "OutDegree of vertex 4: " << graph.outDegree(4) << endl;
  cout << "Degree of vertex 4: " << graph.degree(4) << endl;

  // get all neighbors of a vertex
  cout << "--------------------------------" << endl;
  cout << "Neighbors of vertex" << endl;
  graph.neighbors(1);
  graph.neighbors(4);
  graph.neighbors(7);

  // check if two vertices are adjacent
  cout << "--------------------------------" << endl;
  cout << "Check if two vertices are adjacent" << endl;
  cout << "Is 1 and 2 adjacent? " << graph.neighbor(1, 2) << endl;
  cout << "Is 1 and 4 adjacent? " << graph.neighbor(1, 4) << endl;
  cout << "Is 1 and 7 adjacent? " << graph.neighbor(1, 7) << endl;
  cout << "Is 4 and 5 adjacent? " << graph.neighbor(4, 5) << endl;

  cout << "--------------------------------" << endl;
  cout << "Check if the graph is directed" << endl;
  cout << "Is the graph directed? " << graph.isDirected << endl;

  return 0;
}