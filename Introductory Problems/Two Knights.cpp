/**
 * Problem name: Two Knights
 * Link: https://cses.fi/problemset/task/1072
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  for(int k=1; k<=n; k++) {
    long long int cells=1ll*k*k;
    long long int ans=cells*(cells-1)/2;

    // Each (2x3) and (3x2) blocks will have two positions for which
    // there will be two knights attacking each other

    // (2x3) blocks in k*k cells = (i-1)*(i-2)
    // (3x2) blocks in k*k cells = (i-2)*(i-1)

    long long int sub=2*(k-1)*(k-2)+2*(k-2)*(k-1);
    ans = ans-sub;

    cout<<ans<<endl;
  }

  return 0;
}