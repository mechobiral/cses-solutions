/**
 * Problem name: Money Sums
 * Link: https://cses.fi/problemset/task/1745
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  vector<int> x(n);
  for(int i=0; i<n; i++)
    cin>>x[i];

  vector<vector<int>> possible(n+1, vector<int>(100001));
  set<int> res;

  // possible[i][j]
  // i-> used
  // j-> cost (is reachable)

  possible[0][0]=1;

  for(int i=1; i<=n; i++) {
    possible[i]=possible[i-1];

    for(int j=x[i-1]; j<=100000; j++) {
      if(possible[i-1][j-x[i-1]]) {
        possible[i][j]=1;
        res.insert(j);
      }
    }
  }

  cout<<res.size()<<endl;
  for(auto it:res)
    cout<<it<<" ";

  cout<<endl;

  return 0;
}