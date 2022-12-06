// adjacency list representation of a graph with direction

#include <iostream>
#include "node.h"

using namespace std;

class Graph
{
public:
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

  Node *head;
};

Graph::Graph(bool isDirected)
{
  this->isDirected = isDirected;
  head = nullptr;
}

Graph::Graph()
{
  this->isDirected = false;
  head = nullptr;
}

bool Graph::isEmpty()
{
  return head == nullptr;
}

void Graph::addVertex(int newVertex)
{
  Node *newNode = new Node(newVertex);
  if (isEmpty())
  {
    head = newNode;
  }
  else
  {
    Node *temp = head;
    while (temp->vertex != nullptr)
    {
      temp = temp->vertex;
    }
    temp->vertex = newNode;
  }
}

void Graph::addEdge(int vertex1, int vertex2)
{
  Node *temp = head;
  while (temp->data != vertex1)
  {
    temp = temp->vertex;
  }
  Node *newNode = new Node(vertex2);
  if (temp->neighbor == nullptr)
  {
    temp->neighbor = newNode;
  }
  else
  {
    Node *temp2 = temp->neighbor;
    while (temp2->neighbor != nullptr)
    {
      temp2 = temp2->neighbor;
    }
    temp2->neighbor = newNode;
  }
  // if the graph is directed, add to the other vertex as well
  if (isDirected)
  {
    Node *temp = head;
    while (temp->data != vertex2)
    {
      temp = temp->vertex;
    }
    Node *newNode = new Node(vertex1);
    if (temp->neighbor == nullptr)
    {
      temp->neighbor = newNode;
    }
    else
    {
      Node *temp2 = temp->neighbor;
      while (temp2->neighbor != nullptr)
      {
        temp2 = temp2->neighbor;
      }
      temp2->neighbor = newNode;
    }
  }
}

// print graph with vertex and its neighbours
void Graph::printGraph()
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " -> ";
    Node *temp2 = temp->neighbor;
    while (temp2 != nullptr)
    {
      cout << temp2->data << " ";
      temp2 = temp2->neighbor;
    }
    cout << endl;
    temp = temp->vertex;
  }
}
