/**
 * Problem name: Creating Strings
 * Link: https://cses.fi/problemset/task/1622
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

void permute(string s, int start, set<string>& combinations) {
  if(start>=s.size()) {
    combinations.insert(s);
    return;
  }

  for(int i=start; i<s.size(); i++) {
    swap(s[start], s[i]);

    permute(s, start+1, combinations);

    swap(s[start], s[i]);
  }
}

int main() {
  string s;
  cin>>s;

  sort(s.begin(), s.end());

  set<string> combinations;

  permute(s, 0, combinations);

  cout<<combinations.size()<<endl;
  for(string combination:combinations)
    cout<<combination<<endl;

  cout<<endl;

  return 0;
}