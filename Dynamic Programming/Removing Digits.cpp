/**
 * Problem name: Removing Digits
 * Link: https://cses.fi/problemset/task/1637
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  // Approach: DP
  // res[i] = min(res[i], res[i-d]+1) where d is the digits of x

  vector<int> res(n+5, 1e9);

  res[0]=0;

  for(int i=1; i<=n; i++) {
    int tmp=i;

    // Check for each digits of i
    while(tmp) {
      int d=tmp%10;
      tmp/=10;

      res[i]=min(res[i], res[i-d]+1);
    }
  }

  cout<<res[n]<<endl;

  return 0;
}