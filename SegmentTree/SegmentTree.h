#include <bits/stdc++.h>






template<typename S, auto op, auto e>
class SegmentTree{
  std::vector<S> mArray;
  int mN;
  int mSize;
  int mLog;
  void resize(unsigned int n);
  void update(int n);
public:
  SegmentTree();
  SegmentTree(int n);
  SegmentTree(const std::vector<S>& v);
  void set(int p, const S& x);
  S get(int p);
  S prod(int l, int r);
  S all_prod();
};

template<typename S, auto op, auto e>
SegmentTree<S,op,e>::SegmentTree():SegmentTree(0){}
template<typename S, auto op, auto e>
SegmentTree<S,op,e>::SegmentTree(int n):SegmentTree(std::vector<S>(n, e())){}
template<typename S, auto op, auto e>
SegmentTree<S,op,e>::SegmentTree(const std::vector<S>& v):mN(v.size()),mSize(std::bit_ceil(v.size())){
  mLog = std::countr_zero((unsigned int)mSize);
  mArray.assign(mSize*2, e());
  for(int i = 0;i<(int)v.size();i++){
    mArray[mSize+i] = v[i];
  }
  for(int i = mSize-1;i>=1;i--){
    update(i);
  }
}

template<typename S, auto op, auto e>
void SegmentTree<S,op,e>::resize(unsigned int n){
  if( mSize >= n )return;
  mN = n;
  int old_size = mSize;
  mSize = std::bit_ceil(n);
  mLog = std::countr_zero((unsigned int)mSize);
  mArray.resize(mSize*2, e());

  for(int i = 0;i<old_size;i++){
    mArray[mSize+i] = mArray[old_size+i];
  }
  for(int i = mSize -1;i>=1;i--){
    update(i);
  }
}
template<typename S, auto op, auto e>
void SegmentTree<S,op,e>::update(int n){
  mArray[n] = op(mArray[n*2], mArray[n*2+1]);
}


template<typename S, auto op, auto e>
void SegmentTree<S,op,e>::set(int p, const S& x){
  p+=mSize;
  mArray[p] = x;
  while(p>1){
    p>>=1;
    update(p);
  }
}
template<typename S, auto op, auto e>
S SegmentTree<S,op,e>::get(int p){
  assert(0<=p && p<mN);
  p+=mSize;
  return mArray[p];
}

template<typename S, auto op, auto e>
S SegmentTree<S,op,e>::prod(int l, int r){
  assert(0<=l && l<= r&& r<=mN);
  l+=mSize;
  r+=mSize;
  S le = e();
  S re = e();

  while(l<r){
    if(l&1) le=op(le, mArray[l++]);
    if(r&1) re=op(mArray[--r], re);
    l>>=1;
    r>>=1;
  }
  return op(le, re);
}
template<typename S, auto op, auto e>
S SegmentTree<S,op,e>::all_prod(){
  return mArray[1];
}



/*
template<typename T>
void SegmentTree<T>::resize(int n){
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
void SegmentTree<T>::add(int p, T x){
  assert(0<=p);
  p++;
  resize(p);
  while(p<=static_cast<int>(mArray.size())){
    mArray[p-1]+=x;
    p+=p&-p;
  }
}
template<typename T>
T SegmentTree<T>::sum(int n){
  resize(n);
  T ret = T();
  while(n>0){
    ret+=mArray[n-1];
    n-=n&-n;
  }
  return ret;
}
template<typename T>
T SegmentTree<T>::sum(int l, int r){
  resize(r);
  return sum(r) - sum(l);
}
*/
