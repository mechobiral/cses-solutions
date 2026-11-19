/**
 * Problem Name: Counting Divisors
 * Link: https://cses.fi/problemset/task/1713
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

const int X = 1e6;

// Every number can be divided by 1 and itself
vector<int> divisorcnt(X+10, 2);

void seive() {
  for(int i=2; i<=X; i++) {
    for(int j=i+i; j<=X; j+=i)
      divisorcnt[j]++;
  }
}

int main() {
  // Precalculate the task within O(nlogn) time
  seive();

  int t;
  cin>>t;

  while(t--) {
    int x;
    cin>>x;

    cout<<divisorcnt[x]<<endl;
  }

  return 0;
}
