// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }
  static void EmptySeperatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print(0), std::string(""));
  }

public:
  static void RunTest() {
    BarSeparatorTest();
    EmptySeperatorTest();
  }
};

class TmTypingTestSuite
{
private:
  static void TypingDeletingAtEndTest() {
    TypingMachine tm;
    tm.TypeKey('a');
    tm.TypeKey('b');
    tm.TypeKey('c');
    ASSERT_EQ(tm.Print('|'), std::string("abc|"));
    tm.EraseKey();
    ASSERT_EQ(tm.Print('$'), std::string("ab$"));
    tm.EraseKey();
    tm.EraseKey();
    tm.EraseKey(); // one more
    ASSERT_EQ(tm.Print('#'), std::string("#"));
  }
  static void TypingAtMiddleTest() {
    TypingMachine tm;
    tm.TypeKey('a');
    tm.TypeKey('b');
    tm.TypeKey('c');
    tm.LeftKey();
    tm.LeftKey();
    tm.TypeKey('e');
    ASSERT_EQ(tm.Print('|'), std::string("ae|bc"));
    tm.RightKey();
    tm.EraseKey();
    ASSERT_EQ(tm.Print(0), std::string("aec"));
    tm.HomeKey();
    tm.EraseKey(); // key at boundary
    tm.TypeKey('1');
    tm.EndKey();
    tm.TypeKey('q');
    ASSERT_EQ(tm.Print(0), std::string("1aecq"));
  }

  static void TypingConstraintTest() {
    TypingMachine tm;
    tm.TypeKey(31);
    tm.TypeKey(127);
    ASSERT_EQ(tm.Print('|'), std::string("|"));
    for (int i = 0; i < 105; i++) {
      tm.TypeKey('a');
    }
    std::string long_a = std::string(100, 'a');
    ASSERT_EQ(tm.Print(0), long_a);
  }
public:
  static void RunTest() {
    TypingDeletingAtEndTest();
    TypingAtMiddleTest();
    TypingConstraintTest();
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  TmTypingTestSuite::RunTest();
}