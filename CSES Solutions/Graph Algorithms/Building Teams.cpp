/**
 * Problem Name: Building Teams
 * Link: https://cses.fi/problemset/task/1668
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> color;

bool bfs(int src) {
  queue<int> q;

  // color[i] = -1 : Unset
  // color[i] = 1, color[i] = 2

  color[src] = 1;
  q.push(src);

  while(!q.empty()) {
    int cur=q.front();
    q.pop();

    int next_col = (color[cur]==1)? 2 : 1;

    for(auto next:adj[cur]) {
      if(color[next]==color[cur]) {
        return 0;
      }

      else if(color[next]!=-1)
        continue;

      else {
        q.push(next);
        color[next] = next_col;
      }
    }
  }

  return 1;
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

  // Approach: Bipartite graph
  color = vector<int>(n+1, -1);

  bool possible = 1;

  for(int i=1; i<=n; i++) {
    if(color[i]==-1)
      possible&=bfs(i);
  }

  if(!possible)
    cout<<"IMPOSSIBLE"<<endl;

  else {
    for(int i=1; i<=n; i++)
      cout<<color[i]<<" ";

    cout<<endl;
  }

  return 0;
}
