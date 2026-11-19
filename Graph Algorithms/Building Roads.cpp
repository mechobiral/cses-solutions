/**
 * Problem Name: Building Roads
 * Link: https://cses.fi/problemset/task/1666
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int src) {
  vis[src] = 1;

  for(auto next:adj[src]) {
    if(!vis[next])
      dfs(next);
  }
}

int main() {
  int n, m;
  cin>>n>>m;

  adj = vector<vector<int>>(n+1);

  for(int i=0; i<m; i++) {
    int x, y;
    cin>>x>>y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vis = vector<bool>(n+1);
  vector<int> road_end;

  for(int i=1; i<=n; i++) {
    if(vis[i])
      continue;

    road_end.push_back(i);
    dfs(i);
  }

  cout<<road_end.size()-1<<endl;
  for(int i=1; i<road_end.size(); i++)
    cout<<road_end[i-1]<<" "<<road_end[i]<<endl;

  cout<<endl;

  return 0;
}
