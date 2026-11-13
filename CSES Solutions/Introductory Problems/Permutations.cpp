/**
 * Problem Name: Permutations
 * Link: https://cses.fi/problemset/task/1070
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  if(n==1)
    cout<<1<<endl;

  else if(n<=3)
    cout<<"NO SOLUTION"<<endl;

  else {
    // 2 4 6 ... 1 3 5 ...

    for(int i=2; i<=n; i+=2)
      cout<<i<<" ";

    for(int i=1; i<=n; i+=2)
      cout<<i<<" ";

    cout<<endl;
  }

  return 0;
}