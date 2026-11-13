/**
 * Problem Name: Digit Queries
 * Link: https://cses.fi/problemset/task/2431/
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include <iostream>
#include <vector>

#define roof(x, y)    (((x)/(y))+(x%y!=0))

using namespace std;
using lli = long long int;

// Using custom pow() function to avoid precision loss
lli pw(lli a, lli b) {
  lli res = 1;
  for (int i=1; i<=b; i++)
    res*=a;

  return res;
}
 
/*
  Vector to store ranges

  Example: Let s[] be the infinite string
  Numbers with 1 digit occupy s[1] to s[9]
  Numbers with 2 digits occupy s[10] to s[189]
  And so on
*/
vector<lli> range(18);

void seive_range() {
  for(int i=1; i<18; i++)
    range[i] = range[i-1] + 9LL*i*pw(10, i-1);
}

// Returns the number that `k` belongs to
lli target_num(lli k) {
  int i = 0;
  while(range[i]<k)
    i++;

  lli base = pw(10, i-1)-1; // Starting number containing the same digits as the number `k` belongs to
  lli curnum = roof((k-range[i-1]), (1LL*i))+base; // The number that `k` belongs to

  return curnum;
}

int main() {
  seive_range();

  int q;
  cin>>q;

  while(q--) {
    lli k;
    cin>>k;

    if(k<10) {
      cout<<k<<endl;
      continue;
    }

    lli base_k = k;
    while(target_num(k)==target_num(base_k-1))
      base_k--;

    lli cur = target_num(k);
    lli offset = k-base_k;

    cout<<to_string(cur)[offset]<<endl;
  }
}