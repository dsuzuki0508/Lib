#include <gtest/gtest.h>
#include "ModInt.h"
using namespace std;

TEST(ModIntTestSuite, ConstructorTest){
  ASSERT_TRUE(new ModInt<1000000007>());
  ASSERT_TRUE(new ModInt<1000000007>(1));
}


TEST(ModIntTestSuite, EqualToTest){
  ModInt<1000000007> n(0),m(0);
  EXPECT_EQ(n, m);

  EXPECT_EQ(n, 0);
  EXPECT_EQ(n, 0u);
  EXPECT_EQ(n, 0ll);
  EXPECT_EQ(n, 0ull);

  EXPECT_EQ(0,n);
  EXPECT_EQ(0u,n);
  EXPECT_EQ(0ll,n);
  EXPECT_EQ(0ull,n);
    
  EXPECT_EQ(n, ModInt<1000000007>(0));

  EXPECT_EQ(n, 1000000007);
  EXPECT_EQ(n, 1000000007u);
  EXPECT_EQ(n, 1000000007ll);
  EXPECT_EQ(n, 1000000007ull);

  EXPECT_EQ(1000000007,n);
  EXPECT_EQ(1000000007u,n);
  EXPECT_EQ(1000000007ll,n);
  EXPECT_EQ(1000000007ull,n);
    
  EXPECT_EQ(n, ModInt<1000000007>(1000000007));
}

TEST(ModIntTestSuite, IncrementTest){
  {
    ModInt<1000000007> n(0);
    EXPECT_EQ(++n, 1);
    EXPECT_EQ(++n, 2);
    EXPECT_EQ(++n, 3);
  }
  {
    ModInt<1000000007> n(1000000005);
    EXPECT_EQ(++n, 1000000006);
    EXPECT_EQ(++n, 0);
    EXPECT_EQ(++n, 1);
  }
  {
    ModInt<1000000007> n(0);
    EXPECT_EQ(n++, 0);
    EXPECT_EQ(n++, 1);
    EXPECT_EQ(n++, 2);
  }
  {
    ModInt<1000000007> n(1000000005);
    EXPECT_EQ(n++, 1000000005);
    EXPECT_EQ(n++, 1000000006);
    EXPECT_EQ(n++, 0);
  }
}
  
