/**
 * Problem name: Sum of Three Values
 * Link: https://cses.fi/problemset/task/1641
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;
 
int main() {
  int n, x;
  cin>>n>>x;
 
  vector<int> v(n);
  map<int, vector<int>> idx;
 
  for(int i=0; i<n; i++) {
    cin>>v[i];
    idx[v[i]].push_back(i);
  }
 
  // n<=5000, O(n^2) will pass within 1s

  bool found = 0;

  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      int have = v[i]+v[j];
      int need = x-have;
 
      if(idx.count(need)==0)
        continue;

      for(auto k:idx[need]) {
        if(k!=i and k!=j) {
          cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
          found = 1;
          break;
        }
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
