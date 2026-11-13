/**
 * Problem name: Sum of Two Values
 * Link: https://cses.fi/problemset/task/1640
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;
 
int main() {
  int n, x;
  cin>>n>>x;

  vector<int> v(n);
  map<int, vector<int>> idx;
  bool found = 0;

  for(int i=0; i<n; i++) {
    cin>>v[i];
    idx[v[i]].push_back(i);
  }

  for(int i=0; i<n; i++) {
    // need = total - have
    int need = x-v[i];

    // Check if there exists any index j such that i!=j and v[i]+v[j]==x

    for(auto j:idx[need])
      if(j!=i) {
        cout<<i+1<<" "<<j+1<<endl;
        found=1;
        break;
      }

    if(found)
      break;
  }

  if(!found)
    cout<<"IMPOSSIBLE"<<endl;
 
  return 0;
}
