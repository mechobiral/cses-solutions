/**
 * Problem name: Collecting Numbers
 * Link: https://cses.fi/problemset/task/2216/
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

  vector<bool> visited(n+1);
  int res = 0;

  // Cannot take i-th number if (i-1)-th number is not taken already
  for(int i=0; i<n; i++) {
    if(!visited[v[i]-1])
      res++;

    visited[v[i]]=1;
  }

  cout<<res<<endl;

  return 0;
}
