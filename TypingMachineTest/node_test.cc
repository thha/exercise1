// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }

public:
  static void RunTest() {
    SingleNodeTest();
  }
};

class NodeInsertionTestSuite
{
private:
  static void InsertPreviousTest() {
    Node *node = new Node('A');
    Node *prev = node->InsertPreviousNode('P');

    ASSERT_EQ(node->GetPreviousNode(), prev);
    ASSERT_EQ(prev->GetNextNode(), node);
    ASSERT_TRUE(node->GetNextNode() == nullptr);
    ASSERT_TRUE(prev->GetPreviousNode() == nullptr);

    delete node;
    delete prev;
  }
  static void InsertNextTest() {
    Node *node = new Node('A');
    Node *next = node->InsertNextNode('N');

    ASSERT_EQ(node->GetNextNode(), next);
    ASSERT_EQ(next->GetPreviousNode(), node);
    ASSERT_TRUE(node->GetPreviousNode() == nullptr);
    ASSERT_TRUE(next->GetNextNode() == nullptr);

    delete node;
    delete next;
  }
  static void InsertMiddleTest() {
    Node *node = new Node('A');
    node->InsertNextNode('B');
    Node *prev = node->InsertPreviousNode('C');
    Node *target = prev->InsertNextNode('K');

    ASSERT_EQ(target->GetNextNode()->GetData(), 'A');
    ASSERT_EQ(target->GetPreviousNode()->GetData(), 'C');
  }
public:
  static void RunTest() {
    InsertPreviousTest();
    InsertNextTest();
    InsertMiddleTest();
  }
};

class NodeEraseTestSuite
{
private:
  static void ErasePreviousTest() {
    Node *node = new Node('A');
    node->InsertPreviousNode('P');

    bool is_success = node->ErasePreviousNode();
    ASSERT_TRUE(is_success);
    ASSERT_TRUE(node->GetPreviousNode() == nullptr);
    bool is_failure = node->ErasePreviousNode();
    ASSERT_FALSE(is_failure);
    ASSERT_FALSE(node->EraseNextNode());

    delete node;
  }

  static void EraseNextTest() {
    Node *node = new Node('A');
    node->InsertNextNode('N');

    bool is_success = node->EraseNextNode();
    ASSERT_TRUE(is_success);
    ASSERT_TRUE(node->GetNextNode() == nullptr);
    bool is_failure = node->EraseNextNode();
    ASSERT_FALSE(is_failure);
    ASSERT_FALSE(node->ErasePreviousNode());

    delete node;
  }

public:
  static void RunTest() {
    ErasePreviousTest();
    EraseNextTest();
  }
};


void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  NodeInsertionTestSuite::RunTest();
  NodeEraseTestSuite::RunTest();
}
