/**
 * Problem Name: Hidden Integer
 * Link: https://cses.fi/problemset/task/3112
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;
 
int ask(int n) {
  cout<<"? "<<n<<endl;
  cout.flush();

  string resp;
  cin>>resp;
  return (resp=="YES");
}
 
int main() {
  int lo=1, hi=1e9;

  // Approach: Binary Search (O(logn)) passes
  while(lo<=hi) {
    int mid=(lo+hi)/2;
    int resp=ask(mid);

    // mid > n
    if(resp==1)
      lo=mid+1;

    else
      hi=mid-1;
  }

  cout<<"! "<<lo<<endl;
  cout.flush();
 
  return 0;
}