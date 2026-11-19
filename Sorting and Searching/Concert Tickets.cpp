/**
 * Problem name: Concert Tickets
 * Link: https://cses.fi/problemset/task/1091
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin>>n>>m;

  // Multiset is used for BST
  // Efficient binary searching over the elements while giving
  // O(logn) insertion and deletion

  multiset<int> h;
  for(int i=0; i<n; i++) {
    int x;
    cin>>x;
    h.insert(x);
  }

  vector<int> t(m);
  for(int i=0; i<m; i++)
    cin>>t[i];

  vector<int> res(m);

  for(int i=0; i<m; i++) {
    auto ub=h.upper_bound(t[i]);

    if(ub==h.begin()) {
      res[i]=-1;
      continue;
    }

    ub--;
  
    res[i] = (*ub);

    h.erase(ub);
  }

  for(int i=0; i<m; i++)
    cout<<res[i]<<" ";

  cout<<endl;

  return 0;
}