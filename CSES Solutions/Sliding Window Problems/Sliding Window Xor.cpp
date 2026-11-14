/**
 * Problem Name: Sliding Window Xor
 * Link: https://cses.fi/problemset/task/3426
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin>>n>>k;

  int x, a, b, c;
  cin>>x>>a>>b>>c;

  vector<long long int> v(k);
  v[0] = x;

  long long int cur_xor = x; // (0^x=x)
  for(int i=1; i<k; i++) {
    v[i] = (a*v[i-1]+b)%c;
    cur_xor^=v[i];
  }

  long long int res = cur_xor;

  int cur=0;
  int prev;

  for(int i=k; i<n; i++) {
    cur = (cur==k)? 0 : cur;
    prev = (cur==0)? k-1 : cur-1;

    cur_xor^=v[cur];
    v[cur]=(a*v[prev]+b)%c;
    cur_xor^=v[cur];

    res^=cur_xor;
    cur++;
  }

  cout<<res<<endl;

  return 0;
}
