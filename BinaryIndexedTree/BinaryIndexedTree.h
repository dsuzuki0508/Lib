#include <bits/stdc++.h>


template<typename T>
class BinaryIndexedTree{
  std::vector<T> mArray;
  void resize(int n);
  T sum(int n);
public:
  BinaryIndexedTree(){}
  BinaryIndexedTree(int n):mArray(n){}
  void add(int p, T x);
  T sum(int l, int r);
};

template<typename T>
void BinaryIndexedTree<T>::resize(int n){
  if(n<=static_cast<int>(mArray.size()))return;
  int i = mArray.size();
  mArray.resize(n);
  i++;
  for(;i<=n;i++){
    int l = i&-i;
    int b = i-l;
    while(l>1){
      l/=2;
      b+=l;
      mArray[i-1]+=mArray[b-1];
    }
  }
}

template<typename T>
void BinaryIndexedTree<T>::add(int p, T x){
  assert(0<=p);
  p++;
  resize(p);
  while(p<=static_cast<int>(mArray.size())){
    mArray[p-1]+=x;
    p+=p&-p;
  }
}
template<typename T>
T BinaryIndexedTree<T>::sum(int n){
  resize(n);
  T ret = T();
  while(n>0){
    ret+=mArray[n-1];
    n-=n&-n;
  }
  return ret;
}
template<typename T>
T BinaryIndexedTree<T>::sum(int l, int r){
  resize(r);
  return sum(r) - sum(l);
}
