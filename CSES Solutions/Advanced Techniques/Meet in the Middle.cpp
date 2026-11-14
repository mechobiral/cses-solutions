/**
 * Problem Name: Meet in the Middle
 * Link: https://cses.fi/problemset/task/1628/
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

void compute(vector<int>& v, vector<int>& sum, const int& x) {
  int n=v.size();

  for(int i=0; i<(1ll<<n); i++) {
    int cur_sum = 0;
    bool take = 1;

    for(int j=0; j<n; j++)
      if(i&(1ll<<j)) {
        cur_sum+=v[j];

        // No need to take cur_sum if it is already bigger than x
        if(cur_sum>x) {
          take = 0;
          break;
        }
      }
    
    if(take)
      sum.push_back(cur_sum);
  }
}

int main() {
  int n, x;
  cin>>n>>x;

  // n<=40
  // Split array into halves, generate all subsets and combine their result
  // Subset generation: 2*(2^20)
  // Searching: (2^20)log(2^20)
  // Will pass in 1s

  int n1=n/2, n2=n-n1;
  vector<int> t1(n1), t2(n2);

  for(int i=0; i<n1; i++)
    cin>>t1[i];

  for(int i=0; i<n2; i++)
    cin>>t2[i];

  // All possible subset sums of t1
  vector<int> sum1; 
  compute(t1, sum1, x);

  // All possible subset sums of t2
  vector<int> sum2; 
  compute(t2, sum2, x);

  // Binary search on sum2 
  sort(sum2.begin(), sum2.end());

  long long int res=0;
  for(auto have:sum1) {
    int need=x-have;

    auto ub = upper_bound(sum2.begin(), sum2.end(), need)-1;
    auto lb = lower_bound(sum2.begin(), sum2.end(), need)-1;
    int got = ub-lb;

    res+=got;
  }

  cout<<res<<endl;
   
  return 0;
}
