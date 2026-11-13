/**
 * Problem name: Nearest Smaller Values
 * Link: https://cses.fi/problemset/task/1645
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

  stack<int> prev_idx;
  vector<int> res(n);

  for(int i=0; i<n; i++) {
    // No need to keep elements larger than v[i] in stack when v[i] is a better option
    while(!prev_idx.empty() and v[prev_idx.top()]>=v[i])
      prev_idx.pop();

    if(!prev_idx.empty()) {
      res[i] = prev_idx.top()+1;
    }

    prev_idx.push(i);
  }

  for(int i=0; i<n; i++)
    cout<<res[i]<<" ";
  cout<<endl;

  return 0;
}
