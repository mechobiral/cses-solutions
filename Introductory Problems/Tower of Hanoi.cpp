/**
 * Problem name: Tower of Hanoi
 * Link: https://cses.fi/problemset/task/2165
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

void hanoi(int n, int start=1, int inter=2, int end=3) {
  if(n==0)
    return;

  hanoi(n-1, start, end, inter);

  cout<<start<<" "<<end<<endl;

  hanoi(n-1, inter, start, end);
}

int main() {
  int n;
  cin>>n;

  cout<<(1<<n)-1<<endl;

  hanoi(n);

  return 0;
}