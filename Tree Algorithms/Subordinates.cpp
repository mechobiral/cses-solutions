/**
 * Problem Name: Subordinates
 * Link: https://cses.fi/problemset/task/1674
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

vector<int> children; // number of children of a node
vector<vector<int>> adj;

int count_child(int node) {
  if(children[node]!=0)
    return children[node];

  int child=0;
  for(auto next:adj[node])
    child+=(1+count_child(next));

  children[node]=child;

  return child;
}

int main() {
  int n;
  cin>>n;

  vector<int> v(n+1);
  for(int i=2; i<=n; i++)
    cin>>v[i];

  children=vector<int>(n+1);
  adj=vector<vector<int>>(n+1);

  for(int i=2; i<=n; i++)
    adj[v[i]].push_back(i);

  count_child(1);

  for(int i=1; i<=n; i++)
    cout<<children[i]<<" ";
  cout<<endl;

  return 0;
}
