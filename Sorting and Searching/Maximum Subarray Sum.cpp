/**
 * Problem name: Maximum Subarray Sum
 * Link: https://cses.fi/problemset/task/1643
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;
 
int main() {
  int n;
  cin>>n;

  int mx=INT_MIN;

  vector<int> v(n);
  for(int i=0; i<n; i++) {
    cin>>v[i];
    mx = max(mx, v[i]);
  }

  // Print the largest element if all elements are negative
  if(mx<0)
    cout<<mx<<endl;

  else {
    long long int cur_sum = 0;
    long long int res = 0;

    for(int i=0; i<n; i++) {
      cur_sum+=v[i];

      // No need to continue with the current sequence if the sum is negative
      if(cur_sum<0)
        cur_sum=0;

      res = max(res, cur_sum);
    }

    cout<<res<<endl;
  }

  return 0;
}
