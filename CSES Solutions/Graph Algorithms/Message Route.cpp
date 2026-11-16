/**
 * Problem Name: Message Route
 * Link: https://cses.fi/problemset/task/1667
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin>>n>>m;

  vector<vector<int>> adj(n+1);
  for(int i=0; i<m; i++) {
    int x, y;
    cin>>x>>y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<int> prev(n+1, -1);
  vector<bool> vis(n+1);
  
  // Use BFS to find distances between nodes

  queue<int> q;

  q.push(1);

  prev[1] = 0;
  vis[1] = 1;

  while(!q.empty()) {
    int cur=q.front();
    q.pop();

    for(auto next:adj[cur]) {
      if(vis[next])
        continue;

      vis[next]=1;
      prev[next]=cur;
      q.push(next);
    }
  }

  if(prev[n]==-1) {
    cout<<"IMPOSSIBLE"<<endl;
  }

  else {
    vector<int> steps;
    int cur=n;

    while(cur!=1) {
      steps.push_back(cur);
      cur=prev[cur];
    }
    steps.push_back(1);

    reverse(steps.begin(), steps.end());

    cout<<steps.size()<<endl;
    for(auto step:steps)
      cout<<step<<" ";

    cout<<endl;
  }

  return 0;
}
