/**
 * Problem Name: Round Trip
 * Link: https://cses.fi/problemset/task/1669
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;
vector<int> path;

void construct_path(int cycle_start, int cycle_end) {
  path.push_back(cycle_start);
  for(int cur=cycle_end; cur!=cycle_start; cur=parent[cur]) {
    path.push_back(cur);
  }
  path.push_back(cycle_start);
}

bool dfs(int src) {
  vis[src] = 1;

  for(auto next:adj[src]) {
    if(!vis[next]) {
      parent[next]=src;

      if(dfs(next))
        return 1;
    }

    else if(vis[next] and parent[src]!=next){
      // We have found a cycle

      // cycle_start = next
      // cycle_end = src
      construct_path(next, src);
      return 1;
    }
  }

  return 0;
}

int main() {
  int n, m;
  cin>>n>>m;

  adj = vector<vector<int>>(n+1);
  parent = vector<int>(n+1);
  vis = vector<bool>(n+1);

  for(int i=0; i<m; i++) {
    int x, y;
    cin>>x>>y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  // Approach: find a cycle using DFS and reconstruct the path
  for(int i=1; i<=n; i++) {
    if(!vis[i] and dfs(i))
      break;
  }

  if(path.empty())
    cout<<"IMPOSSIBLE"<<endl;

  else {
    cout<<path.size()<<endl;
    for(int i=0; i<path.size(); i++)
      cout<<path[i]<<" ";

    cout<<endl;
  }

  return 0;
}
