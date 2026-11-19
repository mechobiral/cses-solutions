/**
 * Problem name: Restaurant Customers
 * Link: https://cses.fi/problemset/task/1619
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  map<int, int> del;

  int n;
  cin>>n;

  for(int i=0; i<n; i++) {
    int x, y;
    cin>>x>>y;

    del[x]++;
    del[y]--;
  }

  int res=0;
  int cur=0;

  for(auto [time, delta]:del) {
    cur+=delta;
    res=max(res, cur);
  }

  cout<<res<<endl;

  return 0;
}