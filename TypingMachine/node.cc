// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
  this->data = data;
  this->prevNode = this->nextNode = nullptr;
}

char Node::GetData() {
  return this->data;
}

Node* Node::GetPreviousNode() {
  return this->prevNode;
}

Node* Node::GetNextNode() {
  return this->nextNode;
}

Node* Node::InsertPreviousNode(char data) {
  Node* newNode = new Node(data);
  newNode->InsertBetween(this->prevNode, this);
  return newNode;
}

Node* Node::InsertNextNode(char data) {
  Node* newNode = new Node(data);
  newNode->InsertBetween(this, this->nextNode);
  return newNode;
}

bool Node::ErasePreviousNode() {
  if (this->prevNode) {
    Node::Erase(this->prevNode);
    return true;
  }
  return false;
}

bool Node::EraseNextNode() {
  if (this->nextNode) {
    Node::Erase(this->nextNode);
    return true;
  }
  return false;
}

void Node::InsertBetween(Node* prev, Node* next) {
  if (prev != nullptr) {
    this->prevNode = prev;
    prev->nextNode = this;
  }
  if (next != nullptr) {
    this->nextNode = next;
    next->prevNode = this;
  }
}

void Node::Erase(Node* node) {
  node->LinkBothSide();
  delete node;
}

void Node::LinkBothSide() {
  if (this->nextNode != nullptr) {
    this->nextNode->prevNode = this->prevNode;
  }
  if (this->prevNode != nullptr) {
    this->prevNode->nextNode = this->nextNode;
  }
}
