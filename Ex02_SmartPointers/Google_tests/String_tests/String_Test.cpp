#include <gtest/gtest.h>
#include "MyString.h"
#include "String_my.h"


TEST(StringTest, DefaultConstructor) {
  String s;
  EXPECT_EQ(s.get(0), '\0');
}

TEST(StringTest, CStrConstructor) {
  String s("Hello");
  EXPECT_EQ(s.get(0), 'H');
  EXPECT_EQ(s.get(4), 'o');
}

TEST(StringTest, CopyConstructor) {
  String s1("Hello");
  String s2(s1);
  EXPECT_EQ(s2.get(0), 'H');
  EXPECT_EQ(s2.get(4), 'o');
  EXPECT_EQ(s1.use_count(), 2);
  EXPECT_EQ(s2.use_count(), 2);
  EXPECT_EQ(s1.get_raw_ptr(), s2.get_raw_ptr());
}

TEST(StringTest, AssignmentOperator) {
  String s1("Hello");
  String s2 = s1;
  EXPECT_EQ(s2.get(0), 'H');
  EXPECT_EQ(s2.get(4), 'o');
  EXPECT_EQ(s1.use_count(), 2);
  EXPECT_EQ(s2.use_count(), 2);
  EXPECT_EQ(s1.get_raw_ptr(), s2.get_raw_ptr());
}

TEST(StringTest, SetMethod) {
  String s("Hello");
  s.set(1, 'a');
  EXPECT_EQ(s.get(1), 'a');
}

TEST(StringTest, GetMethod) {
  String s("Hello");
  EXPECT_EQ(s.get(1), 'e');
}

TEST(StringTest, OperatorPlus) {
  String s1("Hello");
  String s2("World");
  String s3 = s1 + s2;
  EXPECT_EQ(s3.get(5), 'W');
  EXPECT_EQ(s3.get(9), 'd');
}

TEST(StringTest, OperatorOutputStream) {
  String s("Hello");
  std::ostringstream os;
  os << s;
  EXPECT_EQ(os.str(), "Hello");
}

TEST(StringTest, CopyOnChangeSemantics) {
  String s1("Hello");
  String s2 = s1;
  s2.set(1, 'a');
  EXPECT_EQ(s1.get(1), 'e');
  EXPECT_EQ(s2.get(1), 'a');
  EXPECT_NE(s1.get_raw_ptr(), s2.get_raw_ptr());
  EXPECT_EQ(s1.use_count(), 1);
  EXPECT_EQ(s2.use_count(), 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
