/**
 * Problem name: Distinct Numbers
 * Link: https://cses.fi/problemset/task/1621
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  vector<int> v(n);
  for(auto &it:v)
    cin>>it;

  sort(v.begin(), v.end());

  int cnt=0;
  int prev=0;

  for(int i=0; i<n; i++) {
    if(v[i]!=prev) {
      prev=v[i];
      cnt++;
    }
  }

  cout<<cnt<<endl;

  return 0;
}