/**
 * Problem name: Apple Division
 * Link: https://cses.fi/problemset/task/1623
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  long long int sum=0;
  vector<int> p(n);

  for(int i=0; i<n; i++) {
    cin>>p[i];
    sum+=p[i];
  }

  // Generate all possible subsets
  // This will pass as n<=20

  long long int min_dif = sum;

  for(int i=1; i<(1<<n)-1; i++) {
    long long int cur_sum=0;

    for(int j=0; j<n; j++)
      if(i&(1<<j))
        cur_sum+=p[j];

    // Difference between the set containing cur_sum and the rest of the apples
    long long int rem_sum=sum-cur_sum;
    min_dif = min(min_dif, abs(cur_sum-rem_sum));
  }

  cout<<min_dif<<endl;
 
  return 0;
}