/**
 * Problem name: Subarray Sums I
 * Link: https://cses.fi/problemset/task/1660
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

  // Sliding Window Technique can be used

  int l = 0;
  int res = 0;
  int cur_sum = 0;

  for(int r=0; r<n; r++) {
    cur_sum+=v[r];

    while(cur_sum>x) {
      cur_sum-=v[l];
      l++;
    }

    if(cur_sum==x)
      res++;
  }

  cout<<res<<endl;

  return 0;
}
