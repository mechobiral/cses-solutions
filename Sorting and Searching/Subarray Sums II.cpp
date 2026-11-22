/**
 * Problem name: Subarray Sums II
 * Link: https://cses.fi/problemset/task/1661
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin>>n>>x;

  vector<int> v(n);
  for(int i=0; i<n; i++) {
    cin>>v[i];
  }

  // Approach: If the current prefix sum is pre, and (pre-x) is encountered before,
  // then the sum of the range must be equal to x (pre-(pre-x)=x)

  map<long long int, int> cnt;
  cnt[0]=1;

  long long int res = 0;
  long long int pre = 0;

  for(int i=0; i<n; i++) {
    pre+=v[i];
    res+=cnt[pre-x];
    cnt[pre]++;
  }

  cout<<res<<endl;

  return 0;
}