TEST(ModIntTestSuite, DecrementTest){
  {
    ModInt<1000000007> n(1);
    EXPECT_EQ(--n, 0);
    EXPECT_EQ(--n, 1000000006);
    EXPECT_EQ(--n, 1000000005);
  }
  {
    ModInt<1000000007> n(1000000006);
    EXPECT_EQ(--n, 1000000005);
    EXPECT_EQ(--n, 1000000004);
    EXPECT_EQ(--n, 1000000003);
  }
  {
    ModInt<1000000007> n(1);
    EXPECT_EQ(n--, 1);
    EXPECT_EQ(n--, 0);
    EXPECT_EQ(n--, 1000000006);
  }
  {
    ModInt<1000000007> n(1000000006);
    EXPECT_EQ(n--, 1000000006);
    EXPECT_EQ(n--, 1000000005);
    EXPECT_EQ(n--, 1000000004);
  }
}
TEST(ModIntTestSuite, AdditionTest){
  ModInt<1000000007> n(0),m(10),l(1000000006);
  EXPECT_EQ(n+m			, 10);
  EXPECT_EQ(n+l			, 1000000006);
  EXPECT_EQ(m+n			, 10);
  EXPECT_EQ(m+l			, 9);
  EXPECT_EQ(l+n			, 1000000006);
  EXPECT_EQ(l+m			, 9);

  EXPECT_EQ(n+10		, 10);
  EXPECT_EQ(n+1000000006	, 1000000006);
  EXPECT_EQ(m+0			, 10);
  EXPECT_EQ(m+1000000006	, 9);
  EXPECT_EQ(l+0			, 1000000006);
  EXPECT_EQ(l+10		, 9);

  EXPECT_EQ(0+m			, 10);
  EXPECT_EQ(0+l			, 1000000006);
  EXPECT_EQ(10+n		, 10);
  EXPECT_EQ(10+l		, 9);
  EXPECT_EQ(1000000006+n	, 1000000006);
  EXPECT_EQ(1000000006+m	, 9);
}  
TEST(ModIntTestSuite, SubtractionTest){
  ModInt<1000000007> n(0), m(10), l(1000000006);
  EXPECT_EQ(n-m			, 999999997);
  EXPECT_EQ(n-l			, 1);
  EXPECT_EQ(m-n			, 10);
  EXPECT_EQ(m-l			, 11);
  EXPECT_EQ(l-n			, 1000000006);
  EXPECT_EQ(l-m			, 999999996);

  EXPECT_EQ(n-10		, 999999997);
  EXPECT_EQ(n-1000000006	, 1);
  EXPECT_EQ(m-0			, 10);
  EXPECT_EQ(m-1000000006	, 11);
  EXPECT_EQ(l-0			, 1000000006);
  EXPECT_EQ(l-10		, 999999996);

  EXPECT_EQ(0-m			, 999999997);
  EXPECT_EQ(0-l			, 1);
  EXPECT_EQ(10-n		, 10);
  EXPECT_EQ(10-l		, 11);
  EXPECT_EQ(1000000006-n	, 1000000006);
  EXPECT_EQ(1000000006-m	, 999999996);
}  
TEST(ModIntTestSuite, MultiplicationTest){
  ModInt<1000000007> n(0), m(10), l(1000000006);
  EXPECT_EQ(n*m			, 0);
  EXPECT_EQ(n*l			, 0);
  EXPECT_EQ(m*n			, 0);
  EXPECT_EQ(m*l			, 999999997);
  EXPECT_EQ(l*n			, 0);
  EXPECT_EQ(l*m			, 999999997);

  EXPECT_EQ(n*10		, 0);
  EXPECT_EQ(n*1000000006	, 0);
  EXPECT_EQ(m*0			, 0);
  EXPECT_EQ(m*1000000006	, 999999997);
  EXPECT_EQ(l*0			, 0);
  EXPECT_EQ(l*10		, 999999997);

  EXPECT_EQ(0*m			, 0);
  EXPECT_EQ(0*l			, 0);
  EXPECT_EQ(10*n		, 0);
  EXPECT_EQ(10*l		, 999999997);
  EXPECT_EQ(1000000006*n	, 0);
  EXPECT_EQ(1000000006*m	, 999999997);
}
/* TODO
TEST(ModIntTestSuite, DivisionTest){
  ModInt<1000000007> n(0), m(10), l(1000000006);
  EXPECT_EQ(n/m			, 0);
  EXPECT_EQ(n/l			, 0);
  ASSERT_ANY_THROW(m/n          );
  EXPECT_EQ(m/l			, 999999997);
  ASSERT_ANY_THROW(l/n          );
  EXPECT_EQ(l/m			, 300000002);

  EXPECT_EQ(n/10		, 0);
  EXPECT_EQ(n/1000000006	, 0);
  ASSERT_ANY_THROW(m/0          );
  EXPECT_EQ(m/1000000006	, 999999997);
  ASSERT_ANY_THROW(l/0          );
  EXPECT_EQ(l/10		, 999999997);

  EXPECT_EQ(0/m			, 0);
  EXPECT_EQ(0/l			, 0);
  EXPECT_EQ(10/n		, 0);
  EXPECT_EQ(10/l		, 999999997);
  EXPECT_EQ(1000000006/n	, 0);
  EXPECT_EQ(1000000006/m	, 999999997);
}  
TEST(ModIntTestSuite, AdditionAssignmentTest){
  {
    ModInt<1000000007> n(0);
    EXPECT_EQ(n+=0,0);
    EXPECT_EQ(n+=1,1);
    EXPECT_EQ(n+=2,3);
    EXPECT_EQ(n+=1000000007,3);
  }
}
TEST(ModIntTestSuite, SubtractionAssignmentTest){
  {
    ModInt<1000000007> n(1000000006);
    EXPECT_EQ(n-=0,1000000006);
    EXPECT_EQ(n-=1,1000000005);
    EXPECT_EQ(n-=2,1000000003);
    EXPECT_EQ(n-=1000000007,1000000003);
  }
}
TEST(ModIntTestSuite, MultiplicationAssignmentTest){
  {
    ModInt<1000000007> n(1);
    EXPECT_EQ(n*=1,1);
    EXPECT_EQ(n*=2,2);
    EXPECT_EQ(n*=3,6);
    EXPECT_EQ(n*=1000000006,1000000001);
    EXPECT_EQ(n*=0,0);
  }
}
*/
  
