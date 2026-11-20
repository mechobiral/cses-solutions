/**
 * Problem name: Multiplication Table
 * Link: https://cses.fi/problemset/task/2422
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  // Approach: Binary search on multiplication table
  long long int lo=1;
  long long int hi=1ll*n*n;

  while(lo<hi) {
    long long int mid=(lo+hi)/2;

    long long int cnt=0;
    for(int i=1; i<=n; i++) {
      if((mid/i)>=n)
        cnt+=n;

      else
        cnt+=(mid/i);
    }

    if(cnt>=(1ll*n*n+1)/2)
      hi=mid;

    else
      lo=mid+1;
  }

  cout<<hi<<endl;

  return 0;
}