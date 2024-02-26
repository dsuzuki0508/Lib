#include <gtest/gtest.h>

#include "UnionFind.h"

TEST(UnionFindTestSuite, FindTest){
  UnionFind<int> u;
  for(int i = 0;i<10;i++){
    for( int j = 0;j<10;j++){
      if(i==j){
	EXPECT_EQ(u.find(i),u.find(j));
      }else{
	EXPECT_NE(u.find(i),u.find(j));
      }
    }
  }
  for(int i = 1;i< 10;i++){
    u.unite(i,i-1);
  }
  for(int i = 0;i<10;i++){
    for( int j = 0;j<10;j++){
      EXPECT_EQ(u.find(i),u.find(j));
    }
  }
}

TEST(UnionFindTestSuite, UniteTest){
  {
    UnionFind<int> u;
    EXPECT_FALSE(u.same(0,1));
    EXPECT_FALSE(u.same(0,2));
    EXPECT_FALSE(u.same(1,2));
    u.unite(0,1);
    u.unite(1,2);
    EXPECT_TRUE(u.same(0,1));
    EXPECT_TRUE(u.same(0,2));
    EXPECT_TRUE(u.same(1,2));
  }
}

TEST(UnionFindTestSuite, SameTest){
  UnionFind<int> u;
  for( int i = 0;i< 10;i++){
    for(int j = 0;j< 10;j++){
      if(i==j){
	EXPECT_TRUE(u.same(i,j));
      }else{
	EXPECT_FALSE(u.same(i,j));
      }
    }
  }
  for(int i = 1;i< 10;i++){
    u.unite(i,i-1);
  }
  for( int i = 0;i< 10;i++){
    for(int j = 0;j< 10;j++){
      EXPECT_TRUE(u.same(i,j));
    }
  }
}
      
