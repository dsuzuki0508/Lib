#include <gtest/gtest.h>
#include "BinaryIndexedTree.h"
using namespace std;

TEST(BinaryIndexedTreeTestSuite, ConstructorTest){
  ASSERT_TRUE(new BinaryIndexedTree<int>());
  ASSERT_TRUE(new BinaryIndexedTree<int>(10));
}


TEST(BinaryIndexedTreeTestSuite, MaxFlowTest){
  {
    BinaryIndexedTree<int> bit;
    bit.add(0, 5);
    bit.add(1, 3);
    bit.add(2, 7);
    bit.add(3, 9);
    bit.add(4, 6);
    bit.add(5, 4);
    bit.add(6, 1);
    bit.add(7, 2);
    EXPECT_EQ( bit.sum(0, 1), 5);
    EXPECT_EQ( bit.sum(0, 2), 8);
    EXPECT_EQ( bit.sum(0, 3), 15);
    EXPECT_EQ( bit.sum(0, 4), 24);
    EXPECT_EQ( bit.sum(0, 5), 30);
    EXPECT_EQ( bit.sum(0, 6), 34);
    EXPECT_EQ( bit.sum(0, 7), 35);
    EXPECT_EQ( bit.sum(0, 8), 37);

  }

  {
    BinaryIndexedTree<int> bit(10);

    bit.add(4, 12);
    bit.add(1, 8);
    EXPECT_EQ( bit.sum(7, 8), 0 );
    bit.add(2, 1);
    bit.add(6, 8);
    bit.add(1, 16);
    bit.add(3, 17);
    bit.add(3, 18);
    EXPECT_EQ( bit.sum(4, 11), 20 );
    EXPECT_EQ( bit.sum(5, 11), 8 );
    bit.add(8, 40);
    EXPECT_EQ( bit.sum(1, 7), 80 );
    EXPECT_EQ( bit.sum(1, 4), 60 );
    EXPECT_EQ( bit.sum(2, 5), 48 );
    EXPECT_EQ( bit.sum(7, 8), 0 );
    bit.add(10, 47);
    bit.add(2, 40);
    EXPECT_EQ( bit.sum(5, 7), 8 );
    bit.add(1, 27);
    EXPECT_EQ( bit.sum(4, 6), 12 );
    EXPECT_EQ( bit.sum(1, 11), 234 );
    EXPECT_EQ( bit.sum(3, 8), 55 );
    EXPECT_EQ( bit.sum(1, 5), 139 );
    bit.add(10, 5);
    bit.add(10, 27);
    bit.add(8, 24);
    EXPECT_EQ( bit.sum(7, 11), 143 );
    EXPECT_EQ( bit.sum(4, 7), 20 );
    bit.add(7, 9);
    EXPECT_EQ( bit.sum(3, 7), 55 );
    bit.add(9, 1);
    EXPECT_EQ( bit.sum(1, 9), 220 );
    bit.add(7, 13);
    bit.add(8, 42);
    EXPECT_EQ( bit.sum(3, 10), 184 );
    bit.add(1, 30);
    EXPECT_EQ( bit.sum(2, 3), 41 );
    EXPECT_EQ( bit.sum(5, 9), 136 );
    bit.add(6, 38);
    bit.add(9, 37);
    bit.add(8, 13);
    bit.add(6, 0);
    EXPECT_EQ( bit.sum(3, 5), 47 );
    EXPECT_EQ( bit.sum(4, 9), 199 );
    bit.add(1, 40);
    bit.add(9, 26);
    bit.add(8, 8);
    bit.add(9, 38);
    bit.add(4, 38);
    EXPECT_EQ( bit.sum(2, 8), 194 );

  }

}

