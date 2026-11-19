/**
 * Problem name: Towers
 * Link: https://cses.fi/problemset/task/1073
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

  // Multiset for O(logn) binsearch, insertion and deletion

  multiset<int> s;

  for(int i=0; i<n; i++) {
    auto ub=s.upper_bound(v[i]);

    if(ub==s.end())
      s.insert(v[i]);

    else {
      s.erase(ub);
      s.insert(v[i]);
    }
  }

  cout<<s.size()<<endl;

  return 0;
}