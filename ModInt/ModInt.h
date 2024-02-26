#include <bits/stdc++.h>
template <auto MOD, typename T = long long int>
class ModInt{
public:
  ModInt():mN(0){};
  ModInt(const ModInt<MOD,T>& m):mN(m.mN){};
  template <typename U>
  ModInt(U v):mN(((v%MOD)+MOD)%MOD){};
  long long int val(){return mN;}
  ModInt pow( long long int n)const{
    ModInt x=*this, r=1;
    while(n){
      if(n&1)r*=x;
      x*=x;
      n>>=1;
    }
    return r;
  }
  ModInt inv() const{
    return pow(MOD-2);
  }
  ModInt& operator++(){
    mN++;
    mN%=MOD;
    return *this;
  }
  ModInt& operator--(){
    mN--;
    mN+=MOD;
    mN%=MOD;
    return *this;
  }
  ModInt operator++(int){
    ModInt ret = *this;
    mN++;
    mN%=MOD;
    return ret;
  }
  ModInt operator--(int){
    ModInt ret = *this;
    mN--;
    mN+=MOD;
    mN%=MOD;
    return ret;
  }
  ModInt& operator+=(const ModInt& rhs){
    mN+=rhs.mN;
    mN%=MOD;
    return *this;
  }
  ModInt& operator-=(const ModInt& rhs){
    mN-=rhs.mN;
    mN+=MOD;
    mN%=MOD;
    return *this;
  }
  ModInt& operator*=(const ModInt& rhs){
    mN*=rhs.mN;
    mN%=MOD;
    mN+=MOD;
    mN%=MOD;
    return *this;
  }
  ModInt& operator/=(const ModInt& rhs){
    return *this = *this * rhs.inv();
  }
  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
    ModInt ret(lhs);
    return ret+=rhs;
  }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
    ModInt ret(lhs);
    return ret-=rhs;
  }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
    ModInt ret(lhs);
    return ret*=rhs;
  }
  friend bool operator==(const ModInt& lhs, const ModInt& rhs) {
    return lhs.mN == rhs.mN;
  }
  private:
    unsigned long long int mN;
};
