/**
 * Problem Name: Shortest Routes I
 * Link: https://cses.fi/problemset/task/1671
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;
using LLI = long long int;

int main() {
  int n, m;
  cin>>n>>m;

  // adj[i].first = source
  // adj[i].second.first = cost
  // adj[i].second.second = destination

  vector<vector<pair<int, int>>> adj(n+1);

  for(int i=0; i<m; i++) {
    int a, b, c;
    cin>>a>>b>>c;

    adj[a].push_back({c, b});
  }

  // Approach: dijkstra

  vector<LLI> dist(n+1, 1e18);
  priority_queue<pair<LLI, int>, vector<pair<LLI, int>>, std::greater<pair<LLI, int>>> pq;

  dist[1] = 0;
  pq.push({0, 1});

  while(!pq.empty()) {
    auto [cur_cost, cur_node] = pq.top();
    pq.pop();

    if(cur_cost>dist[cur_node])
      continue;

    for(auto [next_cost, next]:adj[cur_node]) {
      if(dist[cur_node]+next_cost<dist[next]) {
        dist[next] = dist[cur_node]+next_cost;
        pq.push({dist[next], next});
      }
    }
  }

  for(int i=1; i<=n; i++)
    cout<<dist[i]<<" ";

  cout<<endl;

  return 0;
}
