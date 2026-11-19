/**
 * Problem name: Traffic Lights
 * Link: https://cses.fi/problemset/task/1163
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int x, n;
  cin>>x>>n;

  vector<int> pos(n);
  for(int i=0; i<n; i++)
    cin>>pos[i];

  // Multiset is used for O(log(n)) binary search and insertion

  multiset<int> lights;
  lights.insert(0);
  lights.insert(x);

  multiset<int> res;
  res.insert(x);

  for(int i=0; i<n; i++) {
    lights.insert(pos[i]);

    int pre=*prev(lights.find(pos[i]));
    int nex=*next(lights.find(pos[i]));

    res.erase(res.find(nex-pre));
    
    res.insert(pos[i]-pre);
    res.insert(nex-pos[i]);

    cout<<*prev(res.end())<<" ";
  }

  cout<<endl;

  return 0;
}