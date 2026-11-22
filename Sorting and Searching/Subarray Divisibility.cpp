/**
 * Problem name: Subarray Divisibility
 * Link: https://cses.fi/problemset/task/1662
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  vector<int> v(n);
  for(int i=0; i<n; i++) {
    cin>>v[i];
  }

  map<int, int> cnt;
  cnt[0]=1;

  long long int res = 0;
  int pre = 0;

  for(int i=0; i<n; i++) {
    pre+=v[i];

    if(pre>=0)
      pre=pre%n;

    else
      pre=((pre%n)+n)%n;

    res+=cnt[pre];

    cnt[pre]++;
  }

  cout<<res<<endl;

  return 0;
}