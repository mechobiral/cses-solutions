/**
 * Problem name: Movie Festival
 * Link: https://cses.fi/problemset/task/1629
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  vector<pair<int, int>> movie(n);
  for(int i=0; i<n; i++) {
    cin>>movie[i].first>>movie[i].second;
  }

  // Case: (3, 15), (3, 4), (3, 6)
  // We want it to be sorted as: (3, 4), (3, 6), (3, 15)

  sort(movie.begin(), movie.end(), [&]
    (pair<int, int>& a, pair<int, int>& b) {
      if(a.second==b.second)
        return a.first<b.first;

      return (a.second<b.second);
    }
  );

  int prev=0;
  int res=0;

  for(int i=0; i<n; i++) {
    if(prev<=movie[i].first) {
      prev=movie[i].second;
      res++;
    }
  }

  cout<<res<<endl;

  return 0;
}