/**
 * Problem name: Trailing Zeros
 * Link: https://cses.fi/problemset/task/1618
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int get(int n, int k) {
  int cnt=0;

  for(int i=k; i<=n; i*=k) {
    cnt+=(n/i);
  }

  return cnt;
}

int main() {
  int n;
  cin>>n;

  // number of 2s in n!
  int fives=get(n, 5);

  // number of 5s in n!
  int twos=get(n, 2);

  // number of 10s = min(2s, 5s) as 10=5*2
  int res=min(fives, twos);

  cout<<res<<endl;

  return 0;
}