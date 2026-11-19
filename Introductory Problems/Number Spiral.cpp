/**
 * Problem name: Number Spiral
 * Link: https://cses.fi/problemset/task/1071
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin>>t;

  while(t--) {
    int r, c;
    cin>>r>>c;

    int mx=max(r, c);
    long long int diag=1+2*1ll*(mx-1)*(mx+1-1)/2;
    long long int res=diag;

    if(mx%2==0) {
      if(c<mx)
        res+=(mx-c);
      else
        res-=(mx-r);
    }

    else {
      if(r<mx)
        res+=(mx-r);
      else
        res-=(mx-c);
    }

    cout<<res<<endl;
  }

  return 0;
}