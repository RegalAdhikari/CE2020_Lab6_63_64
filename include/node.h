#ifndef NODE_H
#define NODE_H

class Node
{
public:
  int data;
  Node *vertex;
  Node *neighbor;

  Node()
  {
    vertex = nullptr;
    neighbor = nullptr;
  }

  Node(int data)
  {
    this->data = data;
    vertex = nullptr;
    neighbor = nullptr;
  }
};

#endif