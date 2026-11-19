/**
 * Problem name: Stick Lengths
 * Link: https://cses.fi/problemset/task/1074
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

  sort(v.begin(), v.end());

  long long int res = 0;
  int mid = v[n/2];

  for(int i=0; i<n; i++) {
    int add = abs(mid-v[i]);
    res+=add;
  }

  cout<<res<<endl;

  return 0;
}
