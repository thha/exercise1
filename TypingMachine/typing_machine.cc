// Copyright 2018 <Author>

#include "typing_machine.h"


TypingMachine::TypingMachine() {
  this->head = this->cursor = new Node(' ');
  this->length = 0;
}

void TypingMachine::HomeKey() {
  this->cursor = this->head;
}

void TypingMachine::EndKey() {
  Node* end;
  for (end = this->cursor; end->GetNextNode() != nullptr; end = end->GetNextNode());
  this->cursor = end;
}

void TypingMachine::LeftKey() {
  Node* prev = this->cursor->GetPreviousNode();
  if (prev != nullptr) {
    this->cursor = prev;
  }
}

void TypingMachine::RightKey() {
  Node* next = this->cursor->GetNextNode();
  if (next != nullptr) {
    this->cursor = next;
  }
}

bool TypingMachine::TypeKey(char key) {
  if (key < 32 || key > 126) {
    return false;
  }
  if (this->length >= 100) {
    return false;
  }
  Node *newNode = this->cursor->InsertPreviousNode(key);
  this->length++;
  if (this->cursor == this->head) {
    this->head = newNode;
  }
  return true;
}

bool TypingMachine::EraseKey() {
  if (this->cursor->ErasePreviousNode()) {
    this->length--;
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
    if (node == this->cursor && separator != 0) {
      buffer.push_back(separator);
    }
    buffer.push_back(node->GetData());
  }
  return buffer;
}
