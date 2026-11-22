/**
 * Problem name: Factory Machines
 * Link: https://cses.fi/problemset/task/1620
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int n, t;
vector<int> k;

bool possible(long long int x) {
  long long int products=0;

  for(int i=0; i<n; i++) {
    products+=(x/k[i]);

    if(products>=t)
      return 1;
  }

  return 0; // products<t
}

int main() {
  cin>>n>>t;

  k = vector<int>(n);
  for(int i=0; i<n; i++)
    cin>>k[i];

  // Approach: Binary search

  long long int lo=1, hi=1e18;

  while(lo<=hi) {
    long long int mid=(lo+hi)/2;

    if(possible(mid))
      hi=mid-1;

    else
      lo=mid+1;
  }

  cout<<lo<<endl;

  return 0;
}