/**
 * Problem name: Graph Girth
 * Link: https://cses.fi/problemset/task/1707
 * Author: Mehedi Rahman Mahi (mechobiral)
 */

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

int main() {
  int n, m;
  cin>>n>>m;

  adj=vector<vector<int>>(n+1);

  for(int i=0; i<m; i++) {
    int x, y;
    cin>>x>>y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int res=INT_MAX;

  // Complexity: O(E*(E+V)), will pass constraints

  for(int i=1; i<=n; i++) {
    vector<int> dist(n+1, -1);
    queue<int> q;

    q.push(i);
    dist[i]=0;

    while(!q.empty()) {
      int cur=q.front();
      q.pop();

      for(auto next:adj[cur]) {
        if(dist[next]==-1) {
          dist[next]=dist[cur]+1;
          q.push(next);
        }

        else if(dist[next]>=dist[cur]) {
          res=min(res, dist[cur]+dist[next]+1);
        }
      }
    }
  }

  cout<<(res==INT_MAX? -1 : res)<<endl;

  return 0;
}