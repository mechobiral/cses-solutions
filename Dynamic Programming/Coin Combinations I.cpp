/**
 * Problem name: Coin Combinations I
 * Link: https://cses.fi/problemset/task/1635
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main() {
  int n, x;
  cin>>n>>x;

  vector<int> coins(n);
  for(auto &coin:coins)
    cin>>coin;

  vector<long long int> dp(x+10);

  for(auto coin:coins)
    if(coin<=x)
      dp[coin]=1;

  for(int i=1; i<=x; i++) {
    long long int cur_sum=0;

    for(auto coin:coins) {
      if(i-coin>=1)
        cur_sum+=(dp[i-coin]);
    }

    dp[i]=(dp[i]+cur_sum)%MOD;
  }

  cout<<dp[x]<<endl;

  return 0;
}