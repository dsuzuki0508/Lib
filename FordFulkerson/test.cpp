#include <gtest/gtest.h>
#include "FordFulkerson.h"
using namespace std;

TEST(FordFulkersonTestSuite, ConstructorTest){
  string test="test";
  ASSERT_TRUE(new FordFulkerson());
  ASSERT_TRUE(new FordFulkerson(10));
}


TEST(FordFulkersonTestSuite, MaxFlowTest){
  {
    FordFulkerson ff;
    ff.add_edge(0, 2, 17);
    ff.add_edge(0, 3, 13);
    ff.add_edge(0, 4, 8);
    ff.add_edge(0, 7, 19);
    ff.add_edge(0, 9, 1);
    ff.add_edge(0, 12, 3);
    ff.add_edge(1, 3, 0);
    ff.add_edge(1, 4, 19);
    ff.add_edge(1, 5, 10);
    ff.add_edge(1, 10, 13);
    ff.add_edge(2, 1, 19);
    ff.add_edge(2, 6, 18);
    ff.add_edge(2, 10, 12);
    ff.add_edge(3, 4, 11);
    ff.add_edge(3, 11, 11);
    ff.add_edge(3, 12, 18);
    ff.add_edge(5, 0, 12);
    ff.add_edge(5, 9, 14);
    ff.add_edge(6, 10, 9);
    ff.add_edge(7, 1, 7);
    ff.add_edge(7, 3, 7);
    ff.add_edge(8, 6, 4);
    ff.add_edge(9, 7, 1);
    ff.add_edge(9, 12, 1);
    ff.add_edge(10, 3, 13);
    ff.add_edge(10, 7, 5);
    ff.add_edge(10, 12, 14);
    ff.add_edge(11, 9, 14);
    EXPECT_EQ( ff.max_flow(0, 12), 36 );
  }
  {
    FordFulkerson ff(28);
    ff.add_edge(0, 4, 7);
    ff.add_edge(0, 9, 3);
    ff.add_edge(0, 16, 29);
    ff.add_edge(1, 20, 15);
    ff.add_edge(2, 14, 18);
    ff.add_edge(3, 1, 4);
    ff.add_edge(3, 4, 2);
    ff.add_edge(3, 17, 1);
    ff.add_edge(4, 2, 24);
    ff.add_edge(4, 13, 19);
    ff.add_edge(4, 14, 15);
    ff.add_edge(4, 23, 15);
    ff.add_edge(4, 24, 5);
    ff.add_edge(4, 27, 9);
    ff.add_edge(5, 16, 17);
    ff.add_edge(5, 22, 6);
    ff.add_edge(6, 15, 22);
    ff.add_edge(7, 4, 16);
    ff.add_edge(7, 6, 22);
    ff.add_edge(8, 12, 2);
    ff.add_edge(8, 14, 26);
    ff.add_edge(9, 2, 3);
    ff.add_edge(10, 3, 14);
    ff.add_edge(10, 12, 15);
    ff.add_edge(10, 21, 9);
    ff.add_edge(11, 4, 25);
    ff.add_edge(11, 5, 11);
    ff.add_edge(11, 23, 18);
    ff.add_edge(12, 2, 13);
    ff.add_edge(12, 3, 28);
    ff.add_edge(12, 9, 20);
    ff.add_edge(12, 15, 17);
    ff.add_edge(13, 20, 24);
    ff.add_edge(14, 23, 5);
    ff.add_edge(14, 25, 10);
    ff.add_edge(14, 27, 13);
    ff.add_edge(15, 7, 21);
    ff.add_edge(15, 14, 11);
    ff.add_edge(15, 17, 5);
    ff.add_edge(16, 7, 21);
    ff.add_edge(16, 14, 19);
    ff.add_edge(16, 24, 30);
    ff.add_edge(16, 27, 5);
    ff.add_edge(18, 17, 24);
    ff.add_edge(18, 20, 29);
    ff.add_edge(18, 24, 6);
    ff.add_edge(19, 10, 28);
    ff.add_edge(21, 1, 2);
    ff.add_edge(21, 8, 5);
    ff.add_edge(21, 16, 1);
    ff.add_edge(21, 20, 18);
    ff.add_edge(22, 8, 14);
    ff.add_edge(22, 21, 21);
    ff.add_edge(23, 5, 8);
    ff.add_edge(23, 18, 5);
    ff.add_edge(23, 26, 1);
    ff.add_edge(23, 27, 19);
    ff.add_edge(24, 2, 1);
    ff.add_edge(24, 10, 11);
    ff.add_edge(25, 12, 3);
    ff.add_edge(25, 15, 17);
    ff.add_edge(25, 20, 3);
    ff.add_edge(25, 23, 19);
    ff.add_edge(26, 16, 27);
    ff.add_edge(27, 18, 7);
    EXPECT_EQ( ff.max_flow(0, 27), 39 );
  }
}
