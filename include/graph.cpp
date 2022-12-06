// adjacency list representation of a graph with direction

#include <iostream>
#include "node.h"

using namespace std;

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
  // if the graph is undirected, add to the other vertex as well
  if (!isDirected)
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

void Graph::removeVertex(int vertex)
{
  Node *temp = head;
  Node *prev = nullptr;
  while (temp->data != vertex)
  {
    prev = temp;
    temp = temp->vertex;
  }
  if (prev == nullptr)
  {
    head = temp->vertex;
  }
  else
  {
    prev->vertex = temp->vertex;
  }
  delete temp;

  // remove all edges that contain the vertex
  Node *temp2 = head;
  while (temp2 != nullptr)
  {
    Node *temp3 = temp2->neighbor;
    Node *prev2 = nullptr;
    while (temp3 != nullptr)
    {
      if (temp3->data == vertex)
      {
        if (prev2 == nullptr)
        {
          temp2->neighbor = temp3->neighbor;
        }
        else
        {
          prev2->neighbor = temp3->neighbor;
        }
        delete temp3;
        temp3 = prev2;
      }
      prev2 = temp3;
      if (temp3 != nullptr)
      {
        temp3 = temp3->neighbor;
      }
    }
    temp2 = temp2->vertex;
  }
  cout << "Vertex " << vertex << " has been removed." << endl;
}

// remove edge from the graph with currentNeighbor
void Graph::removeEdge(int vertex1, int vertex2)
{
  Node *temp = head;
  while (temp->data != vertex1)
  {
    temp = temp->vertex;
  }
  Node *temp2 = temp->neighbor;
  Node *prev = nullptr;
  while (temp2->data != vertex2)
  {
    prev = temp2;
    temp2 = temp2->neighbor;
  }
  if (prev == nullptr)
  {
    temp->neighbor = temp2->neighbor;
  }
  else
  {
    prev->neighbor = temp2->neighbor;
  }
  delete temp2;

  // if the graph is undirected, remove the edge from the other vertex as well
  if (!isDirected)
  {
    Node *temp = head;
    while (temp->data != vertex2)
    {
      temp = temp->vertex;
    }
    Node *temp2 = temp->neighbor;
    Node *prev = nullptr;
    while (temp2->data != vertex1)
    {
      prev = temp2;
      temp2 = temp2->neighbor;
    }
    if (prev == nullptr)
    {
      temp->neighbor = temp2->neighbor;
    }
    else
    {
      prev->neighbor = temp2->neighbor;
    }
    delete temp2;
  }

  cout << "Edge from " << vertex1 << " to " << vertex2 << " has been removed." << endl;
}

void Graph::numVertices()
{
  Node *temp = head;
  int count = 0;
  while (temp != nullptr)
  {
    count++;
    temp = temp->vertex;
  }
  cout << "Number of vertices: " << count << endl;
}

// get the number of edges in graph
int Graph::numEdge()
{
  Node *temp = head;
  int count = 0;
  while (temp != nullptr)
  {
    Node *temp2 = temp->neighbor;
    while (temp2 != nullptr)
    {
      count++;
      temp2 = temp2->neighbor;
    }
    temp = temp->vertex;
  }
  return count;
}

// indegree of vertex
int Graph::inDegree(int vertex)
{
  Node *temp = head;
  int count = 0;
  while (temp != nullptr)
  {
    Node *temp2 = temp->neighbor;
    while (temp2 != nullptr)
    {
      if (temp2->data == vertex)
      {
        count++;
      }
      temp2 = temp2->neighbor;
    }
    temp = temp->vertex;
  }
  return count;
}

// outdegree of vertex
int Graph::outDegree(int vertex)
{
  Node *temp = head;
  int count = 0;
  while (temp != nullptr)
  {
    if (temp->data == vertex)
    {
      Node *temp2 = temp->neighbor;
      while (temp2 != nullptr)
      {
        count++;
        temp2 = temp2->neighbor;
      }
    }
    temp = temp->vertex;
  }
  return count;
}

// get all degree
int Graph::degree(int vertex)
{
  return inDegree(vertex) + outDegree(vertex);
}

// get all neighbors of vertex
void Graph::neighbors(int vertex)
{
  Node *temp = head;
  while (temp->data != vertex)
  {
    temp = temp->vertex;
  }
  Node *temp2 = temp->neighbor;
  cout << "Neighbors of vertex " << vertex << ": ";
  while (temp2 != nullptr)
  {
    cout << temp2->data << " ";
    temp2 = temp2->neighbor;
  }
  cout << endl;
}

// check if the two vertices are adjacent
bool Graph::neighbor(int vertex1, int vertex2)
{
  Node *temp = head;
  while (temp->data != vertex1)
  {
    temp = temp->vertex;
  }
  Node *temp2 = temp->neighbor;
  while (temp2 != nullptr)
  {
    if (temp2->data == vertex2)
    {
      return true;
    }
    temp2 = temp2->neighbor;
  }
  return false;
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