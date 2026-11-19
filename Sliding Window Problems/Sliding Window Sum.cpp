/**
 * Problem Name: Sliding Window Sum
 * Link: https://cses.fi/problemset/task/3220
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin>>n>>k;

  int x, a, b, c;
  cin>>x>>a>>b>>c;

  long long int res = 0;
  long long int cur_sum=0;
  
  // Generate array as we travel
  vector<long long int> v(n);

  v[0]=x;
  cur_sum+=x;

  for(int i=1; i<k; i++) {
    v[i]=(a*v[i-1]+b)%c;
    cur_sum+=v[i];
  }

  res=cur_sum;

  int cur=0;
  for(int i=k; i<n; i++) {
    if(cur==k)
      cur=0;
    
    int prev=(cur==0)? k-1 : cur-1;

    cur_sum-=v[cur];
    v[cur]=(a*v[prev]+b)%c;
    cur_sum+=v[cur];

    res^=cur_sum;
    cur++;
  }

  cout<<res<<endl;

  return 0;
}
