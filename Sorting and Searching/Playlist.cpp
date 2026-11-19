/**
 * Problem name: Playlist
 * Link: https://cses.fi/problemset/task/1141
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  vector<int> v(n);
  for(int i=0; i<n; i++)
    cin>>v[i];

  map<int, int> prev_occ;
  int start_idx=0;
  int res=0;

  for(int i=0; i<n; i++) {
    if(!prev_occ.count(v[i])) {
      prev_occ[v[i]]=i;
      continue;
    }

    if(prev_occ[v[i]]<start_idx)
      prev_occ[v[i]]=i;

    else {
      res=max(res, i-start_idx);
      start_idx=prev_occ[v[i]]+1;
      prev_occ[v[i]]=i;
    }
  }
  res=max(res, n-start_idx);

  cout<<res<<endl;

  return 0;
}