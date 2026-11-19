/**
 * Problem name: Ferris Wheel
 * Link: https://cses.fi/problemset/task/1090
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin>>n>>k;

  vector<int> v(n);
  for(int i=0; i<n; i++)
    cin>>v[i];

  sort(v.begin(), v.end());

  // Pairing the lowest and highest available weight is optimal 

  int l=0, r=n-1;
  int res=0;

  while(l<=r) {
    if(v[l]+v[r]>k)
      r--;

    else {
      l++;
      r--;
    }

    res++;
  }

  cout<<res<<endl;

  return 0;
}