// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
  this->head = this->cursor = new Node(' ');
}

void TypingMachine::HomeKey() {
  this->cursor = this->head;
  return;
}

void TypingMachine::EndKey() {
  Node* end;
  for (end = this->cursor; end->GetNextNode() != nullptr; end = end->GetNextNode());
  this->cursor = end;
  return;
}

void TypingMachine::LeftKey() {
  Node* prev = this->cursor->GetPreviousNode();
  if (prev != nullptr) {
    this->cursor = prev;
  }
  return;
}

void TypingMachine::RightKey() {
  Node* next = this->cursor->GetNextNode();
  if (next != nullptr) {
    this->cursor = next;
  }
  return;
}

bool TypingMachine::TypeKey(char key) {
  Node *newNode = this->cursor->InsertPreviousNode(key);
  if (this->cursor == this->head) {
    this->head = newNode;
  }
  return true;
}

bool TypingMachine::EraseKey() {
  if (this->cursor->ErasePreviousNode()) {
    if (this->cursor->GetPreviousNode() == nullptr) {
      this->head = this->cursor;
    }
    return true;
  }
  return false;
}

std::string TypingMachine::Print(char separator) {
  std::string buffer;
  for (Node* node = this->head; node != nullptr; node = node->GetNextNode()) {
    if (node == this->cursor) {
      buffer.push_back(separator);
    }
    buffer.push_back(node->GetData());
  }
  return buffer;
}
