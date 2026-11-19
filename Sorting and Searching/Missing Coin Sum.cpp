/**
 * Problem name: Missing Coin Sum
 * Link: https://cses.fi/problemset/task/2183
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

  long long int pre = 0;

  for(int i=0; i<n; i++) {
    // if v[i] is greater than the prefix_sum + 1, it is impossible to reach the current prefix_sum + 1
    
    if(pre+1 < v[i])
      break;

    pre+=v[i];
  }

  long long int res = pre+1;
  cout<<res<<endl;

  return 0;
}
