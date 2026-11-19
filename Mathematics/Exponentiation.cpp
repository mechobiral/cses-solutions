/**
 * Problem Name: Exponentiation
 * Link: https://cses.fi/problemset/task/1095
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

long long int binexp(int a, int b) {
  // b<=1e9, so b will have at most ~30 bits
  long long int pw[30];
  pw[0] = a;
  for(int i=1; i<30; i++)
    pw[i] = (pw[i-1]*pw[i-1])%MOD;
  
  long long int res = 1;
  for(int i=0; i<30; i++)
    if(b&(1<<i))
      res = (res*pw[i])%MOD;

  return res;
}

int main() {
  int t;
  cin>>t;

  while(t--) {
    int a, b;
    cin>>a>>b;

    // Use binary exponentiation to calculate (a**b) in O(log(n)) time
    long long int res=binexp(a, b);
    cout<<res<<endl;
  }

  return 0;
}
