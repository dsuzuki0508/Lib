#include <gtest/gtest.h>
#include "RollingHash.h"
using namespace std;

TEST(RollingHashTestSuite, ConstructorTest){
  string test="test";
  ASSERT_TRUE(new RollingHash<1000000007>());
  ASSERT_TRUE(new RollingHash<1000000007>(test.begin(), test.end()));
  ASSERT_TRUE(new RollingHash<1000000007>(test));
  ASSERT_TRUE(new RollingHash());
  ASSERT_TRUE(new RollingHash(test.begin(), test.end()));
  ASSERT_TRUE(new RollingHash(test));
}


TEST(RollingHashTestSuite, HashTest){
  {
    string S = "babbcbacbbcccaccababbccbacbaccbacbbcccccaccaababcbccacabbbcbbbcbcbbcaabbbccbaaabbaaaaabcabbcaabacacaaccbbbaccbaacbbcaabacaaccbccbccabbccaacccabcccbcaaacbacbcbabbccacbaccaabacaacccaaaacaaaacacaabbcccaccbbaaabcababcbaacbbbcbabccaacbaccccaabbbbbcaabbcabcacabcccabbaabaaabcbcaacbbaabbbbcbbbbbabaccbcaccbcbbabccacccbbbbaacbcbaaaabaabcaaacbabaacbcbacaacaccbacabbacabcbccacbbaacacaccaccaccacccbabcbcabcabaccbcaacaaabaabcbacacacbcbcbaaabaccaaaacbbaccbcabacbbccaabcbaacaaabbacacbbcaacbbcbaaaacaabcabcbbccaacba";
    string T = "aaabaa";
    
    RollingHash rh(S), p(T);
    for(int i = 0;i+T.size()<=S.size();i++){
      if(i==321 || i==405){
	EXPECT_EQ( rh.hash(i, i+T.size()) , p.hash() );
      }else{
	EXPECT_NE( rh.hash(i, i+T.size()) , p.hash() );
      }
    }
  }
  {
      string S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      RollingHash<100> rh(S);

      EXPECT_EQ(rh.hash(  0,  9), 656667686970717273);
      EXPECT_EQ(rh.hash(  1, 10), 666768697071727374);
      EXPECT_EQ(rh.hash(  2, 11), 676869707172737475);
      EXPECT_EQ(rh.hash(  3, 12), 686970717273747576);
      EXPECT_EQ(rh.hash(  4, 13), 697071727374757677);
      EXPECT_EQ(rh.hash(  5, 14), 707172737475767778);
      EXPECT_EQ(rh.hash(  6, 15), 717273747576777879);
      EXPECT_EQ(rh.hash(  7, 16), 727374757677787980);
      EXPECT_EQ(rh.hash(  8, 17), 737475767778798081);
      EXPECT_EQ(rh.hash(  9, 18), 747576777879808182);
      EXPECT_EQ(rh.hash( 10, 19), 757677787980818283);
      EXPECT_EQ(rh.hash( 11, 20), 767778798081828384);
      EXPECT_EQ(rh.hash( 12, 21), 777879808182838485);
      EXPECT_EQ(rh.hash( 13, 22), 787980818283848586);
      EXPECT_EQ(rh.hash( 14, 23), 798081828384858687);
      EXPECT_EQ(rh.hash( 15, 24), 808182838485868788);
      EXPECT_EQ(rh.hash( 16, 25), 818283848586878889);
      EXPECT_EQ(rh.hash( 17, 26), 828384858687888990);
  }
}
TEST(RollingHashTestSuite, AppendTest){
  string S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
  {
    RollingHash<1000> rh1(S), rh2;
    for(const auto& e: S)rh2.append(e);

    for(int i = 0;i<(int)S.size();i++){
      for(int j = i;j<(int)S.size();j++){
	EXPECT_EQ(rh1.hash(i,j), rh2.hash(i,j));
      }
    }
  }
}
/*
TEST(RollingHashTestSuite, IncrementTest){
  {
    RollingHash<1000000007> n(0);
    EXPECT_EQ(++n, 1);
    EXPECT_EQ(++n, 2);
    EXPECT_EQ(++n, 3);
  }
  {
    RollingHash<1000000007> n(1000000005);
    EXPECT_EQ(++n, 1000000006);
    EXPECT_EQ(++n, 0);
    EXPECT_EQ(++n, 1);
  }
  {
    RollingHash<1000000007> n(0);
    EXPECT_EQ(n++, 0);
    EXPECT_EQ(n++, 1);
    EXPECT_EQ(n++, 2);
  }
  {
    RollingHash<1000000007> n(1000000005);
    EXPECT_EQ(n++, 1000000005);
    EXPECT_EQ(n++, 1000000006);
    EXPECT_EQ(n++, 0);
  }
}
  
TEST(RollingHashTestSuite, DecrementTest){
  {
    RollingHash<1000000007> n(1);
    EXPECT_EQ(--n, 0);
    EXPECT_EQ(--n, 1000000006);
    EXPECT_EQ(--n, 1000000005);
  }
  {
    RollingHash<1000000007> n(1000000006);
    EXPECT_EQ(--n, 1000000005);
    EXPECT_EQ(--n, 1000000004);
    EXPECT_EQ(--n, 1000000003);
  }
  {
    RollingHash<1000000007> n(1);
    EXPECT_EQ(n--, 1);
    EXPECT_EQ(n--, 0);
    EXPECT_EQ(n--, 1000000006);
  }
  {
    RollingHash<1000000007> n(1000000006);
    EXPECT_EQ(n--, 1000000006);
    EXPECT_EQ(n--, 1000000005);
    EXPECT_EQ(n--, 1000000004);
  }
}
TEST(RollingHashTestSuite, AdditionTest){
  RollingHash<1000000007> n(0),m(10),l(1000000006);
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
TEST(RollingHashTestSuite, SubtractionTest){
  RollingHash<1000000007> n(0), m(10), l(1000000006);
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
TEST(RollingHashTestSuite, MultiplicationTest){
  RollingHash<1000000007> n(0), m(10), l(1000000006);
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
TEST(RollingHashTestSuite, DivisionTest){
  RollingHash<1000000007> n(0), m(10), l(1000000006);
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
TEST(RollingHashTestSuite, AdditionAssignmentTest){
  {
    RollingHash<1000000007> n(0);
    EXPECT_EQ(n+=0,0);
    EXPECT_EQ(n+=1,1);
    EXPECT_EQ(n+=2,3);
    EXPECT_EQ(n+=1000000007,3);
  }
}
TEST(RollingHashTestSuite, SubtractionAssignmentTest){
  {
    RollingHash<1000000007> n(1000000006);
    EXPECT_EQ(n-=0,1000000006);
    EXPECT_EQ(n-=1,1000000005);
    EXPECT_EQ(n-=2,1000000003);
    EXPECT_EQ(n-=1000000007,1000000003);
  }
}
TEST(RollingHashTestSuite, MultiplicationAssignmentTest){
  {
    RollingHash<1000000007> n(1);
    EXPECT_EQ(n*=1,1);
    EXPECT_EQ(n*=2,2);
    EXPECT_EQ(n*=3,6);
    EXPECT_EQ(n*=1000000006,1000000001);
    EXPECT_EQ(n*=0,0);
  }
}
  
*/
