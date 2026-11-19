/**
 * Problem Name: Common Divisors
 * Link: https://cses.fi/problemset/task/1081
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

const int X = 1e6;

int main() {
  int n;
  cin>>n;

  vector<int> cnt(X+1);
  vector<int> v(n);

  for(int i=0; i<n; i++) {
    cin>>v[i];
    cnt[v[i]]++;
  }

  // Approx. O(nlogn) solution will pass 1s

  int res = 1;
  for(int i=X; i>=1; i--) {
    int cur=0;

    for(int j=i; j<=X; j+=i) {
      cur+=cnt[j];

      if(cur>=2) {
        res = i;
        break;
      }
    }

    if(res!=1)
      break;
  }

  cout<<res<<endl;

  return 0;
}
