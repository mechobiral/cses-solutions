/**
 * Problem Name: Tree Diameter
 * Link: https://cses.fi/problemset/task/1131
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;

  vector<vector<int>> adj(n+1);

  for(int i=1; i<n; i++) {
    int x, y;
    cin>>x>>y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  // Get farthest node from root (1) using BFS
  vector<bool> vis(n+1);
  queue<pair<int, int>> q;

  q.push({1, 0});
  vis[1]=1;

  int node_start = 1;
  int level = 0;
  while(!q.empty()) {
    auto [cur_node, cur_lvl] = q.front();
    q.pop();

    if(cur_lvl>level) {
      node_start = cur_node;
      level = cur_lvl;
    }

    for(auto next:adj[cur_node]) {
      if(vis[next])
        continue;

      vis[next]=1;
      q.push({next, cur_lvl+1});
    }
  }


  // Get farthest node from node_start, node_end
  // Diameter of tree = distance between node_start and node_end

  vis = vector<bool>(n+1);

  int node_end = node_start;
  level = 0;

  q.push({node_start, 0});
  vis[node_start]=1;

  while(!q.empty()) {
    auto [cur_node, cur_lvl] = q.front();
    q.pop();

    if(cur_lvl>level) {
      node_end = cur_node;
      level = cur_lvl;
    }

    for(auto next:adj[cur_node]) {
      if(vis[next])
        continue;

      vis[next]=1;
      q.push({next, cur_lvl+1});
    }
  }

  cout<<level<<endl;

  return 0;
}
