/**
 * Problem name: Apartments
 * Link: https://cses.fi/problemset/task/1084
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin>>n>>m>>k;

  vector<int> a(n);
  for(int i=0; i<n; i++)
    cin>>a[i];

  vector<int> b(m);
  for(int i=0; i<m; i++)
    cin>>b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int idx_a=0, idx_b=0;
  int res=0;

  while(idx_a<a.size() and idx_b<b.size()) {
    if(b[idx_b]<a[idx_a]-k)
      idx_b++;

    else if(b[idx_b]>a[idx_a]+k)
      idx_a++;

    else {
      idx_a++;
      idx_b++;
      res++;
    }
  }

  cout<<res<<endl;

  return 0;
}