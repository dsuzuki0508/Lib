#include <bits/stdc++.h>
using namespace std;
 
template <typename T>
class UnionFind {
 public:
  int find(const T& a);
  bool unite(const T& a, const T& b);
  bool same(const T& a, const T& b);
 
 private:
  map<T, int> mMap;
  int mId=0;
  deque<int> mParent;
  deque<int> mRank;
  
  int findById(int id);
};
 
template <typename T>
int UnionFind<T>::findById(int id) {
  if (id == mParent[id]) return id;
  return mParent[id] = findById(mParent[id]);
}
 
template <typename T>
int UnionFind<T>::find(const T& a) {
  int id = 0;
  if (!mMap.count(a)) {
    id = mId++;
    mMap[a] = id;
    mParent.push_back(id);
    mRank.push_back(0);
  }
  id = mMap[a];
  return findById(id);
}
 
template <typename T>
bool UnionFind<T>::unite(const T& a, const T& b) {
  int id_a = find(a);
  int id_b = find(b);
  if (a == b) return false;
 
  if (mRank[id_a] < mRank[id_b]) {
    mParent[id_a] = id_b;
  } else {
    mParent[id_b] = id_a;
    if (mRank[id_a] == mRank[id_b]) mRank[id_a]++;
  }
  return true;
}
 
template <typename T>
bool UnionFind<T>::same(const T& a, const T& b) {
  return find(a) == find(b);
}
