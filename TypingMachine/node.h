// Copyright 2018 <Author>

#ifndef NODE_H_
#define NODE_H_

class Node {
 public:
  explicit Node(char data);
  char GetData();
  Node* InsertPreviousNode(char data);
  Node* InsertNextNode(char data);
  Node* GetPreviousNode();
  Node* GetNextNode();
  bool ErasePreviousNode();
  bool EraseNextNode();

 private:
  static void Erase(Node* node);

  void InsertBetween(Node* prev, Node*next);
  void LinkBothSide();

  char data;
  Node* prevNode;
  Node* nextNode;
};

#endif  // NODE_H_
