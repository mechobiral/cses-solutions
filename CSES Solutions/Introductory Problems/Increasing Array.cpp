/**
 * Problem Name: Increasing Array
 * Link: https://cses.fi/problemset/task/1094
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

  // Make v[i] equal to v[i-1] if v[i-1]>v[i]

  long long int res=0;
  for(int i=1; i<n; i++) {
    if(v[i]<v[i-1]) {
      res+=(v[i-1]-v[i]);
      v[i]=v[i-1];
    }
  }

  cout<<res<<endl;

  return 0;
}