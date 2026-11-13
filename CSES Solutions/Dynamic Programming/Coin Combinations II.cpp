/**
 * Problem Name: Coin Combinations II
 * Link: https://cses.fi/problemset/task/1636/
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main() {
	int n, c;
	cin>>n>>c;

	vector<int> coins(n);
	for(auto &coin:coins)
		cin>>coin;

	vector<int> dp(c+1);
	dp[0]=1;

	for(auto coin:coins) {
		if(coin>c)
			continue;

		for(int sum=0; sum<=c; sum++) {
			if(dp[sum] and sum+coin<=c) {
				dp[sum+coin]=(dp[sum+coin]+dp[sum])%MOD;
			}
		}
	}

	cout<<dp[c]<<endl;
}