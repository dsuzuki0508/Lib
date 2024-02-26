#include <bits/stdc++.h>

template<unsigned long long BASE = 0xc0dedba5e>
class RollingHash{
  static const unsigned long long MASK30 = (1UL << 30) - 1;
  static const unsigned long long MASK31 = (1UL << 31) - 1;
  static const unsigned long long MOD = (1UL << 61) - 1;
  static const unsigned long long MASK61 = MOD;
  std::deque<unsigned long long> mHash;
  std::deque<unsigned long long> mPow;

  static unsigned long long calcMod(unsigned long long x){
    unsigned long long xu = x >> 61;
    unsigned long long xd = x & MASK61;
    unsigned long long res = xu + xd;
    if (res >= MOD) res -= MOD;
    return res;
  }
  static unsigned long long mul(unsigned long long a, unsigned long long b){
    unsigned long long au = a >> 31;
    unsigned long long ad = a & MASK31;
    unsigned long long bu = b >> 31;
    unsigned long long bd = b & MASK31;
    unsigned long long mid = ad * bu + au * bd;
    unsigned long long midu = mid >> 30;
    unsigned long long midd = mid & MASK30;
    return calcMod(au * bu * 2 + midu + (midd << 31) + ad * bd);
  }
  static unsigned long long pow(unsigned long long b, unsigned long long n){
    unsigned long long x=b,r=1;
    while(n){
      if(n&1)r = mul(r, x);
      x = mul(x, x);
      n>>=1;
    }
    return r;
  }
  static unsigned long long inv(unsigned long long b){
    return pow(b, MOD-2);
  }
  static unsigned long long inv(){
    static unsigned long long invBase = 0;
    if(invBase==0) return invBase = inv(BASE);
    return invBase;
  }
public:
  unsigned long long append(unsigned long long e){
    mHash.push_back( calcMod( mul(mHash.back(), BASE) + e ) );
    mPow.push_back( mul(mPow.back(), BASE) );
    return mHash.back();
  }
  RollingHash(){
    mHash.push_back(0);
    mPow.push_back(1);
  }
  template<typename InputIterator>
  RollingHash(InputIterator b, InputIterator e):RollingHash(){
    while(b!=e){
      append(*b);
      b=next(b);
    }
  }
  template<typename T>
  RollingHash(const T& v):RollingHash(v.begin(), v.end()){}
  unsigned long long val(){
    return mHash.back();
  }
  unsigned long long hash(long long l = 0, long long r= -1){
    assert(l>=0);
    assert(l<static_cast<long long>(mHash.size()));
    assert(r>=-1);
    assert(r<static_cast<long long>(mHash.size()));
    if(r==-1)r=mHash.size()-1;
    assert(l<=r);
    return calcMod( mHash[r] - mul(mHash[l] , mPow[r-l]) +MOD );
  }
};
