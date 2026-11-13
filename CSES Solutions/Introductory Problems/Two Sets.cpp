/**
 * Problem Name: Two Sets
 * Link: https://cses.fi/problemset/task/1092
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;
 
int main() {
  int n;
  cin>>n;

  // 1+2+...+n must be even

  long long int tot=1ll*n*(n+1)/2;
  if(tot%2) {
    cout<<"NO"<<endl;
    return 0;
  }

  // Keep taking the biggest integer from 1...n which has not been taken yet

  vector<int> set1, set2;

  long long int need = tot/2;
  for(int i=n; i>=1; i--) {
    if(need>=i) {
      set1.push_back(i);
      need-=i;
    }

    else {
      set2.push_back(i);
    }
  }

  cout<<"YES"<<endl;

  cout<<set1.size()<<endl;
  for(auto it:set1)
    cout<<it<<" ";
  cout<<endl;

  cout<<set2.size()<<endl;
  for(auto it:set2)
    cout<<it<<" ";
  cout<<endl;
 
  return 0;
}