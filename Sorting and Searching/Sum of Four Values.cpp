/**
 * Problem name: Sum of Four Values
 * Link: https://cses.fi/problemset/task/1642
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;
 
int main() {
  int n, x;
  cin>>n>>x;
 
  vector<int> v(n);
  for(int i=0; i<n; i++)
    cin>>v[i];

  // n<=1000, O(n^3) will pass in 1s
 
  map<int, vector<pair<int, int>>> idx;

  // Generate all sum of pair(v[i], v[j])
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++)
      idx[v[i]+v[j]].push_back({i, j});
  }

  bool found = 0;

  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      int have = v[i]+v[j];
      int need = x-have;

      if(idx.count(need)==0)
        continue;

      for(auto [k, l]:idx[need]) {
        if((k==i or k==j) or (l==i or l==j))
          continue;

        cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<l+1<<endl;
        
        found = 1;
        break;
      }

      if(found)
        break;
    }

    if(found)
      break;
  }

  if(!found)
    cout<<"IMPOSSIBLE"<<endl;

  return 0;
}
